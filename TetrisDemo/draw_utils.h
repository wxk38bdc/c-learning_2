#pragma once
#include "constants.h"
#include "tetris_block.h"
#include <cstring>


// 加载背景图片并铺满整个窗口
void LoadBackground() {
    IMAGE background;
    // 加载图片，并调整大小为窗口大小
    loadimage(&background, _T("background.jpg"), SCREEN_WIDTH, SCREEN_HEIGHT, true);

    // 绘制图片到窗口，左上角坐标为 (0, 0)
    putimage(0, 0, &background);
}


// 分数管理器
class ScoreManager {
private:
    int score; // 当前分数
    int level; // 当前等级
    int startX; // 分数显示区域的起始X坐标
    int startY; // 分数显示区域的起始Y坐标

public:
    // 构造函数
    ScoreManager() : score(0), level(1), startX(GAME_AREA_WIDTH + MARGIN * 2), startY(MARGIN + PREVIEW_HEIGHT * CELL_SIZE + MARGIN) {}

    // 增加分数
    void AddScore(int linesCleared) {
        // 每消除一行得 100 分
        score += linesCleared * 100;

        // 每 1000 分提升一个等级
        if (score >= level * 1000) {
            level++;
        }
    }

    // 获取当前等级
    int GetLevel() const {
        return level;
    }

    // 获取当前分数
    int GetScore() const {
        return score;
    }

    // 绘制分数和等级
    void Draw() const {
        settextstyle(20, 0, _T("宋体")); // 设置字体
        settextcolor(BLACK); // 设置文字颜色

        // 绘制分数
        TCHAR scoreText[32];
        _stprintf_s(scoreText, _T("分数: %d"), score);
        outtextxy(startX, startY, scoreText);

        // 绘制等级
        TCHAR levelText[32];
        _stprintf_s(levelText, _T("等级: %d"), level);
        outtextxy(startX, startY + 30, levelText);
    }
};


// 管理游戏区域的网格状态
class GameArea {
private:
    COLORREF grid[HEIGHT][WIDTH]; // 游戏区域的网格，存储颜色
    ScoreManager& scoreManager;   // 分数管理器
public:
    // 构造函数
    GameArea(ScoreManager& manager) : scoreManager(manager) {
        // 初始化网格，白色表示空
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                grid[i][j] = WHITE; // 初始化为白色
            }
        }
    }


    // 检测方块是否可以下移
    bool CanMoveDown(const TetrisBlock& block) const {
        for (const auto& point : Block[block.GetType()][block.GetRotation()]) {
            int px = block.GetX() + point.first;
            int py = block.GetY() + point.second + 1; // 下移一格
            if (py >= HEIGHT || grid[py][px] != WHITE) {
                return false; // 无法下移
            }
        }
        return true;
    }

    // 检测方块是否可以左移
    bool CanMoveLeft(const TetrisBlock& block) const {
        for (const auto& point : Block[block.GetType()][block.GetRotation()]) {
            int px = block.GetX() + point.first - 1; // 左移一格
            int py = block.GetY() + point.second;
            if (px < 0 || grid[py][px] != WHITE) {
                return false; // 无法左移
            }
        }
        return true;
    }

    // 检测方块是否可以右移
    bool CanMoveRight(const TetrisBlock& block) const {
        for (const auto& point : Block[block.GetType()][block.GetRotation()]) {
            int px = block.GetX() + point.first + 1; // 右移一格
            int py = block.GetY() + point.second;
            if (px >= WIDTH || grid[py][px] != WHITE) {
                return false; // 无法右移
            }
        }
        return true;
    }

    // 检测方块是否可以旋转
    bool CanRotate(const TetrisBlock& block) const {
        int nextRotation = (block.GetRotation() + 1) % 4; // 下一个旋转状态
        for (const auto& point : Block[block.GetType()][nextRotation]) {
            int px = block.GetX() + point.first;
            int py = block.GetY() + point.second;
            if (px < 0 || px >= WIDTH || py >= HEIGHT || grid[py][px] != WHITE) {
                return false; // 无法旋转
            }
        }
        return true;
    }

    // 固定方块到网格中
    void FixBlock(const TetrisBlock& block) {
        for (const auto& point : Block[block.GetType()][block.GetRotation()]) {
            int px = block.GetX() + point.first;
            int py = block.GetY() + point.second;
            grid[py][px] = block.GetColor(); // 将方块颜色填充到网格中
        }

        // 检查并消除完整行
        int linesCleared = CheckAndClearLines();
        if (linesCleared > 0) {
            scoreManager.AddScore(linesCleared); // 更新分数
        }
    }

    // 检查并消除完整行
    int CheckAndClearLines() {
        int linesCleared = 0;
        for (int i = HEIGHT - 1; i >= 0; --i) {
            bool isFull = true;
            for (int j = 0; j < WIDTH; ++j) {
                if (grid[i][j] == WHITE) {
                    isFull = false;
                    break;
                }
            }

            if (isFull) {
                // 消除该行
                for (int j = 0; j < WIDTH; ++j) {
                    grid[i][j] = WHITE;
                }

                // 将上方的行下移
                for (int k = i; k > 0; --k) {
                    for (int j = 0; j < WIDTH; ++j) {
                        grid[k][j] = grid[k - 1][j];
                    }
                }

                // 最上方的一行清零
                for (int j = 0; j < WIDTH; ++j) {
                    grid[0][j] = WHITE;
                }

                linesCleared++;
                i++; // 继续检查当前行
            }
        }
        return linesCleared;
    }


    // 绘制游戏区域
    void Draw() const {
		
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                setfillcolor(grid[i][j]); // 设置格子颜色
                solidrectangle(MARGIN + j * CELL_SIZE, MARGIN + i * CELL_SIZE,
                    MARGIN + (j + 1) * CELL_SIZE, MARGIN + (i + 1) * CELL_SIZE);
            }
        }
		// 重新绘制网格
        setlinecolor(BLACK);
        for (int i = 0; i <= WIDTH; ++i) {
            line(MARGIN + i * CELL_SIZE, MARGIN, MARGIN + i * CELL_SIZE, MARGIN + HEIGHT * CELL_SIZE);
        }
        for (int j = 0; j <= HEIGHT; ++j) {
            line(MARGIN, MARGIN + j * CELL_SIZE, MARGIN + WIDTH * CELL_SIZE, MARGIN + j * CELL_SIZE);
        }
    }
};



// 预览区域
class PreviewArea {
private:
    int startX; // 预览框的起始X坐标
    int startY; // 预览框的起始Y坐标
    TetrisBlock nextBlock; // 下一个方块

public:
    // 构造函数
    PreviewArea() : startX(GAME_AREA_WIDTH + MARGIN * 2), startY(MARGIN) {}

    // 绘制预览框
    void Draw() {
        // 清理预览区域
        ClearPreviewArea();

        // 绘制下一个方块
        nextBlock.Draw(startX, startY);
    }

    // 更新下一个方块
    void UpdateNextBlock(const TetrisBlock& block) {
        nextBlock = block;
        nextBlock.SetX(PREVIEW_WIDTH / 2);
        nextBlock.SetY(PREVIEW_HEIGHT / 2);
    }

    // 获取下一个方块
    TetrisBlock GetNextBlock() const {
        return nextBlock;
    }

private:
    // 清理预览区域
    void ClearPreviewArea() {
        // 填充白色背景
        setfillcolor(WHITE);
        solidrectangle(startX, startY, startX + PREVIEW_WIDTH * CELL_SIZE, startY + PREVIEW_HEIGHT * CELL_SIZE);

        // 重新绘制网格
        setlinecolor(BLACK);
        for (int i = 0; i <= PREVIEW_WIDTH; ++i) {
            line(startX + i * CELL_SIZE, startY, startX + i * CELL_SIZE, startY + PREVIEW_HEIGHT * CELL_SIZE);
        }
        for (int j = 0; j <= PREVIEW_HEIGHT; ++j) {
            line(startX, startY + j * CELL_SIZE, startX + PREVIEW_WIDTH * CELL_SIZE, startY + j * CELL_SIZE);
        }
    }
};

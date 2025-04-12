#pragma once
#include "board.h"
#include "piece.h"
#include <vector>
#include <iostream>

// 游戏模式基类
class Game {
protected:
    Board board;
    std::vector<std::vector<Piece::Type>> boardState;
    Piece::Type currentPlayer;
    bool gameOver;

public:
    Game() : currentPlayer(Piece::PIECE_WHITE), gameOver(false) {
        boardState.resize(BOARD_SIZE, std::vector<Piece::Type>(BOARD_SIZE, Piece::PIECE_NONE));
        Piece::initImages();
        board.draw();
    }

    virtual ~Game() {}

    // 将屏幕坐标转换为棋盘行列
    bool screenToBoard(int screenX, int screenY, int& row, int& col) const {
        col = static_cast<int>((screenX - BOARD_MARGIN + GRID_SIZE / 2) / GRID_SIZE);
        row = static_cast<int>((screenY - BOARD_MARGIN + GRID_SIZE / 2) / GRID_SIZE);
        return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
    }

    // 处理鼠标点击（虚函数，子类可以重写）
    virtual void handleMouseClick(int x, int y) = 0;

    // 获取当前玩家
    Piece::Type getCurrentPlayer() const {
        return currentPlayer;
    }

    // 切换玩家
    void switchPlayer() {
        currentPlayer = (currentPlayer == Piece::PIECE_WHITE) ?
            Piece::PIECE_BLACK : Piece::PIECE_WHITE;
    }

    // 判断位置是否为空
    bool isEmpty(int row, int col) const {
        return (row >= 0 && row < BOARD_SIZE &&
            col >= 0 && col < BOARD_SIZE &&
            boardState[row][col] == Piece::PIECE_NONE);
    }

    // 检查是否五子连珠
    bool checkWin(int row, int col, Piece::Type player) {
        // 检查四个方向: 水平、垂直、对角线、反对角线
        int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

        for (int i = 0; i < 4; ++i) {
            int count = 1;  // 当前位置已经有一个棋子

            // 正向检查
            for (int step = 1; step < 5; ++step) {
                int r = row + directions[i][0] * step;
                int c = col + directions[i][1] * step;
                if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE ||
                    boardState[r][c] != player) {
                    break;
                }
                count++;
            }

            // 反向检查
            for (int step = 1; step < 5; ++step) {
                int r = row - directions[i][0] * step;
                int c = col - directions[i][1] * step;
                if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE ||
                    boardState[r][c] != player) {
                    break;
                }
                count++;
            }

            if (count >= 5) {
                return true;
            }
        }

        return false;
    }

    // 显示胜利信息
    void showWinMessage(Piece::Type winner) {
        gameOver = true;

        // 设置文字样式
        settextcolor(RGB(255, 0, 0));
        settextstyle(40, 0, _T("Arial"));
        setbkmode(TRANSPARENT);

        // 计算显示位置
        int x = WINDOW_WIDTH / 2 - 100;
        int y = WINDOW_HEIGHT / 2 - 20;

        // 显示胜利信息
        if (winner == Piece::PIECE_WHITE) {
            outtextxy(x, y, _T("白方胜利!"));
        }
        else {
            outtextxy(x, y, _T("黑方胜利!"));
        }

        // 显示重新开始提示
        settextstyle(20, 0, _T("Arial"));
        outtextxy(x + 20, y + 50, _T("按ESC键退出"));
    }

    // 落子（虚函数，子类可以重写）
    virtual void placePiece(int row, int col) {
        if (isEmpty(row, col)) {
            boardState[row][col] = currentPlayer;
            Piece::draw(row, col, currentPlayer);

            std::cout << "落子位置: " << (char)('A' + row) << col + 1
                << " 玩家: " << (currentPlayer == Piece::PIECE_WHITE ? "白" : "黑")
                << std::endl;

            if (checkWin(row, col, currentPlayer)) {
                showWinMessage(currentPlayer);
                return;
            }

            switchPlayer();
        }
    }
};

// 双人对战模式
class TwoPlayerGame : public Game {
public:
    void handleMouseClick(int x, int y) override {
        if (gameOver) return;

        int row, col;
        if (screenToBoard(x, y, row, col)) {
            placePiece(row, col);
        }
    }
};

// 人机对战模式（AI作为黑方）
class AIGame : public Game {
public:
    void handleMouseClick(int x, int y) override {
        // TODO: 实现人机对战逻辑
    }

    void AITurn() {
        // TODO: 实现AI落子逻辑
    }
};

// AI对战AI模式（演示用）
class AIVsAIGame : public Game {
public:
    void handleMouseClick(int x, int y) override {
        // TODO: 实现AI对战AI逻辑
    }

    void AITurn(Piece::Type player) {
        // TODO: 实现AI落子逻辑
    }
};
#include <graphics.h>
#include <iostream>
#include "constants.h"
#include "draw_utils.h"
#include "tetris_block.h"



int main() {
    // 初始化图形窗口
    initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

    // 设置背景颜色为白色
    setbkcolor(WHITE);
    cleardevice();

    // 加载背景图片
    LoadBackground();

    // 初始化分数管理器
    ScoreManager scoreManager;

    // 绘制游戏区域
	GameArea gameArea(scoreManager);
	PreviewArea previewArea;

    // 初始化当前方块和下一个方块
    TetrisBlock currentBlock(rand() % BLOCK_TYPE_COUNT, 0, WIDTH / 2 - 2, 0);
    TetrisBlock nextBlock(rand() % BLOCK_TYPE_COUNT, 0, 0, 0);
    previewArea.UpdateNextBlock(nextBlock);

    // 游戏主循环
    while (true) {
        // 绘制游戏区域
		gameArea.Draw();


        // 绘制当前方块
        currentBlock.Draw(MARGIN, MARGIN);

        // 绘制预览框
        previewArea.Draw();

        // 绘制分数和等级
        scoreManager.Draw();


        // 处理用户输入
        if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) { // 左移
            if (gameArea.CanMoveLeft(currentBlock)) {
                currentBlock.MoveLeft();
            }
        }
        if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000) { // 右移
            if (gameArea.CanMoveRight(currentBlock)) {
                currentBlock.MoveRight();
            }
        }
        if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000) { // 下移
            if (gameArea.CanMoveDown(currentBlock)) {
                currentBlock.MoveDown();
            }
        }
        if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000) { // 旋转
            if (gameArea.CanRotate(currentBlock)) {
                currentBlock.Rotate();
            }
        }

        // 检测方块是否可以下移
        if (gameArea.CanMoveDown(currentBlock)) {
            currentBlock.MoveDown(); // 下移一格
        }
        else {
            gameArea.FixBlock(currentBlock); // 固定方块
            // 将下一个方块移动到游戏区域
            currentBlock = previewArea.GetNextBlock();
            currentBlock = TetrisBlock(currentBlock.GetType(), currentBlock.GetRotation(), WIDTH / 2 - 2, 0,currentBlock.GetColor());

            // 生成新的下一个方块并更新预览框
            nextBlock = TetrisBlock(rand() % 7, 0, 0, 0);
            previewArea.UpdateNextBlock(nextBlock);
        }

        // 根据等级调整下落速度
        int delay = 150 - (scoreManager.GetLevel() - 1) * 20; // 每升一级减少 20 毫秒
        if (delay < 50) delay = 50; // 最小延迟为 50 毫秒
        Sleep(delay);


        // 检测游戏结束
        if (!gameArea.CanMoveDown(currentBlock) && currentBlock.GetY() == 0) {
            outtextxy(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, _T("游戏结束!"));
			Sleep(2000);
			exit(0);
        }
    }

    // 保持窗口打开，直到用户按下任意键
    system("pause");

    // 关闭图形窗口
    closegraph();

    return 0;
}


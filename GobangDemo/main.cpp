#define _CRT_SECURE_NO_WARNINGS 1
#include "board.h"
#include "piece.h"
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include "game.h"
#include <iostream>

// 静态成员初始化
IMAGE Piece::blackPieceImg;
IMAGE Piece::whitePieceImg;
bool Piece::imagesLoaded = false;

int main() {
    Game game;

    // 主游戏循环
    while (true) {
        // 检查按键输入
        if (_kbhit()) {
            if (_getch() == VK_ESCAPE) {
                break; // ESC键退出
            }
        }

        // 处理鼠标消息
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                game.handleMouseClick(msg.x, msg.y);
            }
        }

        Sleep(1); // 降低CPU占用
    }

    return 0;
}

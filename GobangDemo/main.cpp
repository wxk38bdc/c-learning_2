#define _CRT_SECURE_NO_WARNINGS 1
#include "board.h"
#include "piece.h"
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include "game.h"
#include <iostream>
#include <memory>

// 静态成员初始化
IMAGE Piece::blackPieceImg;
IMAGE Piece::whitePieceImg;
bool Piece::imagesLoaded = false;

int main() {
    // 使用智能指针管理游戏对象
    std::unique_ptr<Game> game = std::make_unique<TwoPlayerGame>();

    // 主游戏循环
    while (true) {
        // 如果 ESC 键被按下，退出游戏
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        // 处理鼠标消息
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN) {
                game->handleMouseClick(msg.x, msg.y);
            }
        }

        Sleep(1); // 降低CPU占用
    }

    return 0;
}
////////////////////////////////////////////////////////
// 程序名称：博弈五子棋
// 原作者：陈可佳 <emil09_chen@126.com>
// 修改者：wxk38bdc
// 最后修改：2024/12/9
// 程序功能：实现一个简单的五子棋游戏，玩家与电脑对战。

#include <iostream>
#include <conio.h>
#include "GameLogic.h"
#include <Windows.h>






int main() {
    initgraph(700, 700);  // 初始化绘图环境
    setbkcolor(WHITE);    // 设置背景颜色
    cleardevice();        // 清屏
    setbkmode(TRANSPARENT); // 设置透明文字输出背景

    do {
        chooseMode();  // 用户选择模式
        init();  // 初始化棋盘
        game();  // 游戏开始

        // 清屏后显示是否继续游戏
        cleardevice();
    } while (askToContinue()); // 如果用户输入Y，则继续游戏；点击N则结束游戏

    closegraph();  // 关闭图形窗口
    return 0;
}




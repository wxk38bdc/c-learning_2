////////////////////////////////////////////////////////
// 程序名称：博弈五子棋
// 原作者：陈可佳 <emil09_chen@126.com>
// 修改者：wxk38bdc
// 最后修改：2024/12/9
// 程序功能：实现一个简单的五子棋游戏，玩家与电脑对战。

#include <conio.h>
#include "GameLogic.h"
#include <Windows.h>

// 游戏是否继续的选择函数
bool askToContinue() {
    std::cout << "Do you want to play again? (Y/y for yes,N/n for no): ";  // 在控制台输出提示信息
    char ch;
	std::cin >> ch;

    // 等待用户输入 'Y' 或 'N'
    while (toupper(ch) != 'Y' && toupper(ch) != 'N') {
		std::cout << "Error.Please input 'Y/y' or 'N/n': ";
        std::cin >> ch;
    }

    // 根据用户输入判断是否继续游戏
    return toupper(ch) == 'Y';
}

int main()
{
    initgraph(700, 700);  // 初始化绘图环境
    setbkcolor(WHITE);  // 设置背景颜色
    cleardevice();  // 清屏
    setbkmode(TRANSPARENT);  // 设置透明文字输出背景

    do {
        init();  // 初始化棋盘
        game();  // 游戏开始

        // 清屏后显示是否继续游戏
        cleardevice();

    } while (askToContinue());  // 如果用户输入Y，则继续游戏；点击N则结束游戏

    closegraph();  // 关闭图形窗口
    return 0;
}





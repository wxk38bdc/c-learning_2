#define _CRT_SECURE_NO_WARNINGS 1
#include "gamelogic.h"

int main()
{
	//设置随机数种子
	srand(time(nullptr));

	//初始化图形界面
	initgraph(GRAPH_LENGTH, GRAPH_WIDTH);

	setbkmode(TRANSPARENT);//设置背景透明

	//创建蛇
	Snake snake({ { 14, 11 },
		{ 13, 11 },
		{ 13, 10 },
		{ 12, 10 },
		{ 11, 10 },
		{ 11, 9 }/*,
		{ 11, 8 },
		{ 11, 7 },
		{ 10, 7 },
		{ 9, 7 },
		{ 8, 7 },
		{ 7, 7 }*/
		});

	//绘制背景
	snake.drawBackground();

	//初始化食物
	snake.generateFood();

	//游戏主循环
	while (true)
	{
		//绘制蛇
		snake.drawSnake();

		// 检测键盘输入,并改变蛇的移动方向
		snake.checkKeyBoard();

		//移动蛇
		snake.autoMove();

		//检测是否游戏结束
		snake.checkGameOver();

		//延时
		Sleep(150);
	}

	system("pause");
	closegraph();
	return 0;
}

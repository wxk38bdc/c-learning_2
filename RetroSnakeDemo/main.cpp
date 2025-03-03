#define _CRT_SECURE_NO_WARNINGS 1
#include "gamelogic.h"

int main()
{
	//设置随机数种子
	srand(time(nullptr));

	//初始化图形界面
	initgraph(GRAPH_LENGTH, GRAPH_WIDTH);

	//创建蛇
	Snake snake({ { 14, 11 },
		{ 13, 11 },
		{ 13, 10 },
		{ 12, 10 },
		{ 11, 10 },
		{ 11, 9 },
		{ 11, 8 },
		{ 11, 7 },
		{ 10, 7 },
		{ 9, 7 },
		{ 8, 7 },
		{ 7, 7 }
		});

	//游戏主循环
	while (true)
	{
		//绘制蛇
		snake.draw(GREEN);

		////生成食物
		//snake.generateFood(BLUE);

		// 检测键盘输入,并改变蛇的移动方向
		snake.moveSnake();//与checkKeyBoard()为同一功能，只是checkKeyBoard()更加合理
		//snake.checkKeyBoard();

		//移动蛇
		snake.autoMove();

		//检测是否游戏结束
		snake.checkGameOver();

		//打印蛇身坐标到控制台，用于调试
		snake.printBodyCoordinate();

		//延时，避免游戏过快
		Sleep(100);
	}

	system("pause");
	closegraph();
	return 0;
}

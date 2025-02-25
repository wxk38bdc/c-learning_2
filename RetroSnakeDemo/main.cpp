#define _CRT_SECURE_NO_WARNINGS 1
#include "gamelogic.h"


int main()
{
	//设置随机数种子
	srand(time(nullptr));

	//初始化图形界面
	initgraph(GRAPH_LENGTH, GRAPH_WIDTH);

	//设置背景为白色并刷新
	setbkcolor(WHITE);
	cleardevice();

	//绘制表格
	drawTable(COL, ROW);

	//创建蛇
	Snake snake({{ 14, 11 },
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

    //绘制蛇
	snake.drawSnake(GREEN);

	//生成食物
	snake.generateFood(BLUE);

    system("pause");
    closegraph();
    return 0;
}
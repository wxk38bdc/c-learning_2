#define _CRT_SECURE_NO_WARNINGS 1
#include "gamelogic.h"

//蛇的初始位置
vector<vector<int>> snake = {
	{14, 11},
	{13, 11},
	{13, 10},
	{12, 10},
	{11, 10},
	{11, 9},
	{11, 8},
	{11, 7},
	{10, 7},
	{9, 7},
	{8, 7},
	{7, 7}
};


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

    //绘制蛇
    drawSnake(snake, BLUE);

	//生成食物
	generateFood(snake);

    Sleep(1500);
    //system("pause");
    closegraph();
    return 0;
}
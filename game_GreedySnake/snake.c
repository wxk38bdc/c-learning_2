#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

//设置光标位置
void SetPos(int x, int y)
{
	//获得设备句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//根据句柄设置光标位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}
//欢迎界面
void WelcomeToGame()
{
	//打印欢迎界面
	SetPos(35, 10);
	printf("欢迎来到贪吃蛇游戏");
	SetPos(38, 20);
	system("pause");
	system("cls");
	//功能介绍信息
	SetPos(15, 10);
	printf("游戏规则：用 ↑ . ↓ . ← . → 分别控制蛇的移动,F3为加速,F4为减速\n");
	SetPos(15, 11);
	printf("游戏说明：蛇吃到食物长度加1，蛇撞到墙壁或者自己游戏结束\n");
	SetPos(15, 13);
	system("pause");
	system("cls");
}
//创建地图
void CreateMap()
{
	//打印上边界
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i < 58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//打印下边界
	SetPos(0, 25);
	for (i = 0; i <58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//打印左边界
	for (i = 1; i < 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//打印右边界
	for (i = 0; i < 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
	system("pause");
}
//游戏开始
void GameStart(pSnake ps)
{
	system("mode con cols=100 lines=30");
	system("color 0f");
	system("title 贪吃蛇GreedySnake");
	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
	//打印欢迎界面
	WelcomeToGame();
	//绘制地图
	CreateMap();
	//初始化蛇

	//创建食物
}
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <wchar.h>

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&0x1)?1:0) //按键按下
#define WALL L'㊣' 
enum GAME_STATUS
{
	OK,
	ESC,
	KILL_BY_WALL,
	KILL_BY_SELF
};
enum DIRECTION
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};
//定义蛇身节点
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;
//定义蛇
typedef struct Snake
{
	pSnakeNode pSnake;//维护整条蛇的指针
	pSnakeNode pFood;//维护食物的指针
	int Score;//分数
	int FoodWeight;//一个食物的分数
	int SleepTime;//蛇休眠的时间
	enum GAME_STATUS Status;//游戏状态
	enum DIRECTION Dir;//蛇的方向
}Snake, * pSnake;
void SetPos(int x, int y); //设置光标位置
void GameStart(pSnake ps); //游戏开始
void WelcomeToGame(); //欢迎界面
void CreateMap(); //创建地图
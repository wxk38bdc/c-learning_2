#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <wchar.h>

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&0x1)?1:0) //按键按下
#define WALL L'■' 
#define BODY L'◎'
#define FOOD L'★'
//默认起始坐标
#define POS_X 24
#define POS_Y 5
enum GAME_STATUS
{
	OK=1,//正常运行
	ESC,//按ESC退出
	KILL_BY_WALL,//撞墙
	KILL_BY_SELF//撞自身
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
	long long FoodWeight;//一个食物的分数
	int SleepTime;//蛇休眠的时间
	enum GAME_STATUS Status;//游戏状态
	enum DIRECTION Dir;//蛇的方向
}Snake, * pSnake;
void SetPos(int x, int y); //设置光标位置

void WelcomeToGame(); //欢迎界面
void CreateMap(); //创建地图
void InitSnake(pSnake ps);//初始化蛇
void CreateFood(pSnake ps);//创建食物
void PrintHelpInfo();//打印帮助信息
void Pause();//暂停
void SnakeMove(pSnake ps);//蛇身运动
bool NextIsFood(pSnake ps, pSnakeNode pNext);//判断下一个位置是否为食物
void EatFood(pSnake ps, pSnakeNode pNext);//吃到食物
void NotEatFood(pSnake ps, pSnakeNode pNext);//没吃到食物
bool KillByWall(pSnake ps);//撞墙
bool KillBySelf(pSnake ps);//撞自己
void GameStart(pSnake ps); //游戏开始
void GameRun(pSnake ps);//游戏运行
void GameEnd(pSnake ps);//游戏结束
#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"


void test()
{
	Snake snake = { 0 };

	GameStart(&snake);//游戏开始
	//GameRun();//游戏运行
	//GameEnd();//游戏结束
}
int main()
{
	//修改适配本地中文环境
	setlocale(LC_ALL, "");
	//测试函数
	test();
	return 0;
}
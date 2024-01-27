#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"


void test()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do {
		Snake snake = { 0 };
		GameStart(&snake);//游戏开始
		GameRun(&snake);//游戏运行
		GameEnd(&snake);//游戏结束
		SetPos(20, 15);
		printf("再来一局吗？(1:是 0:否):");
		scanf("%d", &choice);
	} while (choice);

	SetPos(0, 27);
}
int main()
{
	//修改适配本地中文环境
	setlocale(LC_ALL, "");
	//测试函数
	test();

	return 0;
}
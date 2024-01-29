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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	//打印欢迎界面
	SetPos(35, 10);
	printf("欢迎来到贪吃蛇游戏");
	SetPos(38, 20);
	system("pause");
	system("cls");
	//功能介绍信息
	system("color e8");
	SetPos(15, 10);
	printf("游戏规则：用 ↑.↓.←.→ 分别控制蛇的移动,Ctrl为加速,Alt为减速\n");
	SetPos(15, 11);
	printf("游戏说明：蛇吃到食物长度加1，蛇撞到墙壁或者自己游戏结束\n");
	SetPos(15, 13);
	system("pause");
	system("cls");
	system("color 6D");
}
//创建地图
void CreateMap()
{
	//打印上边界
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i < 58; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//打印下边界
	SetPos(0, 26);
	for (i = 0; i < 58; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//打印左边界
	for (i = 1; i < 26; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//打印右边界
	for (i = 0; i < 26; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}
//初始化蛇
void InitSnake(pSnake ps)
{
	//创建5个蛇身节点
	pSnakeNode cur = NULL;
	SetPos(62, 5);
	printf("模式选择");
	SetPos(62, 6);
	printf("1.简单 2.普通 3.困难 4.噩梦:");
	int ch = 0;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		ps->SleepTime = 200;
		ps->FoodWeight = 100;
		break;
	case 2:
		ps->SleepTime = 150;
		ps->FoodWeight = 200;
		break;
	case 3:
		ps->SleepTime = 100;
		ps->FoodWeight = 300;
		break;
	case 4:
		ps->SleepTime = 50;
		ps->FoodWeight = 400;
		break;
	default:
		ps->SleepTime = 200;
		ps->FoodWeight = 100;
		break;
	}
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake():malloc");
		}
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		cur->next = NULL;
		//头插法
		if (ps->pSnake == NULL)
		{
			ps->pSnake = cur;
		}
		else
		{
			cur->next = ps->pSnake;
			ps->pSnake = cur;
		}
		//打印蛇身
		cur = ps->pSnake;
		while (cur)
		{
			SetPos(cur->x, cur->y);
			wprintf(L"%lc", BODY);
			cur = cur->next;
		}
		//其他信息初始化
		ps->Dir = RIGHT;
		//ps->FoodWeight = 100;
		ps->pFood = NULL;
		ps->Status = OK;
		//ps->SleepTime = 200;
		ps->Score = 0;
	}
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);
	pSnakeNode cur = ps->pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood:malloc");
		return;
	}
	else
	{
		pFood->x = x;
		pFood->y = y;
		SetPos(x, y);
		wprintf(L"%lc", FOOD);
		ps->pFood = pFood;
	}
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
	InitSnake(ps);
	//创建食物
	CreateFood(ps);
}
//打印帮助信息
void PrintHelpInfo()
{
	SetPos(62, 14);
	printf("注意事项：");
	SetPos(62, 15);
	printf("1.不能撞墙，不能碰到自己");
	SetPos(62, 16);
	printf("2.用 ↑.↓.←.→ 分别控制蛇移动");
	SetPos(62, 17);
	printf("3.Ctrl为加速, Alt为减速");
	SetPos(62, 18);
	printf("4.按空格键暂停");
	SetPos(62, 19);
	printf("5.按ESC键退出游戏");
	SetPos(62, 21);
	printf("游戏制作 @wxk2227814847");
	SetPos(62, 22);
	printf("版权所有 侵权必究");

}
//游戏运行
void Pause()
{
	while (1)
	{
		Sleep(300);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}
void SnakeMove(pSnake ps)
{
	pSnakeNode pNext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNext == NULL)
	{
		perror("SnakeMove():malloc");
		return;
	}
	pNext->next = NULL;

	switch (ps->Dir)
	{
	case LEFT:
		pNext->x = ps->pSnake->x - 2;
		pNext->y = ps->pSnake->y;
		break;
	case RIGHT:
		pNext->x = ps->pSnake->x + 2;
		pNext->y = ps->pSnake->y;
		break;
	case UP:
		pNext->x = ps->pSnake->x;
		pNext->y = ps->pSnake->y - 1;
		break;
	case DOWN:
		pNext->x = ps->pSnake->x;
		pNext->y = ps->pSnake->y + 1;
		break;
	}
	//下一个坐标处是否为食物
	if (NextIsFood(ps, pNext))
	{
		//是食物就吃掉
		EatFood(ps, pNext);
	}
	else
	{
		//不是就正常走一步
		NotEatFood(ps, pNext);
	}
	//检测撞墙
	KillByWall(ps);
	//检测撞到自己
	KillBySelf(ps);
}
bool KillByWall(pSnake ps)
{
	if (ps->pSnake->x <= 0 || ps->pSnake->x >= 56 || ps->pSnake->y <= 0 || ps->pSnake->y >= 26)
	{
		ps->Status = KILL_BY_WALL;
		return true;
	}
	return false;
}
bool KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->pSnake->next;//从第二个节点开始
	while (cur)
	{
		if (cur->x == ps->pSnake->x && cur->y == ps->pSnake->y)
		{
			ps->Status = KILL_BY_SELF;
			return true;
		}
		cur = cur->next;
	}
	return false;

}
void EatFood(pSnake ps, pSnakeNode pNext)
{
	//是食物就吃掉
	//头插，不释放尾结点
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;

	pSnakeNode cur = ps->pSnake;
	//打印蛇
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->Score += ps->FoodWeight;
	//释放旧食物
	free(ps->pFood);
	//创建新食物
	CreateFood(ps);
}
void NotEatFood(pSnake ps, pSnakeNode pNext)
{
	//不是就正常走一步
	//头插
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;
	//找到尾结点
	pSnakeNode cur = ps->pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//把尾结点打印为空白
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	//给1分
	ps->Score++;
	//删除尾结点
	free(cur->next);
	cur->next = NULL;
}
bool NextIsFood(pSnake ps, pSnakeNode pNext)
{
	return (ps->pFood->x == pNext->x) && (ps->pFood->y == pNext->y);
}
void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	do {
		SetPos(62, 10);
		printf("总得分:%5d\n", ps->Score);
		SetPos(62, 11);
		printf("每个食物得分:%5d\n", ps->FoodWeight);
		//检测按键
		if (KEY_PRESS(VK_UP) && ps->Dir != DOWN)
		{
			ps->Dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->Dir != UP)
		{
			ps->Dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->Dir != RIGHT)
		{
			ps->Dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->Dir != LEFT)
		{
			ps->Dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->Status = ESC;
			break;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();//暂停，恢复
		}
		else if (KEY_PRESS(VK_LCONTROL) || KEY_PRESS(VK_RCONTROL))
		{
			if (ps->SleepTime >= 80)
			{
				ps->SleepTime -= 20;
				ps->FoodWeight += 10;
			}
		}
		else if (KEY_PRESS(VK_LMENU) || KEY_PRESS(VK_RMENU))
		{
			if (ps->FoodWeight >= 50)
			{
				ps->SleepTime += 20;
				ps->FoodWeight -= 10;
			}
		}
		//睡眠
		Sleep(ps->SleepTime);
		//走一步
		SnakeMove(ps);
	} while (ps->Status == OK);

}
//游戏结束
void GameEnd(pSnake ps)
{
	SetPos(30, 12);
	switch (ps->Status)
	{
	case ESC:
		printf("主动退出游戏\n");
		break;
	case KILL_BY_WALL:
		printf("你撞到墙了哦！！\n");
		break;
	case KILL_BY_SELF:
		printf("你咋撞到自己了呢？\n");
		break;
	}
	SetPos(30, 13);
	printf("你的得分是:%d\n", ps->Score - 1);
	//释放贪吃蛇的链表资源
	pSnakeNode cur = ps->pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}
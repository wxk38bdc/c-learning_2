#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

//���ù��λ��
void SetPos(int x, int y)
{
	//����豸���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ݾ�����ù��λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}
//��ӭ����
void WelcomeToGame()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	//��ӡ��ӭ����
	SetPos(35, 10);
	printf("��ӭ����̰������Ϸ");
	SetPos(38, 20);
	system("pause");
	system("cls");
	//���ܽ�����Ϣ
	system("color e8");
	SetPos(15, 10);
	printf("��Ϸ������ ��.��.��.�� �ֱ�����ߵ��ƶ�,CtrlΪ����,AltΪ����\n");
	SetPos(15, 11);
	printf("��Ϸ˵�����߳Ե�ʳ�ﳤ�ȼ�1����ײ��ǽ�ڻ����Լ���Ϸ����\n");
	SetPos(15, 13);
	system("pause");
	system("cls");
	system("color 6D");
}
//������ͼ
void CreateMap()
{
	//��ӡ�ϱ߽�
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i < 58; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//��ӡ�±߽�
	SetPos(0, 26);
	for (i = 0; i < 58; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	//��ӡ��߽�
	for (i = 1; i < 26; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//��ӡ�ұ߽�
	for (i = 0; i < 26; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}
//��ʼ����
void InitSnake(pSnake ps)
{
	//����5������ڵ�
	pSnakeNode cur = NULL;
	SetPos(62, 5);
	printf("ģʽѡ��");
	SetPos(62, 6);
	printf("1.�� 2.��ͨ 3.���� 4.ج��:");
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
		//ͷ�巨
		if (ps->pSnake == NULL)
		{
			ps->pSnake = cur;
		}
		else
		{
			cur->next = ps->pSnake;
			ps->pSnake = cur;
		}
		//��ӡ����
		cur = ps->pSnake;
		while (cur)
		{
			SetPos(cur->x, cur->y);
			wprintf(L"%lc", BODY);
			cur = cur->next;
		}
		//������Ϣ��ʼ��
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
//��Ϸ��ʼ
void GameStart(pSnake ps)
{
	system("mode con cols=100 lines=30");
	system("color 0f");
	system("title ̰����GreedySnake");
	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
	//��ӡ��ӭ����
	WelcomeToGame();
	//���Ƶ�ͼ
	CreateMap();
	//��ʼ����
	InitSnake(ps);
	//����ʳ��
	CreateFood(ps);
}
//��ӡ������Ϣ
void PrintHelpInfo()
{
	SetPos(62, 14);
	printf("ע�����");
	SetPos(62, 15);
	printf("1.����ײǽ�����������Լ�");
	SetPos(62, 16);
	printf("2.�� ��.��.��.�� �ֱ�������ƶ�");
	SetPos(62, 17);
	printf("3.CtrlΪ����, AltΪ����");
	SetPos(62, 18);
	printf("4.���ո����ͣ");
	SetPos(62, 19);
	printf("5.��ESC���˳���Ϸ");
	SetPos(62, 21);
	printf("��Ϸ���� @wxk2227814847");
	SetPos(62, 22);
	printf("��Ȩ���� ��Ȩ�ؾ�");

}
//��Ϸ����
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
	//��һ�����괦�Ƿ�Ϊʳ��
	if (NextIsFood(ps, pNext))
	{
		//��ʳ��ͳԵ�
		EatFood(ps, pNext);
	}
	else
	{
		//���Ǿ�������һ��
		NotEatFood(ps, pNext);
	}
	//���ײǽ
	KillByWall(ps);
	//���ײ���Լ�
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
	pSnakeNode cur = ps->pSnake->next;//�ӵڶ����ڵ㿪ʼ
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
	//��ʳ��ͳԵ�
	//ͷ�壬���ͷ�β���
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;

	pSnakeNode cur = ps->pSnake;
	//��ӡ��
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->Score += ps->FoodWeight;
	//�ͷž�ʳ��
	free(ps->pFood);
	//������ʳ��
	CreateFood(ps);
}
void NotEatFood(pSnake ps, pSnakeNode pNext)
{
	//���Ǿ�������һ��
	//ͷ��
	pNext->next = ps->pSnake;
	ps->pSnake = pNext;
	//�ҵ�β���
	pSnakeNode cur = ps->pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//��β����ӡΪ�հ�
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	//��1��
	ps->Score++;
	//ɾ��β���
	free(cur->next);
	cur->next = NULL;
}
bool NextIsFood(pSnake ps, pSnakeNode pNext)
{
	return (ps->pFood->x == pNext->x) && (ps->pFood->y == pNext->y);
}
void GameRun(pSnake ps)
{
	//��ӡ������Ϣ
	PrintHelpInfo();
	do {
		SetPos(62, 10);
		printf("�ܵ÷�:%5d\n", ps->Score);
		SetPos(62, 11);
		printf("ÿ��ʳ��÷�:%5d\n", ps->FoodWeight);
		//��ⰴ��
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
			Pause();//��ͣ���ָ�
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
		//˯��
		Sleep(ps->SleepTime);
		//��һ��
		SnakeMove(ps);
	} while (ps->Status == OK);

}
//��Ϸ����
void GameEnd(pSnake ps)
{
	SetPos(30, 12);
	switch (ps->Status)
	{
	case ESC:
		printf("�����˳���Ϸ\n");
		break;
	case KILL_BY_WALL:
		printf("��ײ��ǽ��Ŷ����\n");
		break;
	case KILL_BY_SELF:
		printf("��զײ���Լ����أ�\n");
		break;
	}
	SetPos(30, 13);
	printf("��ĵ÷���:%d\n", ps->Score - 1);
	//�ͷ�̰���ߵ�������Դ
	pSnakeNode cur = ps->pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}
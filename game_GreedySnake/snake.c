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
	//��ӡ��ӭ����
	SetPos(35, 10);
	printf("��ӭ����̰������Ϸ");
	SetPos(38, 20);
	system("pause");
	system("cls");
	//���ܽ�����Ϣ
	SetPos(15, 10);
	printf("��Ϸ������ �� . �� . �� . �� �ֱ�����ߵ��ƶ�,F3Ϊ����,F4Ϊ����\n");
	SetPos(15, 11);
	printf("��Ϸ˵�����߳Ե�ʳ�ﳤ�ȼ�1����ײ��ǽ�ڻ����Լ���Ϸ����\n");
	SetPos(15, 13);
	system("pause");
	system("cls");
}
//������ͼ
void CreateMap()
{
	//��ӡ�ϱ߽�
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i < 58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//��ӡ�±߽�
	SetPos(0, 25);
	for (i = 0; i <58; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//��ӡ��߽�
	for (i = 1; i < 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//��ӡ�ұ߽�
	for (i = 0; i < 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
	system("pause");
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

	//����ʳ��
}
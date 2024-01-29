#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

#include <graphics.h>
#include <time.h>
#include <conio.h>

#define MAXSTAR 200	// ��������

struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);

	// ������λ��
	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

// ��
void test2()
{
	srand((unsigned)time(NULL));	// �������
	initgraph(640, 480);			// ������ͼ����

	// ��ʼ����������
	for (int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 640;
	}

	// �����ǿգ���������˳�
	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}

	closegraph();					// �رջ�ͼ����
	return 0;
}
void test()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do {
		Snake snake = { 0 };
		GameStart(&snake);//��Ϸ��ʼ
		GameRun(&snake);//��Ϸ����
		GameEnd(&snake);//��Ϸ����
		SetPos(20, 15);
		printf("����һ����(1:�� 0:��):");
		scanf("%d", &choice);
	} while (choice);

	SetPos(0, 27);
}
int main()
{
	//�޸����䱾�����Ļ���
	setlocale(LC_ALL, "");
	//���Ժ���
	//test();
	test2();

	return 0;
}
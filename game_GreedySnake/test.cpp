#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

#include <graphics.h>
#include <time.h>
#include <conio.h>


void test_rainbow()
{
	// ��������Ļ�ͼ����
	initgraph(1024, 768);

	// ����������(ͨ������������)
	float H = 190;      // ɫ��
	float S = 1;        // ���Ͷ�
	float L = 0.7f;     // ����
	for (int y = 0; y < 768; y++)
	{
		L += 0.0004f;  // �����������ӵ�����
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 1023, y);
	}

	// ���ʺ�(ͨ��ɫ��������)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);      // �����߿�Ϊ 2
	for (int r = 400; r > 344; r--)
	{
		H += 5;
		setlinecolor(HSLtoRGB(H, S, L));
		circle(512, 768, r);  // ����Բ��λ������Ӧ�´���
	}

	// ���м��ӡ���ټ���
	settextcolor(WHITE);
	settextstyle(200, 0, _T("Consolas"));
	static int i = 0;
	if (i == 0)
	{
		outtextxy(200, 120, _T("��ӭ��"));
		i++;
	}
	else
		outtextxy(200, 120, _T("�ټ���"));

	// ��������˳�
	//_getch();
	Sleep(1500);//�ӳ�1.5��
	closegraph();
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
	test_rainbow();
	test();
	test_rainbow();

	return 0;
}



#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"


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
	test();

	return 0;
}
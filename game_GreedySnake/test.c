#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"


void test()
{
	Snake snake = { 0 };

	GameStart(&snake);//��Ϸ��ʼ
	//GameRun();//��Ϸ����
	//GameEnd();//��Ϸ����
}
int main()
{
	//�޸����䱾�����Ļ���
	setlocale(LC_ALL, "");
	//���Ժ���
	test();
	return 0;
}
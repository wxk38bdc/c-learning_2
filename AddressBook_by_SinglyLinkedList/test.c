#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void menu()
{
	printf("******************************\n");
	printf("*******1. �����ϵ��**********\n");
	printf("*******2. ��ʾ��ϵ��**********\n");
	printf("*******3. ɾ����ϵ��**********\n");
	printf("*******4. �޸���ϵ��**********\n");
	printf("*******5. ������ϵ��**********\n");
	printf("*******0. �˳�ͨѶ¼**********\n");
	printf("******************************\n");
}
int main()
{
	int choice = 0;
	contact con;
	contact* pcon = &con;
	InitContact(pcon);
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			AddContact(&pcon);
			break;
		case 2:
			ShowContact(pcon);
			break;
		case 3:
			DelContact(&pcon);
			break;
		case 4:
			ModifyContact(&pcon);
			break;
		case 5:
			FindContact(pcon);
			break;
		case 0:
			printf("�˳�ͨѶ¼�ɹ���\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (choice);
	return 0;
}
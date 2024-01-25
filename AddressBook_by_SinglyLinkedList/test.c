#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void menu()
{
	printf("******************************\n");
	printf("*******1. 添加联系人**********\n");
	printf("*******2. 显示联系人**********\n");
	printf("*******3. 删除联系人**********\n");
	printf("*******4. 修改联系人**********\n");
	printf("*******5. 查找联系人**********\n");
	printf("*******0. 退出通讯录**********\n");
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
		printf("请选择:>");
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
			printf("退出通讯录成功！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (choice);
	return 0;
}
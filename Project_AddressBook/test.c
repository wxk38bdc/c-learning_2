#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//#include"Contact.h"

int main()
{
	Contact con;
	ContactInit(&con);

	int op = -1;
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("�����ϵ��\n");
			ContactAdd(&con);
			break;
		case 2:
			printf("ɾ����ϵ��\n");
			ContactDel(&con);
			break;
		case 3:
			printf("������ϵ��\n");
			ContactFind(&con);
			break;
		case 4:
			printf("�޸���ϵ��\n");
			ContactModify(&con);
			break;
		case 5:
			printf("�鿴ͨѶ¼\n");
			ContactShow(&con);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
		}
	} while (op);

	ContactDestroy(&con);
	return 0;
}
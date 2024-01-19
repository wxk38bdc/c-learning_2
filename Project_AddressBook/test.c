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
		printf("请选择：>");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("添加联系人\n");
			ContactAdd(&con);
			break;
		case 2:
			printf("删除联系人\n");
			ContactDel(&con);
			break;
		case 3:
			printf("查找联系人\n");
			ContactFind(&con);
			break;
		case 4:
			printf("修改联系人\n");
			ContactModify(&con);
			break;
		case 5:
			printf("查看通讯录\n");
			ContactShow(&con);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
		}
	} while (op);

	ContactDestroy(&con);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SListTest01()
{
	SLTNode* node1 = BuyNewNode(1);
	SLTPushBack(&node1, 2);
	SLTPushBack(&node1, 3);
	SLTPushBack(&node1, 4);
	SLTPushBack(&node1, 5);
	SLTPrint(node1);
	SLTPushFront(&node1, 0);
	SLTPrint(node1);
	SLTNode* ToFind = SLTFind(node1, 0);
	if(ToFind)
	{
		printf("Find it!\n");
	}
	else
	{
		printf("Not Find!\n");
	}
	SLTInsertAfter(ToFind, 500);
	SLTPrint(node1);
	SLTInsertBefore(&node1, ToFind, 100);
	SLTPrint(node1);
	SLTErase(&node1, ToFind);
	SLTPrint(node1);
}
int main()
{
	SListTest01();
	return 0;
}
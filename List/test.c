#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"

void test1()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPushFront(&pList, 0);
	SListPrint(pList);
}
int main()
{

	test1();

	return 0;
}
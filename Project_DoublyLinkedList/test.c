#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void test01()
{
	LTNode* plist = NULL;
	LTInit(&plist);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
}
void test02()
{
	LTNode* plist = LTInit2();
	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTNode* toFind = LTFind(plist, 2);
	if (toFind)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
	LTInsertAfter(toFind, 5);
	LTInsertBefore(toFind, 6);
	LTPrint(plist);
	LTRemove(toFind);
	LTPrint(plist);
	LTCheckNode(plist);
}
int main()
{
	//test01();
	test02();
	return 0;
}
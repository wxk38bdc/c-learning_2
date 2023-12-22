#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

void test1()
{
	ListNode* phead = NULL;
	ListInit(&phead);
	ListPushBack(phead, 1);//尾插
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPrint(phead);
	ListPopBack(phead);//尾删
	ListPrint(phead);
	ListPushFront(phead, 0);//头插
	ListPrint(phead);
	ListPopFront(phead);//头删
	ListPrint(phead);
	ListNode* pos = ListFind(phead, 2);//查找
	ListInsert(pos, 10086);//在pos位置插入
	ListPrint(phead);
	ListErase(pos);//删除pos位置
	ListPrint(phead);
	ListDestroy(&phead);//销毁
}
int main()
{
	test1();
	return 0;
}
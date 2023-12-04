#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//测试头尾的插入删除
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 11);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 5, 100);
	SeqListPrint(&s);
	SeqListErase(&s, 5);
	SeqListPrint(&s);
	SeqListDestory(&s);//销毁
}
int main()
{
	TestSeqList1();
	return 0;
}
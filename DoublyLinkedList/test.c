#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

void test1()
{
	ListNode* phead = NULL;
	ListInit(&phead);
	ListPushBack(phead, 1);//β��
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPrint(phead);
	ListPopBack(phead);//βɾ
	ListPrint(phead);
	ListPushFront(phead, 0);//ͷ��
	ListPrint(phead);
	ListPopFront(phead);//ͷɾ
	ListPrint(phead);
	ListNode* pos = ListFind(phead, 2);//����
	ListInsert(pos, 10086);//��posλ�ò���
	ListPrint(phead);
	ListErase(pos);//ɾ��posλ��
	ListPrint(phead);
	ListDestroy(&phead);//����
}
int main()
{
	test1();
	return 0;
}
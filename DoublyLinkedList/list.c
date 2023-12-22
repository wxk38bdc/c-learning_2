#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
//新增节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		// Handle memory allocation failure if necessary
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//初始化链表
void ListInit(ListNode** pphead)
{
	assert(pphead);
	*pphead = BuyListNode(0);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
//打印链表
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	printf("head->");
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("head\n");
}
//尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newnode=BuyListNode(x);

	//tail->next=newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}
//尾删
void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* tailprev = tail->prev;

	//tailprev->next = phead;
	//phead->prev = tailprev;
	//free(tail);
	ListErase(phead->prev);
}
//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);

	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//first->prev = newnode;
	ListInsert(phead->next, x);
}
//头删
void ListPopFront(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);//链表不为空
	//ListNode* first = phead->next;
	//ListNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	ListErase(phead->next);
}
//查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
//在pos位置之前插入x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}
//销毁
void ListDestroy(ListNode** pphead)
{
	assert(pphead);
	ListNode* cur = (*pphead)->next;
	while (cur != *pphead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*pphead);
	*pphead = NULL;
}
//清空但不销毁
void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = phead;
	phead->prev = phead;
}
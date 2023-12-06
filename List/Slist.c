#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"

SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//打印
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//尾插
void SListPushBack(SListNode** pphead, SListDataType x)//传二级指针的原因：会改变头指针的值
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead;//尾指针
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}

}

//尾删
void SListPopBack(SLTNode** pphead)
{
	//1.链表为空
	//2.链表只有一个节点
	//3.链表有多个节点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
//头插
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next= *pphead;
	*pphead = newnode;
}
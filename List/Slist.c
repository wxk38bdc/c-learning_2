#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"

SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("����ڵ�ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//��ӡ
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
//β��
void SListPushBack(SListNode** pphead, SListDataType x)//������ָ���ԭ�򣺻�ı�ͷָ���ֵ
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead;//βָ��
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}

}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	//1.����Ϊ��
	//2.����ֻ��һ���ڵ�
	//3.�����ж���ڵ�
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
//ͷ��
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next= *pphead;
	*pphead = newnode;
}
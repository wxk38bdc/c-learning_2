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
	if (*pphead == NULL)//����Ϊ�գ��½ڵ����ͷ�ڵ�
	{
		*pphead = newNode;
	}
	else//����Ϊ�գ��ҵ����һ���ڵ㣬�����һ���ڵ��nextָ���½ڵ�
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

//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	//1.����Ϊ��
	//2.����ֻ��һ���ڵ� & �����ж���ڵ�
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//����
SListNode* SListFind(SListNode* phead, SListDataType x)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��posλ��֮�����x
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos != NULL);//����
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//ɾ��posλ��֮��Ľڵ�
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
}
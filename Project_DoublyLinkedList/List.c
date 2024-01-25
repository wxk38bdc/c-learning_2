#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//��ӡ
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	printf("head->");
	while(cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//��ʼ����ͨ�����εķ�ʽ��
void LTInit(LTNode** pphead)
{
	*pphead = (LTNode*)malloc(sizeof(LTNode));
	if(*pphead == NULL)
	{
		assert(0);
		return;
	}
	(*pphead)->data = -1;
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
//��ʼ����ͨ������ֵ�ķ�ʽ��
LTNode* LTInit2()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if(phead == NULL)
	{
		assert(0);
		return NULL;
	}
	phead->data = -1;
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//����
void LTDestroy(LTNode** pphead)
{
	LTNode* cur = (*pphead)->next;
	while(cur != *pphead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*pphead);
	*pphead = NULL;
}
//�����½ڵ�
LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if(newnode == NULL)
	{
		assert(0);
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* ptail = phead->prev;
	LTNode* newnode = BuyLTNode(x);
	newnode->next = phead;
	newnode->prev = ptail;
	ptail->next = newnode;
	phead->prev = newnode;
}
//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	LTNode* ptail = phead->prev;
	if(ptail == phead)
	{
		return;
	}
	LTNode* prev = ptail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(ptail);
}
//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyLTNode(x);
	LTNode* next = phead->next;
	newnode->next = next;
	newnode->prev = phead;
	next->prev = newnode;
	phead->next = newnode;

}
//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	LTNode* next = phead->next;
	if(next == phead)
	{
		return;
	}
	LTNode* nextnext = next->next;
	phead->next = nextnext;
	nextnext->prev = phead;
	free(next);

}
//����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while(cur != phead)
	{
		if(cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;

}
//��posλ��֮ǰ����x
void LTInsertBefore(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyLTNode(x);
	newnode->next = pos;
	newnode->prev = prev;
	prev->next = newnode;
	pos->prev = newnode;
}
//��posλ��֮�����x
void LTInsertAfter(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* next = pos->next;
	LTNode* newnode = BuyLTNode(x);
	newnode->next = next;
	newnode->prev = pos;
	next->prev = newnode;
	pos->next = newnode;
}
//ɾ��posλ�õĽڵ�
void LTRemove(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
//��ӡ��Ч�ڵ����
void LTCheckNode(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int count = 0;
	while(cur != phead)
	{
		count++;
		cur = cur->next;
	}
	printf("��Ч�ڵ����Ϊ��%d\n", count);
}
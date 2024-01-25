#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//打印
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
//初始化（通过传参的方式）
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
//初始化（通过返回值的方式）
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
//销毁
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
//创建新节点
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
//尾插
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
//尾删
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
//头插
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
//头删
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
//查找
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
//在pos位置之前插入x
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
//在pos位置之后插入x
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
//删除pos位置的节点
void LTRemove(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
//打印有效节点个数
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
	printf("有效节点个数为：%d\n", count);
}
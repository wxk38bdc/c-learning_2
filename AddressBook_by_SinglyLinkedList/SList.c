#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//打印
void SLTPrint(SLTNode* phead)
{
	//assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//获取新节点
SLTNode* BuyNewNode(SLTDataType x)
{
	SLTNode* pnewnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (pnewnode == NULL)
	{
		assert(0);
		return NULL;
	}
	pnewnode->data = x;
	pnewnode->next = NULL;
	return pnewnode;

}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* pnewnode = BuyNewNode(x);
	if (*pphead == NULL)
	{
		*pphead = pnewnode;
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = pnewnode;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* pnewnode = BuyNewNode(x);
	if (*pphead == NULL)
	{
		*pphead = pnewnode;
	}
	else
	{
		pnewnode->next = *pphead;
		*pphead = pnewnode;
	}
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	//链表为空
	if (*pphead == NULL)
	{
		return;
	}
	//链表只有一个节点
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//链表有多个节点
	else
	{
		while (pcur->next->next != NULL)
		{
			pcur = pcur->next;
		}
		free(pcur->next);
		pcur->next = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	if (pcur == NULL)
	{
		return;
	}
	else
	{
		*pphead = pcur->next;
		free(pcur);
	}
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	/*while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}*/
	//没找到
	return NULL;
}
//在pos位置之后插入x
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* pnewnode = BuyNewNode(x);
	pnewnode->next = pos->next;
	pos->next = pnewnode;

}
//删除pos位置之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	SLTNode* pcur = pos->next;
	//pos之后没有节点
	if (pcur == NULL)
	{
		return;
	}
	//pos之后有节点
	else
	{
		pos->next = pcur->next;
		free(pcur);
	}
}
//删除pos位置的节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if(pos==*pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
	}
}
//在pos位置之前插入x
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);//链表不为空
	SLTNode* pnewnode = BuyNewNode(x);
	//pos为头节点
	if (*pphead == pos)
	{
	/*	pnewnode->next = *pphead;
		*pphead = pnewnode;*/
		SLTPushFront(pphead, x);
	}
	//pos不为头结点
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pnewnode->next = pos;
		pcur->next = pnewnode;
	}
}
//销毁
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		*pphead = pcur->next;
		free(pcur);
		pcur = *pphead;
	}
}
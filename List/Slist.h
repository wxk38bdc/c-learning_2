#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef int SListDataType;

//定义链表节点
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode, SLTNode;

//定义链表
SListNode* BuySListNode(SListDataType x);
//尾插
void SListPushBack(SLTNode** pphead, SListDataType x);
//尾删
void SListPopBack(SLTNode** pphead);
//头插
void SListPushFront(SLTNode** pphead, SListDataType x);
//头删
void SListPopFront(SLTNode* phead);
//打印
void SListPrint(SLTNode* phead);
//
void SListSize(SLTNode* phead);

//查找
SListNode* SListFind(SLTNode* phead, SListDataType x);	

//在pos位置之后插入x
void SListInsertAfter(SLTNode* pos, SListDataType x);

//删除pos位置之后的节点
void SListEraseAfter(SLTNode* pos);
#pragma once
#include <stdio.h>
#include <stdlib.h>
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
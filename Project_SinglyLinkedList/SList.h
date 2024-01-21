#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//打印
void SLTPrint(SLTNode* phead);
//获取新节点
SLTNode* BuyNewNode(SLTDataType x);
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//在pos位置之后插入x
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//删除pos位置之后的节点
void SLTEraseAfter(SLTNode* pos);
//删除pos位置的节点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//在pos位置之前插入x
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//销毁
void SLTDestroy(SLTNode** pphead);


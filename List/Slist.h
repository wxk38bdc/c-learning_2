#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SListDataType;

//��������ڵ�
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode, SLTNode;

//��������
SListNode* BuySListNode(SListDataType x);
//β��
void SListPushBack(SLTNode** pphead, SListDataType x);
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷ��
void SListPushFront(SLTNode** pphead, SListDataType x);
//ͷɾ
void SListPopFront(SLTNode* phead);
//��ӡ
void SListPrint(SLTNode* phead);
//
void SListSize(SLTNode* phead);
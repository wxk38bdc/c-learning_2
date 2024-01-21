#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//��ӡ
void SLTPrint(SLTNode* phead);
//��ȡ�½ڵ�
SLTNode* BuyNewNode(SLTDataType x);
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//��posλ��֮�����x
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//ɾ��posλ��֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos);
//ɾ��posλ�õĽڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);
//��posλ��֮ǰ����x
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//����
void SLTDestroy(SLTNode** pphead);


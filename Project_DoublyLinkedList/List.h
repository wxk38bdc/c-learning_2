#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

void LTPrint(LTNode* phead);//��ӡ
void LTInit(LTNode** pphead);//��ʼ����ͨ�����Σ�
LTNode* LTInit2();//��ʼ����ͨ������ֵ��
void LTDestroy(LTNode** pphead);//����
LTNode* BuyLTNode(LTDataType x);//�����½ڵ�
void LTPushBack(LTNode* phead, LTDataType x);//β��
void LTPopBack(LTNode* phead);//βɾ
void LTPushFront(LTNode* phead, LTDataType x);//ͷ��
void LTPopFront(LTNode* phead);//ͷɾ
LTNode* LTFind(LTNode* phead, LTDataType x);//����
void LTInsertBefore(LTNode* pos, LTDataType x);//��posλ��֮ǰ����x
void LTInsertAfter(LTNode* pos, LTDataType x);//��posλ��֮�����x
void LTRemove(LTNode* pos);//ɾ��posλ�õĽڵ�
void LTCheckNode(LTNode* phead);//��ӡ��Ч�ڵ����

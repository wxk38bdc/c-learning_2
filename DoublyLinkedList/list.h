#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;

typedef struct ListNode 
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* BuyListNode(LTDataType x);
void ListInit(ListNode** pphead);
void ListPrint(ListNode* phead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListDestroy(ListNode** pphead);
void ListClear(ListNode* phead);
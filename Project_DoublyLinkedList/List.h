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

void LTPrint(LTNode* phead);//打印
void LTInit(LTNode** pphead);//初始化（通过传参）
LTNode* LTInit2();//初始化（通过返回值）
void LTDestroy(LTNode** pphead);//销毁
LTNode* BuyLTNode(LTDataType x);//创建新节点
void LTPushBack(LTNode* phead, LTDataType x);//尾插
void LTPopBack(LTNode* phead);//尾删
void LTPushFront(LTNode* phead, LTDataType x);//头插
void LTPopFront(LTNode* phead);//头删
LTNode* LTFind(LTNode* phead, LTDataType x);//查找
void LTInsertBefore(LTNode* pos, LTDataType x);//在pos位置之前插入x
void LTInsertAfter(LTNode* pos, LTDataType x);//在pos位置之后插入x
void LTRemove(LTNode* pos);//删除pos位置的节点
void LTCheckNode(LTNode* phead);//打印有效节点个数

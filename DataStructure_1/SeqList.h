#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//顺序表
////静态顺序表设计（大小固定）
//typedef int SLDataType;
//#define N 10
//
//struct SeqList
//{
//	SLDataType data[N];
//	int size;
//};

//动态顺序表设计（大小可变）
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;//有效元素个数
	int capacity;//容量
}SL, SeqList;

void SeqListInit(SL*s);//初始化
void SeqListDestory(SL* ps);//销毁
void SeqListPrint(SL* ps);//打印
void SeqlistCheckCapacity(SL* ps);//检查容量
void SeqListPushBack(SL* ps, SLDataType x);//尾插
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删
void SeqListInsert(SL* ps, int pos, SLDataType x);//任意位置插入
void SeqListErase(SL* ps, int pos);//任意位置删除


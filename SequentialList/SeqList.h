#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//顺序表的数据类型
typedef int SLDataType;
//动态顺序表
typedef struct SeqList
{
	SLDataType* arr;//动态开辟的数组
	size_t size;//有效元素个数
	size_t capacity;//容量
}SL;

//初始化
void SLInit(SL* ps);
//销毁
void SLDestory(SL* ps);
//判断容量
void SLCheckCapacity(SL* ps);
//打印
void SLPrint(SL* ps);
//尾插
void SLPushBack(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头插
void SLPushFront(SL* ps, SLDataType x);
//头删
void SLPopFront(SL* ps);
//查找
int SLFind(SL* ps, SLDataType x);
//在pos位置插入x
void SLInsert(SL* ps, size_t pos, SLDataType x);
//删除pos位置的元素
void SLErase(SL* ps, size_t pos);

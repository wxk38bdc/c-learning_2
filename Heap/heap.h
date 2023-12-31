#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* php, HPDataType* a, int n);//初始化
void HeapDestory(Heap* php);//销毁
void HeapPush(Heap* php, HPDataType x);//插入
void HeapPop(Heap* php);//删除
HPDataType HeapTop(Heap* php);//取堆顶元素
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

void HeapInit(Heap* php, HPDataType* a, int n);//��ʼ��
void HeapDestory(Heap* php);//����
void HeapPush(Heap* php, HPDataType x);//����
void HeapPop(Heap* php);//ɾ��
HPDataType HeapTop(Heap* php);//ȡ�Ѷ�Ԫ��
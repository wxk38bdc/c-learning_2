#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);

	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//建堆
	int i = (n - 2) / 2;
	

}
void HeapDestory(Heap* php);//销毁
void HeapPush(Heap* php, HPDataType x);//插入
void HeapPop(Heap* php);//删除
HPDataType HeapTop(Heap* php);//取堆顶元素
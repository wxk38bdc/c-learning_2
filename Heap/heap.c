#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);

	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//����
	int i = (n - 2) / 2;
	

}
void HeapDestory(Heap* php);//����
void HeapPush(Heap* php, HPDataType x);//����
void HeapPop(Heap* php);//ɾ��
HPDataType HeapTop(Heap* php);//ȡ�Ѷ�Ԫ��
#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0,1,5,6,7,9,10,2};
	int sz_a = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz_a);//��������
	//ShellSort(a, sz_a);//ϣ������
	//SelectSort(a, sz_a);//ѡ������
	//HeapSort(a, sz_a);//������
	//BubbleSort(a, sz_a);//ð������
	QuickSort(a, 0, sz_a - 1);//��������
	PrintArray(a, sz_a);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
#define NUM 20
int main()
{
	//���������
	srand((unsigned int)time(NULL));
	int a[NUM] = { 0 };
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		a[i] = rand() % 100;
	}
	PrintArray(a, NUM);
	int sz_a = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz_a);//��������
	//ShellSort(a, sz_a);//ϣ������
	//SelectSort(a, sz_a);//ѡ������
	//HeapSort(a, sz_a);//������
	//BubbleSort(a, sz_a);//ð������
	//QuickSort(a, 0, sz_a - 1);//��������
	//QuickSortNonR(a, 0, sz_a - 1);//�ǵݹ��������
	//MergeSort(a, sz_a);//�鲢����
	MergeSortNonR(a, sz_a);//�鲢����ǵݹ�
	PrintArray(a, sz_a);
	return 0;
}
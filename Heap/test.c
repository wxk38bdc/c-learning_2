#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void HeapSortDown(int* a, int n)//�Ӵ�С���򣬽�С��
{
	//����
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
int main()
{
	int a[] = { 255,18,26,577,59,236,10,0};
	HeapSortDown(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	//Heap hp;
	//HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	////��ӡ�����������
	//for (int i = 0; i < hp._size; i++)
	//{
	//	printf("%d ", hp._a[i]);
	//}
	return 0;
}
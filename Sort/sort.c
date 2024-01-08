#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"
//��ӡ����
void PrintArray(int* a, int n)
{
	assert(a);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//����
void Swap(int* a, int* b)
{
	assert(a && b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
void InsertSort(int* a, int n)
{
	assert(a);
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int* a, int n)
{
	//gap>1 �൱��Ԥ�������һ��gap=1���൱�ڲ�������
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int i = 0;
		for (i = gap; i < n; i++)
		{
			int end = i - gap;
			int tmp = a[i];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

//ѡ������
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		int i = 0;
		for (i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

//������
void AdjustDown(int* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	assert(a);
	//����
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
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

//ð������
void BubbleSort(int* a, int n)
{
	assert(a);
	int end = n - 1;
	while (end > 0)
	{
		int exchange = 0;
		int i = 0;
		for (i = 0; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
		end--;
	}
}

//��������
//[begin,end]������
int GetMidIndex(int* a, int begin, int end)
{
	//����ȡ�з�
	int mid = begin + (end - begin) / 2;
	//int mid = (begin + end) / 2;//��ֹ���
	if (a[mid] > a[begin])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else //a[mid] < a[begin]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}
int PartSort1(int* a, int begin, int end)
{
	//������������ָ�뷨
	//�Ż������ѡȡ��׼ֵ
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//end��С
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;//������

}
int PartSort2(int* a, int begin, int end)
{
	//���������ڿӷ�
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);
	int key = a[end];
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		//����ҵ���ģ���ӵ�λ�ã�beginָ���
		a[end] = a[begin];
		//end��С
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		//�ұ��ҵ�С�ģ���ӵ�λ�ã�endָ���
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;//������
}
int PartSort3(int* a, int begin, int end)
{
	//ǰ��ָ�뷨
	int MidIndex = GetMidIndex(a, begin, end);
	Swap(&a[MidIndex], &a[end]);
	int key = a[end];
	int cur = begin;
	int prev = cur - 1;
	while (cur < end)
	{
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[++prev], &a[end]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	if(right-left+1<10)
	{
		//������С���ò�������
		InsertSort(a+left,right-left+1);
		return;
	}
	else
	{
		//���������ÿ�������
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
//�ǵݹ��������
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);
	stack st;
	stackInit(&st);
	//�����ң�������
	stackPush(&st, right);
	stackPush(&st, left);
	while (!stackEmpty(&st))
	{
		//�ȳ����ٳ���
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//[begin,end]������
		int div = PartSort1(a, begin, end);
		//[begin,div-1]
		if (div - 1 > begin)
		{
			stackPush(&st, div - 1);
			stackPush(&st, begin);
		}
		//[div+1,end]
		if (div + 1 < end)
		{
			stackPush(&st, end);
			stackPush(&st, div + 1);
		}
	}
}

//�鲢����
//�ݹ�ʵ��
void Merge(int* a, int left, int mid, int right, int* tmp) 
{
	int i = left;
	int j = mid + 1;
	int k = left;

	// �ϲ�������������
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
		}
	}

	// ����ʣ���Ԫ��
	while (i <= mid) {
		tmp[k++] = a[i++];
	}
	while (j <= right) {
		tmp[k++] = a[j++];
	}

	// ���ϲ�������鸴�ƻ�ԭ����
	for (i = left; i <= right; i++) {
		a[i] = tmp[i];
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left < right)
	{
		//[left,mid][mid+1,right]
		int mid = left + (right - left) / 2; // �������
		_MergeSort(a, left, mid, tmp); // ������벿��
		_MergeSort(a, mid + 1, right, tmp); // �����Ұ벿��
		//Merge(a, left, mid, right, tmp); // �ϲ�������������
		int i = left;
		int j = mid + 1;
		int k = left;

		// �ϲ�������������
		while (i <= mid && j <= right) {
			if (a[i] <= a[j]) {
				tmp[k++] = a[i++];
			}
			else {
				tmp[k++] = a[j++];
			}
		}

		// ����ʣ���Ԫ��
		while (i <= mid) {
			tmp[k++] = a[i++];
		}
		while (j <= right) {
			tmp[k++] = a[j++];
		}

		// ���ϲ�������鸴�ƻ�ԭ����
		for (i = left; i <= right; i++) {
			a[i] = tmp[i];
		}
	}
}

void MergeSort(int* a, int n) {
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//�ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		printf("malloc fail\n");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int left = i;
			int mid = i + gap - 1;
			int right = i + 2 * gap - 1;
			if (mid >= n - 1)
			{
				mid = n - 1;
			}
			if (right >= n)
			{
				right = n - 1;
			}
			Merge(a, left, mid, right, tmp);
		}
		gap *= 2;
	}
	free(tmp);
}

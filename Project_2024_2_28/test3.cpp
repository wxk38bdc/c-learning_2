#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"
#include<ctime>

void testHeap1()
{
	//利用堆找到最小的k个数
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&heap, arr[i]);
	}
	HeapPrint(&heap);
	HeapPop(&heap);
	HeapPrint(&heap);
	HeapPop(&heap);
	HeapPrint(&heap);
	HeapPop(&heap);
	HeapPrint(&heap);
	HeapPop(&heap);

	HeapPush(&heap, 10);
	HeapPrint(&heap);
	HeapPush(&heap, 11);
	HeapPrint(&heap);
}
void testHeap2()
{
	//利用堆排序
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&heap, arr[i]);
	}
	HeapPrint(&heap);
	while (HeapEmpty(&heap) != true)
	{
		cout << HeapTop(&heap) << " ";
		HeapPop(&heap);
	}
	cout << endl;
	HeapDestroy(&heap);
}
void testHeap3()
{
	//调用Heapsort
	int arr[100] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand()%1000;
	}
	HeapSort(arr, 100);
	for (int i = 0; i < 100; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//创造一个100个随机数的文件
void CreateNodes()
{
	FILE* f = fopen("input.txt", "w");
	srand((unsigned int)time(NULL));
	if (f == NULL)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		fprintf(f, "%d\n", rand() % 100);
	}
	fclose(f);
}
void AdjustDown_Arr(int* arr, int size, int index) {
	int smallest = index;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;

	// 寻找子节点中最小的值
	while (leftChild < size || rightChild < size) {
		if (leftChild < size && arr[leftChild] < arr[smallest]) {
			smallest = leftChild;
		}
		if (rightChild < size && arr[rightChild] < arr[smallest]) {
			smallest = rightChild;
		}

		// 如果当前节点就是最小值，结束调整
		if (smallest == index) {
			break;
		}

		// 否则，交换当前节点和最小值，并继续向下调整
		swap(arr[index], arr[smallest]);
		index = smallest;
		leftChild = 2 * index + 1;
		rightChild = 2 * index + 2;
	}
}

void topK() {
	int k;
	cout << "请输入k的值:" << endl;
	cin >> k;
	FILE* f = fopen("input.txt", "r");
	if (f == NULL) {
		cout << "文件打开失败" << endl;
		return;
	}

	int* arr = new int[k]; // 使用new动态分配内存
	for (int i = 0; i < k; i++) {
		fscanf(f, "%d", &arr[i]);
	}
	// 建立一个小堆
	for (int i = (k - 2) / 2; i >= 0; i--) { // 修正建堆的起始位置
		AdjustDown_Arr(arr, k, i);
	}

	int num;
	while (fscanf(f, "%d", &num) != EOF) {
		if (num > arr[0]) {
			arr[0] = num;
			AdjustDown_Array(arr, k, 0);
		}
	}
	fclose(f);
	cout << "最大的" << k << "个数为：" << endl;
	for (int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr; // 使用delete释放动态分配的内存
}
//void topK()
//{
//	int k;
//	cout << "请输入k的值:" << endl;
//	cin >> k;
//	FILE* f = fopen("input.txt", "r");
//	if (f == NULL)
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//	int* arr = (int*)malloc(sizeof(int)*k);
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(f, "%d", &arr[i]);
//	}
//	//建立一个小堆
//	for(int i = (k - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown_Array(arr, k, i);
//	}
//	int num;
//	while (fscanf(f, "%d", &num) != EOF)
//	{
//		if (num > arr[0])
//		{
//			arr[0] = num;
//			AdjustDown_Array(arr, k, 0);
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	free(arr);	
//	fclose(f);
//}
void testHeap4()
{
	//利用堆找到最小的k个数
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&heap, arr[i]);
	}
}
void testHeap5()
{
	//利用堆排序
	Heap heap;
	HeapInit(&heap);
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	for (int i = 0; i < 10; i++)
	{
		HeapPush(&heap, arr[i]);
	}
	while (HeapEmpty(&heap) != true)
	{
		cout << HeapTop(&heap) << " ";
		HeapPop(&heap);
	}
	cout << endl;
	HeapDestroy(&heap);
}
void testHeap6()
{
	//调用Heapsort
	int arr[100] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1000;
	}
	HeapSort(arr, 100);
	for (int i = 0; i < 100; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	//testHeap1();
	//testHeap2();
	//testHeap3();
	//CreateNodes();
	topK();
	return 0;
}
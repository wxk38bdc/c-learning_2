/*
题目描述
请判断输入的整数序列是否为堆。

如果为最大堆，请输出“max ”以及整理后的最小堆，整数序列数字之间有空格，最后无空格。

如果为最小堆，请输出“min ” 以及整理后的最大堆，整数序列数字之间有空格，最后无空格。

如果不为堆，请输出整理后的最大堆，整数序列数字之间有空格，最后无空格。

如果既是最大堆也是最小堆，请只输出“max min ”

Input Format

先输入整数序列个数n 0<n<1000

然后输入n个整数序列，整数取值范围【-100000，100000】

Output Format
最大堆或最小堆序列

Example
Input
10
-8 8 -9 10 -2 1 -6 -9 7 2

Output
10 8 1 7 2 -9 -6 -9 -8 -2

Input
10
10 8 1 7 2 -9 -6 -9 -8 -2

Output
max -9 -9 -6 -8 -2 1 10 7 8 2

Input
 10
-9 -9 -6 -8 -2 1 10 7 8 2

Output
min 10 8 1 7 2 -9 -6 -9 -8 -2

Input
 3
1 1 1

Output
max min

注意：序列最后无空格,max和min后面均有空格。

如案例，定义以下实现约束：两个相等子节点情况下，整理过程中，父节点下沉时，选择右沉。

10

10 8 1 7 2 -9 -6 -9 -8 -2
 两个相等子节点情况下，整理过程中，父节点下沉时，选择右沉。




样例输入输出
样例1
输入:
10
-9 -9 -6 -8 -2 1 10 7 8 2
输出:
min 10 8 1 7 2 -9 -6 -9 -8 -2
样例2
输入:
3
1 1 1
输出:
max min
样例3
输入:
10
10 8 1 7 2 -9 -6 -9 -8 -2
输出:
max -9 -9 -6 -8 -2 1 10 7 8 2
样例4
输入:
10
-8 8 -9 10 -2 1 -6 -9 7 2
输出:
10 8 1 7 2 -9 -6 -9 -8 -2

*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isMaxHeap(vector<int>& arr)
{
	for (int i = arr.size() - 1; i > 0; i--)
	{
		if (arr[i] > arr[(i - 1) / 2])return false;
	}
	return true;
}
bool isMinHeap(vector<int>& arr)
{
	for (int i = arr.size() - 1; i > 0; i--)
	{
		if (arr[i] < arr[(i - 1) / 2])return false;
	}
	return true;
}
void AdjustDownMaxHeap(vector<int>& a, int root)//向下调整
{
	int n = a.size();
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] >= a[child])
			child++;
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void createMaxHeap(vector<int>& arr) {
	int n = arr.size();
	// 从第一个非叶子节点开始向下调整
	for (int i = n / 2 - 1; i >= 0; i--) {
		AdjustDownMaxHeap(arr, i);
	}
}
void AdjustDownMinHeap(vector<int>& a, int root)//向下调整
{
	int n = a.size();
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] <= a[child])
			child++;
		if (a[child] < a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void createMinHeap(vector<int>& arr) {
	int n = arr.size();
	// 从第一个非叶子节点开始向下调整
	for (int i = n / 2 - 1; i >= 0; i--) {
		AdjustDownMinHeap(arr, i);
	}
}
void printArr(vector<int>& arr)
{
	for (auto num : arr)cout << num << " ";
}
int main() {
	int n = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	if (isMaxHeap(arr) && isMinHeap(arr))
	{
		cout << "max min ";
	}
	else if (isMaxHeap(arr))
	{
		cout << "max ";
		createMinHeap(arr);
		printArr(arr);
	}
	else if (isMinHeap(arr))
	{
		cout << "min ";
		createMaxHeap(arr);
		printArr(arr);
	}
	else//不是堆
	{
		createMaxHeap(arr);
		printArr(arr);
	}
	return 0;
}

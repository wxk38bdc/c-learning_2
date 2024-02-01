#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<chrono>
#include <ctime>
#include <Windows.h>
using namespace std;

//class Date
//{
//private:
//	int year;
//	int month;
//	int day;
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:year(year), month(month), day(day)
//	{}//构造函数,初始化列表
//	void Print()
//	{
//		cout << year << "-" << month << "-" << day << endl;
//	}
//};
//int main()
//{
//	cout<<"hello world"<<endl;
//	Date d1;
//	d1.Print();
//	return 0;
//}

void MergeSort(int* arr, int left, int right, int* temp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(arr, left, mid, temp);
	MergeSort(arr, mid + 1, right, temp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			temp[index++] = arr[begin1++];
		}
		else
		{
			temp[index++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = arr[begin2++];
	}
	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <iomanip>
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

//void MergeSort(int* arr, int left, int right, int* temp)
//{
//	if (left >= right)
//		return;
//	int mid = (left + right) / 2;
//	MergeSort(arr, left, mid, temp);
//	MergeSort(arr, mid + 1, right, temp);
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (arr[begin1] < arr[begin2])
//		{
//			temp[index++] = arr[begin1++];
//		}
//		else
//		{
//			temp[index++] = arr[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		temp[index++] = arr[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		temp[index++] = arr[begin2++];
//	}
//	for (int i = left; i <= right; i++)
//	{
//		arr[i] = temp[i];
//	}
//}

//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left;
//	int end = right;
//	int key = arr[left];
//	while (begin < end)
//	{
//		while (begin < end && arr[end] >= key)
//		{
//			end--;
//		}
//		arr[begin] = arr[end];
//		while (begin < end && arr[begin] <= key)
//		{
//			begin++;
//		}
//		arr[end] = arr[begin];
//	}
//	arr[begin] = key;
//	QuickSort(arr, left, begin - 1);
//	QuickSort(arr, begin + 1, right);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//    int n, q, l, r, i, j;
//    scanf("%d %d", &n, &q);
//    int *arr= (int *)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    while (q--)
//    {
//        scanf("%d %d", &l, &r);
//        l--;
//        r--;
//        int flag = 0;
//        for (i = l; i <= r; i++)
//        {
//            for (j = l + 1; j <= r; j++)
//            {
//                if (abs(arr[i] - arr[j]) <= 365)
//                {
//                    flag = 1;
//                }
//            }
//        }
//        if (flag)
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

//int main()
//{
//	double a, b;
//	cin >> a >> b;
//	cout << fixed << setprecision(3) << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	//声明并初始化一个空字符串
//	string str1;
//	//使用字符串字面值初始化一个字符串
//	string str2= "hello,world!";
//	//使用另一个字符串初始化一个字符串
//	string str3(str2);//string str3 = str2;
//	//使用部分字符串初始化一个字符串
//	string str4(str2, 0, 5);
//	//使用n个字符初始化一个字符串
//	string str5(10, 'a');
//	//使用字符数组初始化一个字符串
//	char ch[] = "hello,wor";
//	string str6(ch);
//	//输出字符串
//	cout << str1 << endl;//空字符串
//	cout << str2 << endl;//hello,world!
//	cout << str3 << endl;//hello,world!
//	cout << str4 << endl;//hello
//	cout << str5 << endl;//aaaaaaaaaa
//	cout << str6 << endl;//hello,wor
//	return 0;
//}
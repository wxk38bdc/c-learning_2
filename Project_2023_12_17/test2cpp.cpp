#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include<cerrno>
using namespace std;
//int main()
//{
//	double x = 1, y = 1, z = x + 1 / 4 + y / 2;
//	cout<<"z="<<z<<endl;
//	return 0;
//}
//int main()
//{
//	int a = 2, b = 2, c = 2, m = 2, n = 2, d = 2;
//	a = (m == a > b) && (n = c < d);
//	cout << "a=" << a << endl;
//	cout << "m=" << m << endl;
//	cout << "n=" << n << endl;
//	return 0;
//}
//int main()
//{
//	int a[30] = { 0 };
//	int i = 0;
//	while(cin>>a[i])
//	{
//		if (a[i] == -1)
//		{
//			break;
//		}
//		i++;
//	}
//	int j = 0;
//	double avg = 0.0;
//	for (j = 0; j < i; j++)
//	{
//		avg += a[j];
//	}
//	avg = avg * 1.0 / i;
//	cout<<"avg="<<avg<<endl;
//
//	begin:
//	for (int index = 0; index < 5; index++)
//	{
//		if (i != 0)
//		{
//			cout<<a[i-1]<<" ";
//			i--;
//		}
//		else
//		{
//			break;
//		}
//	}
//	cout << endl;
//	if (i != 0)
//	{
//		goto begin;
//	}
//	return 0;
//}
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//};
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	cout<<"a="<<a<<" ,"<<"b="<<b<<endl;
//	return 0;
//}
//int main()
//{
//	int rats = 101;
//	int *pt = &rats;
//	int &rodents = *pt;
//	int bunnies = 50;
//	pt = &bunnies;
//	bunnies = 60;
//	cout<<"bunnies = "<<bunnies<<endl;
//	cout << "*pt = " << *pt << endl;
//	cout << "rodents = " << rodents << endl;
//	cout << "rats = " << rats << endl;
//	return 0;
//}
//int main()
//{
//	int a = 1, b = 2;
//	if (a > b) 
//		cout << "a>b" << endl; cout << "hello" << endl;
//	
//		cout<<"112233"<<endl;
//	return 0;
//}
//int main()
//{
//	int x = 2, y = 1;
//	int z;
//	z = (x < y);
//	cout << z << endl;
//	z = (x > y);
//	cout << z << endl;
//	return 0;
//}
//int main()
//{
//	//int x = 3, y = 5;
//	//x *= y + 2;
//	//x /= y + 2;
//	//cout << x <<" " << y;
//	//return 0;
//	//cout << 0.0000000123 << endl;//1.23e-5
//	//int a = 3;
//	//double b= 3.14;
//	//b = a;
//	//cout<< (double)b << endl;//3
//	//char ch = 'A';
//	//cout << ch << endl;//A
//	//cout << ch + 1 << endl;
//	//cout<<(char)(ch + 1) << endl;//B
//	return 0;
//}
//int main()
//{
//	bool f = true;
//	cout << f << endl;//1
//	bool g = false;
//	cout << g << endl;//1
//	return 0;
//}
//int main()
//{
//	int b = 12;
//	b += b -= b * b;
//	cout << b << endl;//-264
//	return 0;
//}
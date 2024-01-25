#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//void func1(int a = 10, int b = 20)
//{
//	cout << "a=" << a << ",b=" << b << endl;
//}
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void Swap(double& a, double& b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//void Swap(char& a, char& b)
//{
//	char tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	char e = '0', f = '1';
//	cout<<"交换前：" << "a=" << a << ",b=" << b << endl;
//	Swap(a, b);
//	cout<<"交换后：" << "a=" << a << ",b=" << b << endl;
//	cout<<"交换前：" << "c=" << c << ",d=" << d << endl;
//	Swap(c, d);
//	cout<<"交换后：" << "c=" << c << ",d=" << d << endl;
//	cout<<"交换前：" << "e=" << e << ",f=" << f << endl;
//	Swap(e, f);
//	cout<<"交换后：" << "e=" << e << ",f=" << f << endl;
//	return 0;
//}

//int& Count1()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//int main()
//{
//	int& a = Count1();
//	cout<<"a=" << a << endl;
//	a++;
//	cout << "a=" << a << endl;
//	int b = Count1();
//	cout<<"b=" << b << endl;
//	return 0;
//}

//inline void Swap(int& a, int& b)
//{
//	int tmp = b;
//	b = a;
//	a = tmp;
//}
//int main()
//{
//	int a = 0, b = 2;
//	cout << "交换前：a=" << a << ",b=" << b << endl;
//	Swap(a, b);
//	cout << "交换后：a=" << a << ",b=" << b << endl;
//	return 0;
//}

int main()
{
	//int a = 0;
	//auto b = a;
	//auto pb = &b;
	//cout << typeid(pb).name()<< endl;
	int arr[] = { 1,2,3,4,5 };
	for (auto& e : arr)
	{
		e *= 2;
	}
	for (auto& e : arr)
	{
		cout << e << " ";
	}


}
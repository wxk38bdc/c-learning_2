#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<chrono>
#include <ctime>
#include <Windows.h>
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

//int main()
//{
//	//int a = 0;
//	//auto b = a;
//	//auto pb = &b;
//	//cout << typeid(pb).name()<< endl;
//	int arr[] = { 1,2,3,4,5 };
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto& e : arr)
//	{
//		cout << e << " ";
//	}
//}

////定义一个栈的类
//class Stack
//{
//public:
//	void Init(size_t capacity = 10)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(int x)
//	{
//		if (_size == _capacity)
//		{
//			_capacity *= 2;
//			_a = (int*)realloc(_a, sizeof(int)*_capacity);
//		}
//		_a[_size++] = x;
//	}
//	void Pop()
//	{
//		if (_size > 0)
//		{
//			_size--;
//		}
//	}
//	int Top()
//	{
//		return _a[_size - 1];
//	}
//	bool Empty()
//	{
//		return _size == 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	Stack st;
//	return 0;
//}

//class Date {
//public:
//    Date() {
//        AutoInit();
//    }
//
//    Date(int year, int month, int day, int hour = 0, int minute = 0, int second = 0) {
//        Init(year, month, day, hour, minute, second);
//    }
//
//    void Init(int year, int month, int day, int hour, int minute, int second) {
//        _year = year;
//        _month = month;
//        _day = day;
//        _hour = hour;
//        _minute = minute;
//        _second = second;
//    }
//    void AutoInit() // 获取当前时间
//    {
//		auto now = chrono::system_clock::now(); // 获取当前时间点
//		time_t now_c = chrono::system_clock::to_time_t(now); // 转换为time_t
//		struct tm* parts = localtime(&now_c); // 转换为tm结构体
//
//		_year = 1900 + parts->tm_year;
//		_month = 1 + parts->tm_mon;
//		_day = parts->tm_mday;
//		_hour = parts->tm_hour;
//		_minute = parts->tm_min;
//		_second = parts->tm_sec;
//	}
//    void Display() {
//        cout << _year << "-" << _month << "-" << _day << " ";
//        printf("%02d:%02d:%02d\n", _hour, _minute, _second);
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//int main() {
//    system("color 07");
//    system("title 时间显示");
//    system("mode con cols=20 lines=5");
//    while (1)
//    {
//        printf("当前时间：\n");
//        Date d;
//        d.Display();
//        printf("按空格键退出\n");
//        if (GetAsyncKeyState(VK_SPACE))
//        {
//            printf("退出成功\n");
//            return 0;
//        }
//        Sleep(10);
//        system("cls");
//    }
//    return 0;
//}

class Date {
public:
	int _year;
	int _month;
	int _day;

	Date() {
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	void Display() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
};
bool operator==(const Date& d1, const Date& d2)//重载==
{
	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
}
bool operator>(const Date& d1, const Date& d2)//重载>
{
	if (d1._year > d2._year)
	{
		return true;
	}
	else if (d1._year == d2._year)
	{
		if (d1._month > d2._month)
		{
			return true;
		}
		else if (d1._month == d2._month)
		{
			if (d1._day > d2._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool operator >=(const Date& d1, const Date& d2)//重载>=
{
	return d1 > d2 || d1 == d2;
}
void Judge(const Date& d1, const Date& d2)
{
	if (d1 == d2)
	{
		cout << "d1 = d2" << endl;
	}
	else if (d1 > d2)
	{
		cout << "d1 > d2" << endl;
	}
	else
	{
		cout << "d1 < d2" << endl;
	}
}
int main()
{
	Date d1(2020, 1, 1);
	Date d2(2020, 1, 2);
	Judge(d1, d2);
	return 0;
}
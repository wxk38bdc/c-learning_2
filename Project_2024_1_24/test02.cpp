#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<chrono>
#include <ctime>
#include <Windows.h>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:year(year), month(month), day(day)
	{}//构造函数,初始化列表
	void Print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
};
int main()
{
	cout<<"hello world"<<endl;
	Date d1;
	d1.Print();
	return 0;
}
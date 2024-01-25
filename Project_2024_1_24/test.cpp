#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void func(int a = 10, int b = 20)
{
	cout << "a=" << a << ",b=" << b << endl;
}
int main()
{
	cout<<"Hello world!"<<endl;
	func();
	func(0);
	func(0,0);
	return 0;
}
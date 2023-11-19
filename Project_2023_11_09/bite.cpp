#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//namespace N1
//{
//	int a = 10;
//	int add(int left, int right)
//	{
//		return left + right;
//	}
//}
//using namespace N1;
//int main()
//{
//	printf("%d", a);
//	return 0;
//}
//using std::cout;
//using std::endl;
//using std::cin;
//int main()
//{
//	cout<<"hello world\n"<<endl;
//	return 0;
//}

#include<iostream>
using namespace std;
void func(int a = 10)
{
	cout << a << endl;
}
int main()
{
	func();
	return 0;
}
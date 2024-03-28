#include<iostream>
using namespace std;

void func()
{
	cout << "Value of a is:: " << endl;
}
void func(int a=10)
{
	cout << "Value of a is: "  << endl;

}
int main()
{
	func(1);
	//func(10);
	return 0;
}
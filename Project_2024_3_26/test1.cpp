#include<iostream>
using namespace std;

//void func()
//{
//	cout << "Value of a is:: " << endl;
//}
//void func(int a=10)
//{
//	cout << "Value of a is: "  << endl;
//
//}
//int main()
//{
//	func(1);
//	//func(10);
//	return 0;
//}

class point {
public:
	point() { cout << "C"; }
	~point() { cout << "D"; }
};
int main() {
	point* ptr;
	point A, B;
	point* ptr_point = new point[3];
	//delete[] ptr_point;
	return 0;
}
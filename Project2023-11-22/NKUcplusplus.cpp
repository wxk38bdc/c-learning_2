#define _CRT_SECURE_NO_WARNINGS 1
//专用学校练习时写C++代码

//#include<iostream>
//#include<cstdio>
//using namespace std;
//struct stu {
//	char name[10];
//	int age;
//	int height;
//};
//stu operator+(stu a,int b)
//{
//	a.age += b;
//	return a;
//}
//int main()
//{
//	stu s1 = { "zhangsan",20,180 };
//	stu s2 = s1 + 2;
//	cout << s2.name<<' '<<s2.age<<' '<<s2.height << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int fun(int a, int b) {
//	static int n = 2;
//	int m = 0;
//	n = n + m + a;
//	m = m + n + b;
//	return m;
//}
//int main() {
//	int x = 4, y = 1, r1, r2;
//	r1 = fun(x, y);
//	r2 = fun(x, y);
//	cout << r1 << ','<<r2<<endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//char min(char a, char b)
//{
//	return (a < b) ? : a : b;
//}
////函数模板
//template <typename T> T min(T a, T b)
//{
//	return (a < b) ? a : b;
//}
////一个函数用2个模板
//template <typename T1, typename T2> bool if_min(T1 a, T2 b)
//{
//	return (a < b) ? a : b;
//}
//int main()
//{
//	cout << min('a', 'b') << endl;//调用char min(char a, char b)
//	cout << min(12, 24) << endl;//调用int min(int a, int b)
//	cout << min(12.5, 24.5) << endl;//调用double min(double a, double b)
//	return 0;
//}

//#include <iostream>
//using namespace std;
////回溯
//int x[4] = { 0 };
//void search(int k)
//{
//	if (k > 3)
//	{
//		cout << x[0] << x[1] << x[2] <<x[3]<< endl;
//	}
//	else
//	{
//		for (int i = 1; i <= 4; i++)
//		{
//			x[k] = i;
//			search(k + 1);
//		}
//	}
//}
//int main()
//{
//	search(0);
//	return 0;
//}
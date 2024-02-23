#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//int main()
//{
//	int b[3] = { 1835081801, 1701344288, 2037412640 };
//	char* a = (char*)&b[0];
//	for (int i = 0; i < 12; i++)
//	{
//		cout << a[i];
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	auto a = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	return 0;
//}

int main()
{
	int n;
	cin >> n;
	string s;
	s.reserve(n);
	cin >> s;
	auto it = s.rbegin();
	while (it != s.rend())
	{
		cout << *it;
		it++;
	}
	return 0;
}
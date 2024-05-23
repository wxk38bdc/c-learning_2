#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

template<class T>
void Print(T* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
}
template<class T>
void GtLever(T* p, int n, T lever)
{
	//将大于lever的元素移动到数组最前面
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] > lever)
		{
			swap(p[i], p[j]);
			j++;
		}
	}
	Print(p, j);
}
int main()
{
	string type;
	cin>> type;
	int len;
	cin >> len;
	int n;
	cin >> n;
	if (type == "int")
	{
		int* p = new int[len];
		for (int i = 0; i < len; i++)
		{
			cin >> p[i];
		}
		int lever;
		cin >> lever;
		GtLever(p, n, lever);
		delete[] p;
	}
	else if(type=="float")
	{
		float* p = new float[len];
		for (int i = 0; i < len; i++)
		{
			cin >> p[i];
		}
		float lever;
		cin >> lever;
		GtLever(p, n, lever);
		delete[] p;
	}
	else if(type=="char")
	{
		char* p = new char[len];
		for (int i = 0; i < len; i++)
		{
			cin >> p[i];
		}
		char lever;
		cin >> lever;
		GtLever(p, n, lever);
		delete[] p;
	}
	return 0;
}
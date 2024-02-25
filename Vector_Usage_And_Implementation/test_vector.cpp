#define _CRT_SECURE_NO_WARNINGS
#include"myvector.h"


//void test_vector01()
//{
//	vector<int>v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	auto v2(v1); //拷贝构造
//	//输出
//	for (auto& e : v2)
//	{
//		cout << e << " ";
//	}
//}
//void test_vector02()
//{
//	vector<int>v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	//遍历
//	//方法1：[]+size
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//	//方法2：迭代器
//	vector<int>::iterator it = v1.begin();
//	for (; it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//方法3：auto 即范围for,本质上是迭代器
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//
//}
//void test_vector03()
//{
//	vector<int>v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//插入
//	v1.insert(v1.begin(), 0);
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//删除
//	v1.erase(v1.begin());
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//查找并删除2
//	//v1.erase(v1.begin() + 1);
//
//	auto pos = find(v1.begin(), v1.end(), 2);
//	if (pos != v1.end())
//	{
//		v1.erase(pos);
//	}
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//}
//void test_vector04()
//{
//	vector<int>v1;
//	int size = v1.size();
//	int capacity = v1.capacity();
//	cout<< "size:" << size << " " << "capacity:" << capacity << endl;
//	for (int i = 0; i < 1000; i++)
//	{
//		v1.push_back('a');
//		if (capacity != v1.capacity())
//		{
//			capacity = v1.capacity();
//			cout << "size:" << v1.size() << " " << "capacity:" << capacity << endl;
//		}
//	}
//}
//int main()
//{
//	//test_vector01();
//	//test_vector02();
//	test_vector03();
//	//test_vector04();
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<climits>
//using namespace std;
//int main()
//{
//    long long n;
//    cin >> n;
//    long long* a = new long long[n];
//    long long* b = new long long[n];
//    long long i = 0, j = 0;
//    for (i = 0; i < n; i++)
//    {
//        cin >> a[i];
//    }
//    for (i = 0; i < n; i++)
//    {
//        cin >> b[i];
//    }
//    sort(a, a + n);
//    sort(b, b + n);
//    long long ret = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (a[i] == -1)continue;
//        for (j = 0; j < n; j++)
//        {
//            if (b[j] == INT_MAX)continue;
//            if (2 * a[i] > b[j])
//            {
//                a[i] = -1;
//                b[j] = INT_MAX;
//                ret++;
//                break;
//            }
//        }
//    }
//    cout << ret;
//    delete[]a;
//    delete[]b;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    int* a = new int[n];
//    int* b = new int[n];
//
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> b[i];
//    }
//
//    sort(a, a + n);
//    sort(b, b + n);
//
//    int ret = 0;
//    int i = 0, j = n - 1; // i starts from the beginning of a, j starts from the end of b
//    while (i < n && j >= 0) {
//        if (2 * a[i] <= b[j]) {
//            // b[j] is too large to form a triangle with a[i], decrement j
//            j--;
//        }
//        else {
//            // Found a valid pair, increment ret and move both pointers
//            ret++;
//            i++;
//            j--;
//        }
//    }
//
//    cout << ret << endl;
//
//    delete[] a;
//    delete[] b;
//    return 0;
//}

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double k, m;
		double x = 1;
		cin >> k >> m;
		double cur = 0;
		while (1)
		{
			if (sqrt(x) + floor(log(x) / log(k) )> m)
			{
				cout << x << endl;
				break;
			}
			else
			{
				x += 1.0;
			}
		}
	}
	return 0;
}

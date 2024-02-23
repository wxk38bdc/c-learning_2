#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void test_vector01()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	auto v2(v1); //��������
	//���
	for (auto& e : v2)
	{
		cout << e << " ";
	}
}
void test_vector02()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//����
	//����1��[]+size
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	//����2��������
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����3��auto ����Χfor,�������ǵ�����
	for (auto& e : v1)
	{
		cout << e << " ";
	}

}
void test_vector03()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//����
	v1.insert(v1.begin(), 0);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//ɾ��
	v1.erase(v1.begin());
	for (auto& e : v1)
	{
		cout << e << " ";
	}

}
void test_vector04()
{
	vector<int>v1;
	int size = v1.size();
	int capacity = v1.capacity();
	cout<< "size:" << size << " " << "capacity:" << capacity << endl;
	for (int i = 0; i < 1000; i++)
	{
		v1.push_back('a');
		if (capacity != v1.capacity())
		{
			capacity = v1.capacity();
			cout << "size:" << v1.size() << " " << "capacity:" << capacity << endl;
		}
	}
}
int main()
{
	//test_vector01();
	//test_vector02();
	//test_vector03();
	test_vector04();
	return 0;
}
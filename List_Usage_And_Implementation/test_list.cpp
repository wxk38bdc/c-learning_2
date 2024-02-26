#define _CRT_SECURE_NO_WARNINGS

#include"list.h"
#include<list>
void test_list1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);
	l1.push_back(10);
	l1.push_front(0);
	l1.push_front(-1);
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	list<int>::reverse_iterator rit = l1.rbegin();
	while (rit != l1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test_list2()
{
	//²âÊÔfind,insert,erase
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(9);
	l1.push_back(10);
	l1.push_front(0);
	l1.push_front(-1);

	auto pos = find(l1.begin(), l1.end(), 5);
	if(pos!=l1.end())
	{
		l1.insert(pos, 100);
	}
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
	l1.erase(pos);
	for (auto e : l1)
	{
		cout << e << " ";
	}
}
int main()
{
	//test_list1();
	//test_list2();
	return 0;
}
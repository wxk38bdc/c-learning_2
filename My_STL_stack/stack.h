#pragma once
#include<deque>
#include<list>
using namespace std;
template<class T, class Container = deque<T>>
class Stack
{
private:
	Container con;
public:
	Stack()
	{

	}
	void push(const T& val)
	{
		con.push_back(val);
	}
	void pop()
	{
		con.pop_back();
	}
	T& top()
	{
		return con.back();
	}
	size_t size()
	{
		return con.size();
	}
	bool empty()
	{
		return con.empty();
	}
};
void testStack()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	Stack<int, list<int>> s2;
	s2.push(10);
	s2.push(20);
	s2.push(30);
	s2.push(40);
	s2.push(50);
	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
}
#pragma once
#include<list>
#include<deque>
using namespace std;
template<class T, class Container = deque<T> >
class Queue
{
private:
	Container con;
public:
	Queue(){}
	void push(const T& val)
	{
		con.push_back(val);
	}
	void pop()
	{
		con.pop_front();
	}
	T& front()
	{
		return con.front();
	}
	T& back()
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

void testQueue()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	if (q.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	if(q.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;
}
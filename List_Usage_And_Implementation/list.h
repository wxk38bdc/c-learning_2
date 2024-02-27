#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace myList
{
	/*
	template<class T>
	class list
	{
	private:
		struct Node
		{
			T _data;
			Node* _next;
			Node* _prev;
		};
		Node* _head;
		Node* _tail;
		size_t _size;
	public:
		list()
			:_head(NULL)
			, _tail(NULL)
			, _size(0)
		{}
		~list()
		{
			Node* cur = _head;
			while (cur)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
			}
			_head = _tail = NULL;
		}
		void push_back(const T& data)
		{
			Node* newNode = new Node;
			newNode->_data = data;
			newNode->_next = NULL;
			newNode->_prev = NULL;
			if (_head == NULL)
			{
				_head = _tail = newNode;
			}
			else
			{
				_tail->_next = newNode;
				newNode->_prev = _tail;
				_tail = newNode;
			}
			_size++;
		}
		void pop_back()
		{
			if (_head == NULL)
				return;
			if (_head == _tail)
			{
				delete _head;
				_head = _tail = NULL;
			}
			else
			{
				Node* del = _tail;
				_tail = _tail->_prev;
				_tail->_next = NULL;
				delete del;
			}
			_size--;
		}
		void push_front(const T& data)
		{
			Node* newNode = new Node;
			newNode->_data = data;
			newNode->_next = NULL;
			newNode->_prev = NULL;
			if (_head == NULL)
			{
				_head = _tail = newNode;
			}
			else
			{
				newNode->_next = _head;
				_head->_prev = newNode;
				_head = newNode;
			}
			_size++;
		}
		void pop_front()
		{
			if (_head == NULL)
				return;
			if (_head == _tail)
			{
				delete _head;
				_head = _tail = NULL;
			}
			else
			{
				Node* del = _head;
				_head = _head->_next;
				_head->_prev = NULL;
				delete del;
			}
			_size--;
		}
		void insert(size_t pos, const T& data)
		{
			if (pos > _size)
				return;
			if (pos == 0)
			{
				push_front(data);
			}
			else if (pos == _size)
			{
				push_back(data);
			}
			else
			{
				Node* cur = _head;
				while (pos--)
				{
					cur = cur->_next;
				}
				Node* newNode = new Node;
				newNode->_data = data;
				newNode->_next = cur;
				newNode->_prev = cur->_prev;
				cur->_prev->_next = newNode;
				cur->_prev = newNode;
				_size++;
			}
		}
		void erase(size_t pos)
		{
			if (pos >= _size)
				return;
			if (pos == 0)
			{
				pop_front();
			}
			else if (pos == _size - 1)
			{
				pop_back();
			}
			else
			{
				Node* cur = _head;
				while (pos--)
				{
					cur = cur->_next;
				}
				cur->_prev->_next = cur->_next;
				cur->_next->_prev = cur->_prev;
				delete cur;
				_size--;
			}
		}
		size_t size()
		{
			return _size;
		}
		bool empty()
		{
			return _size == 0;
		}
		void clear()
		{
			Node* cur = _head;
			while (cur)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
			}
			_head = _tail = NULL;
			_size = 0;
		}
		void print()
		{
			Node* cur = _head;
			while (cur)
			{
				cout << cur->_data << " ";
				cur = cur->_next;
			}
			cout << endl;
		}
		*/
	
	template<class T>
	struct __list_node
	{
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T data;
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		//带头双向循环链表
		list()
		{
			_head = new node;
			_head->_prev = _head;
			_head->_next = _head;
		}
		~list()
		{
			node* cur = _head->_next;
			while (cur != _head)
			{
				node* del = cur;
				cur = cur->_next;
				delete del;
			}
			delete _head;
			_head = NULL;
		}
		void push_back(const T& data)
		{
			node* newNode = new node;
			newNode->data = data;
			newNode->_next = _head;
			newNode->_prev = _head->_prev;
			_head->_prev->_next = newNode;
			_head->_prev = newNode;
		}
		void pop_back()
		{
			if (_head->_next == _head)
				return;
			node* del = _head->_prev;
			_head->_prev = del->_prev;
			del->_prev->_next = _head;
			delete del;
		
		}
	private:
		node* _head;
	};

	void test_mylist01()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);
		l.push_back(7);
		l.push_back(8);
		l.push_back(9);
		l.push_back(10);
		l.push_back(11);
		l.push_back(12);
		l.push_back(13);
		l.push_back(14);
		l.push_back(15);

		//l.print();
	}

}
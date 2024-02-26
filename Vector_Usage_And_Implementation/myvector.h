#pragma once
#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
using namespace std;

namespace MyVector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		//拷贝构造
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			copy(v.begin(), v.end(), _start);
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}
		//析构函数
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t size = _finish - _start;
				T* tmp = new T[n];
				if (_start)
				{
					copy(_start, _finish, tmp);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + size;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const T& x = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = x;
					++_finish;
				}
			}
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t size = pos - _start;
				size_t newcapacity = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + size;//reserve可能会导致原有空间被重新分配,所以需要重新定位pos
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
		iterator erase(iterator first, iterator last)
		{
			assert(first >= _start && first <= last && last <= _finish);
			iterator begin = last;
			while (begin != _finish)
			{
				*(first++) = *(begin++);
			}
			_finish -= last - first;
			return first;
		}
		iterator find(iterator first, iterator last, const T& x)
		{
			while (first != last)
			{
				if (*first == x)
				{
					return first;
				}
				++first;
			}
			return last;
		}
		iterator find(const T& x)
		{
			return find(_start, _finish, x);
		}
		//赋值运算符重载
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		void swap(vector<T>& v)
		{
			//交换_start,_finish,_end_of_storage
			//交换的是指针，不是交换指针指向的内容
			//用::是为了区分std::swap和自定义的swap
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_end_of_storage, v._end_of_storage);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	template<class T>
	void print(const vector<T>& v)
	{
		//vector<int>::const_iterator it = v.begin();
		//for (; it != v.end(); it++)
		//{
		//	cout << *it << " ";
		//}
		for (auto&e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//void test_vector01()
	//{
	//	vector<int>v1;
	//	v1.push_back(1);
	//	v1.push_back(2);
	//	v1.push_back(3);
	//	v1.push_back(4);

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
	//}
	//void test_vector02()
	//{
	//	//测试insert,erase,find
	//	vector<int>v1;

	//	v1.push_back(1);
	//	v1.push_back(2);
	//	v1.push_back(3);
	//	v1.push_back(4);
	//	v1.push_back(5);
	//	v1.push_back(6);
	//	v1.push_back(7);
	//	v1.push_back(8);
	//	v1.push_back(9);
	//	v1.push_back(10);

	//	//测试insert
	//	vector<int>::iterator pos = v1.begin();
	//	pos = v1.insert(pos, 0);
	//	print(v1);
	//	v1.insert(pos, -1);
	//	print(v1);
	//	v1.insert(v1.end(), 11);
	//	print(v1);
	//	v1.insert(v1.end(), 12);
	//	print(v1);

	//	//测试erase
	//	vector<int>::iterator it = v1.begin();
	//	it = v1.erase(it);
	//	print(v1);
	//	it = v1.begin();
	//	it = v1.erase(it);
	//	print(v1);

	//	//测试find
	//	vector<int>::iterator pos1 = v1.find(v1.begin(), v1.end(), 6);
	//	if (pos1 != v1.end())
	//	{
	//		cout << "找到了：" << pos1-v1.begin() << endl;
	//	}
	//	else
	//	{
	//		cout << "找不到" << endl;
	//	}
	//}
	//void test_vector03()
	//{
	//	vector<int>v1;
	//	v1.push_back(1);
	//	v1.push_back(2);
	//	v1.push_back(3);
	//	v1.push_back(4);
	//	v1.push_back(5);
	//	v1.push_back(6);
	//	v1.push_back(7);
	//	v1.push_back(8);
	//	v1.push_back(9);
	//	v1.push_back(10);
	//	//测试拷贝构造
	//	vector<int>v2(v1);
	//	print(v2);
	//	//测试赋值运算符重载
	//	vector<int>v3;
	//	v3 = v1;
	//	print(v3);
	//}
	void test_vector04()
	{
		//测试vector<string>
		vector<string>v1;
		v1.push_back("111");
		v1.push_back("222");
		v1.push_back("333");
		v1.push_back("444");
		v1.push_back("555");

		print(v1);
	}
}


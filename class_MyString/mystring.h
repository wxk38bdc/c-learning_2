#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
using namespace std;
namespace MyString
{
	class string
	{
	private:
		char* _str;
		size_t _size;//有效长度
		size_t _capacity;//能够容纳的最大有效长度

		static size_t npos;
	public:
		typedef char* iterator;//迭代器
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		typedef const char* const_iterator;//常迭代器
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}

		string(const char* str = " ")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//string(string& s)//深拷贝
		//{
		//	_size = s.size();
		//	_capacity = s._capacity;
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s.c_str());
		//}
		//深拷贝的现代写法:使用构造函数进行初始化
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}
		size_t size()const
		{
			return _size;
		}
		size_t length()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		const char* c_str()const
		{
			return _str;
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		string& operator=(string s)
		{
			//现代写法
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
			//if (this != &s)
			//{
			//	string tmp(s);
			//	swap(_str, tmp._str);
			//	//delete[] _str;//释放原有空间
			//	//_str = new char[s.size() + 1];
			//	//strcpy(_str, s.c_str());
			//	//_size = s.size();
			//	//_capacity = s.capacity();
			//}
			return *this;
		}
		string& operator=(const char* str)
		{
			string tmp(str);
			swap(_str, tmp._str);
			//delete[] _str;
			//_size = _capacity = strlen(str);
			//_str = new char[strlen(str) + 1];
			//strcpy(_str, str);
			return *this;
		}
		friend istream& operator>>(istream& _cin, string& s);

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n > _capacity)
			{
				reserve(n);
			}
			if (n < _size)
			{
				_str[n] = '\0';
			}
			else
			{
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
			}
			_size = n;
		}
		//增删查改
		void push_back(char ch)
		{
			//如果有效长度等于容量，进行扩容
			if (_size == _capacity)
			{
				size_t newcapacity = (_capacity == 0) ? 15 : 2 * _capacity;
				reserve(newcapacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		void append(const string& s)
		{
			const char* str = s.c_str();
			append(str);
		}
		void operator+=(char ch)
		{
			push_back(ch);
		}
		void operator+=(const char* str)
		{
			append(str);
		}
		void operator+=(const string& s)
		{
			append(s);
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = (_capacity == 0) ? 15 : 2 * _capacity;
				reserve(newcapacity);
			}
			for (size_t i = _size; i > pos; --i)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = ch;
			++_size;
			_str[_size] = '\0';
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			for (int i = _size; i >=(int)pos; --i)
			{
				_str[i + len] = _str[i];
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& insert(size_t pos, const string& s)
		{
			insert(pos, s.c_str());
			return *this;
		}


		size_t find(char ch, size_t pos = 0)const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)const
		{
			char* substr = strstr(_str + pos, str);
			if (substr == nullptr)
			{
				return npos;
			}
			return substr - _str;
			//size_t len = strlen(str);
			//for (size_t i = pos; i < _size - len + 1; ++i)
			//{
			//	if (strncmp(_str + i, str, len) == 0)
			//	{
			//		return i;
			//	}
			//}
			//return npos;
		}
		string& erase(size_t pos, size_t len = npos - 1)
		{
			if (pos >= _size)
			{
				return *this;
			}
			if (pos + len > _size)
			{
				_size = pos;
				_str[_size] = '\0';
				return *this;
			}
			for (size_t i = pos + len; i < _size; ++i)
			{
				_str[i - len] = _str[i];
			}

			_size -= len;
			_str[_size] = '\0';
			return *this;
		}
		bool operator<(const string& s)const
		{
			return strcmp(_str, s.c_str()) < 0;
		}
		bool operator>(const string& s)const
		{
			return strcmp(_str, s.c_str()) > 0;
		}
		bool operator==(const string& s)const
		{
			return strcmp(_str, s.c_str()) == 0;
		}
		bool operator!=(const string& s)const
		{
			return strcmp(_str, s.c_str()) != 0;
		}
		bool operator<=(const string& s)const
		{
			return strcmp(_str, s.c_str()) <= 0;
		}
		bool operator>=(const string& s)const
		{
			return strcmp(_str, s.c_str()) >= 0;
		}
	};
	size_t string::npos = -1;//静态成员变量的初始化
	ostream& operator<<(ostream& _cout, const string& s)
	{
		//for(size_t i = 0; i < s.size(); ++i)
		//{
		//	_cout << s[i];
		//}
		_cout << s.c_str();
		return _cout;
	}
	istream& operator>>(istream& _cin, string& s)
	{
		_cin >> s._str;
		s._size = strlen(s._str);
		s._capacity = s._size;
		return _cin;
	}
	void test_string1()
	{
		string s1("hello");
		string s2(s1);
		string s3 = s1;
		string s4 = "world";
		//cout << s1 << endl;
		//cout << s2.c_str() << endl;
		//cout << s3.c_str() << endl;
		//cout << s4.c_str() << endl;
		//for (auto e : s4)//范围for-底层使用迭代器
		//{
		//	cout << e << " ";
		//}
		//s1.push_back(' ');
		//s1.append(s4);
		//s1 += "you";
		//s1 += 'k';
		//s1 += s4;
		//cout << s1 << endl;
		//s1 += " world";
		//cout << s1 << endl;
		//s1.erase(1);
		//cout << s1 << endl;
		cout << s1 << endl;
		cin >> s1;
		cout << s1 << endl;
	}
	void test_string2()
	{
		string s1("hello");
		string s2("world");
		cout << (s1 < s2) << endl;
		cout << (s1 > s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 != s2) << endl;
		cout << (s1 <= s2) << endl;
		cout << (s1 >= s2) << endl;
	}
	void test_string3()
	{
		string s1("hello");
		s1.insert(1, 'a');
		cout << s1 << endl;
		s1.insert(1, "world");
		cout << s1 << endl;
		s1.erase(1, 5);
		cout << s1 << endl;
		cout << s1.find('l') << endl;
		cout << s1.find("lo") << endl;
		s1.insert(0, "00");
		cout << s1 << endl;
	}
}
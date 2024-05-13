#pragma once
#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;
namespace MyString
{
	class string
	{
	private:
		char* _str;
		size_t _size;//有效长度
		size_t _capacity;//能够容纳的最大有效长度

	public:
		//构造函数、析构函数与赋值运算符重载
		string(const char* str = " ");
		string(const string& s);
		~string();
		string& operator=(string s);
		string& operator=(const char* str);

		//访问及遍历操作函数
		typedef char* iterator;//迭代器
		iterator begin();
		iterator end();
		typedef const char* const_iterator;//常迭代器
		const_iterator begin()const;
		const_iterator end()const;
		const char& operator[](size_t index)const;
		char& operator[](size_t index);

		//容量操作函数
		size_t size()const;
		size_t length()const;
		size_t capacity()const;
		void reserve(size_t n);
		void resize(size_t n, char ch = '\0');
		void clear();

		//对象修改操作函数
		void push_back(char ch);
		void append(const char* str);
		void append(const string& s);
		void operator+=(char ch);
		void operator+=(const char* str);
		void operator+=(const string& s);
		string operator+(char ch);
		string operator+(const char* str);
		string operator+(const string& s);
		string& insert(size_t pos, char ch);
		string& insert(size_t pos, const char* str);
		string& insert(size_t pos, const string& s);
		string& erase(size_t pos, size_t len = npos - 1);
		void swap(string& s);

		//其他操作函数
		string substr(size_t pos = 0, size_t len = npos - 1)const;
		size_t find(char ch, size_t pos = 0)const;
		size_t find(const char* str, size_t pos = 0)const;
		const char* c_str()const;

		//运算符重载
		bool operator<(const string& s)const;
		bool operator>(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator>=(const string& s)const;
		friend ostream& operator<<(ostream& _cout, const string& s);
		friend istream& operator>>(istream& _cin, string& s);
		
		//静态成员
		const static size_t npos;
	};
	
}
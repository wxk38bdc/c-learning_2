#define _CRT_SECURE_NO_WARNINGS 1

#include"mystring.h"//自定义的string类

namespace MyString
{
	string::string(const char* str)
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	string::string(const string& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		string tmp(s._str);
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}

	size_t string::npos = -1;

	ostream& operator<<(std::ostream& _cout, const string& s) {
		_cout << s.c_str();
		return _cout;
	}

	istream& operator>>(std::istream& _cin, string& s) {
		char temp[1000];
		_cin >> temp;
		string tmp(temp);
		std::swap(s._str, tmp._str);
		std::swap(s._size, tmp._size);
		std::swap(s._capacity, tmp._capacity);
		return _cin;
	}
}


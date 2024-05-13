#define _CRT_SECURE_NO_WARNINGS 1

#include"mystring.h"//自定义的string类

namespace MyString
{
	//构造函数、析构函数与赋值运算符重载
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
		std::swap(_str, tmp._str);
		std::swap(_size, tmp._size);
		std::swap(_capacity, tmp._capacity);
	}

	string::~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	string& string::operator=(string s)
	{
		//现代写法
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
		return *this;
	}

	string& string::operator=(const char* str)
	{
		string tmp(str);
		std::swap(_str, tmp._str);
		std::swap(_size, tmp._size);
		std::swap(_capacity, tmp._capacity);
		return *this;
	}

	//访问及遍历操作函数
	string::iterator string::begin()
	{
		return _str;
	}
	
	string::iterator string::end()
	{
		return _str + _size;
	}

	string::const_iterator string::begin()const
	{
		return _str;
	}

	string::const_iterator string::end()const
	{
		return _str + _size;
	}

	const char& string::operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	char& string::operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}

	//容量操作函数
	size_t string::size()const
	{
		return _size;
	}

	size_t string::length()const
	{
		return _size;
	}

	size_t string::capacity()const
	{
		return _capacity;
	}

	void string::reserve(size_t n)
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

	void string::resize(size_t n, char ch)
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

	void string::clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}

	//对象修改操作函数
	void string::push_back(char ch)
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

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	void string::append(const string& s)
	{
		const char* str = s.c_str();
		append(str);
	}

	void string::operator+=(char ch)
	{
		push_back(ch);
	}
	void string::operator+=(const char* str)
	{
		append(str);
	}
	void string::operator+=(const string& s)
	{
		append(s);
	}
	string string::operator+(char ch)
	{
		string tmp(*this);
		tmp.push_back(ch);
		return tmp;
	}
	string string::operator+(const char* str)
	{
		string tmp(*this);
		tmp.append(str);
		return tmp;
	}
	string string::operator+(const string& s)
	{
		string tmp(*this);
		tmp.append(s);
		return tmp;
	}
	string& string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newcapacity = (_capacity == 0) ? 15 : 2 * _capacity;
			reserve(newcapacity);
		}
		for (size_t i = _size; i > (int)pos; --i)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = ch;
		++_size;
		_str[_size] = '\0';
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		for (int i = _size; i >= (int)pos; --i)
		{
			_str[i + len] = _str[i];
		}
		strncpy(_str + pos, str, len);
		_size += len;
		return *this;
	}
	string& string::insert(size_t pos, const string& s)
	{
		insert(pos, s.c_str());
		return *this;
	}

	string& string::erase(size_t pos, size_t len)
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

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	//其他操作函数
	string string::substr(size_t pos, size_t len) const {
		if (pos > _size) {
			throw std::out_of_range("Position is out of range");
		}
		if (len == npos || pos + len > _size) {
			len = _size - pos;
		}

		string tmp;
		tmp.reserve(len);
		for (size_t i = 0; i < len; ++i) {
			tmp.push_back(_str[pos + i]);
		}
		return tmp;
	}

	size_t string::find(char ch, size_t pos)const
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

	size_t string::find(const char* str, size_t pos)const
	{
		char* substr = strstr(_str + pos, str);
		if (substr == nullptr)
		{
			return npos;
		}
		return substr - _str;
	}

	const char* string::c_str()const
	{
		return _str;
	}

	//运算符重载
	bool string::operator<(const string& s)const
	{
		return strcmp(_str, s.c_str()) < 0;
	}
	bool string::operator>(const string& s)const
	{
		return strcmp(_str, s.c_str()) > 0;
	}
	bool string::operator==(const string& s)const
	{
		return strcmp(_str, s.c_str()) == 0;
	}
	bool string::operator!=(const string& s)const
	{
		return strcmp(_str, s.c_str()) != 0;
	}
	bool string::operator<=(const string& s)const
	{
		return strcmp(_str, s.c_str()) <= 0;
	}
	bool string::operator>=(const string& s)const
	{
		return strcmp(_str, s.c_str()) >= 0;
	}
	
	ostream& operator<<(ostream& _cout, const string& s) {
		_cout << s.c_str();
		return _cout;
	}

	istream& operator>>(istream& _cin, string& s) {
		char temp[1000];
		_cin >> temp;
		string tmp(temp);
		std::swap(s._str, tmp._str);
		std::swap(s._size, tmp._size);
		std::swap(s._capacity, tmp._capacity);
		return _cin;
	}

	//静态成员
	const size_t string::npos = -1;
}


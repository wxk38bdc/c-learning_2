#include"date.h"

//构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
//拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
//析构函数（在日期类中没啥用）
Date::~Date()
{
	_year = 2000;
	_month = 1;
	_day = 1;
}
//赋值运算符重载
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;

}
//打印日期
void Date::Print()const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//等于运算符重载
bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
//小于运算符重载
bool Date::operator<(const Date& d)const
{
	if (_year < d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day < d._day)
				return true;
		}
	}
	return false;
}
//小于等于运算符重载
bool Date::operator<=(const Date& d)const
{
	return *this < d || *this == d;
}
//大于运算符重载
bool Date::operator>(const Date& d)const
{
	return !(*this <= d);
}
//大于等于运算符重载
bool Date::operator>=(const Date& d)const
{
	return !(*this < d);
}
//不等于运算符重载
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}
//获取某年某月的天数
int Date::getDayOfMonth(int year, int month)const
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		days[2] = 29;
	}
	return days[month];
}
//+=运算符重载
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > getDayOfMonth(_year, _month))
	{
		_day -= getDayOfMonth(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
//+运算符重载
Date Date::operator+(int day)const
{
	Date ret(*this);
	ret += day;
	return ret;
}
//前置++运算符重载
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//后置++运算符重载
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;
	return ret;
}
//-=运算符重载
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day < 1)
	{
		_month--;
		if (_month < 1)
		{
			_month = 12;
			_year--;
		}
		_day += getDayOfMonth(_year, _month);
	}
	return *this;
}
//-运算符重载
Date Date::operator-(int day)const
{
	Date ret(*this);
	ret -= day;
	return ret;
}
//前置--运算符重载
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//后置--运算符重载
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}

int Date::operator-(const Date& d)const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min < max)
	{
		min++;
		count++;
	}
	return count * flag;
}

//<<运算符重载
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

//>>运算符重载
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
#pragma once
#include<iostream>

using namespace std;

class Rational {
private:
	int num;//numerator,分子
	int den;//denominator,分母
public:
	Rational(int n = 0, int d = 1) : num(n), den(d)//构造函数
	{
		if (den == 0)
		{
			cout << "Denominator can't be zero!" << endl;
			exit(1);
		}
		simplify();
	}
	Rational(const Rational& r) : num(r.num), den(r.den) //拷贝构造函数
	{
		simplify();
	}
	void simplify()//约分
	{
		int a = num, b = den, c;
		while (b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
		num /= a;
		den /= a;
		if (den < 0)
		{
			num = -num;
			den = -den;
		}
	}
	//重载运算符
	Rational operator+(const Rational& r) const
	{
		return Rational(num * r.den + r.num * den, den * r.den);
	}
	Rational operator-(const Rational& r) const
	{
		return Rational(num * r.den - r.num * den, den * r.den);
	}
	friend Rational operator*(const Rational& r1, const Rational& r2);
	friend Rational operator/(const Rational& r1, const Rational& r2);
	friend ostream& operator<<(ostream& os, const Rational& r);

	Rational operator++()//前置++
	{
		num += den;
		return *this;
	}
	Rational& operator=(const Rational& r) {
		if (this != &r) { // 避免自我赋值
			num = r.num;
			den = r.den;
		}
		return *this;
	}
	Rational invert() const {
		if (num == 0) { // 避免除以零
			cout << "Cannot invert a zero numerator!" << endl;
			return *this;
		}
		return Rational(den, num);
	}
};

Rational operator*(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num * r2.num, r1.den * r2.den);
}
Rational operator/(const Rational& r1, const Rational& r2)
{
	return Rational(r1.num * r2.den, r1.den * r2.num);
}
ostream& operator<<(ostream& os, const Rational& r)
{
	if (r.den == 1)
		os << r.num;
	else
		os << r.num << "/" << r.den;
	return os;
}
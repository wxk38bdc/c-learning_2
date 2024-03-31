#ifndef _MYNUM_H_

#define _MYNUM_H_
/*
	MyNum类  存放单个数字元
	由于想要实现大数的运算  所以用int数组来存放数字(用了deque因为比vector更方便一点)
	模仿IEEE浮点数的思路 将数字转化为  0.xxxxx * 10^power
		其中xxxxx是"有效数字"  power是阶数		注意: 这里的"有效数字"不包括末尾的一些0
	deque<int> digits	//有效数字
	int power			//幂指数
	int sign			//符号  1正-1负  0表示零  -2 ERROR  2表示计算符

	一些特殊量:
		0:  digits={0} power=0 sign=0 即这里面的zero常量
		ERROR: digits={-1} power=0 sign=-2
		sign=2: 表示计算符  此时将digits临时变为char型数组 存放函数名称
				其中power的含义变为运算符优先级
				( -1  逻辑判断符0   +- 1    /*% 2   ^3   函数4
*/
#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>


#define PRECISION 35		//设定默认精度

using std::string;

const std::deque<int> ZERODEQUE(1);

const std::deque<string> errorreason({
		"禁止出现除以0！",
		"禁止出现0的0次幂！",
		"禁止出现负数的分数次幂！",
		"表达式非法！",
		"log函数不允许非正底数出现！"
	}
);

class MyNum {
public:
	//构造函数
	MyNum(const std::deque<int>& d = ZERODEQUE, int p = 0, int s = 0)
		:digits(d), power(p), sign(s) {}
	MyNum(int i);
	MyNum(long long i);
	MyNum(double d);
	MyNum(std::string str);

	//拷贝构造拷贝赋值
	MyNum(const MyNum& other)
		:digits(other.digits), power(other.power), sign(other.sign) {}
	MyNum& operator= (const MyNum& other) {
		this->digits = other.digits;
		this->power = other.power;
		this->sign = other.sign;
		return *this;
	}

	//析构
	~MyNum() {}

	//数学函数
	static MyNum getPI();	//求π
	//单目数学函数
	MyNum My_sqrt() const;
	MyNum My_sin() const; MyNum My_cos() const; MyNum My_tan() const;
	MyNum My_exp() const;
	MyNum My_fabs() const;
	MyNum My_neg() const;
	MyNum My_log() const;
	//多目数学函数
		//见类外定义的非成员函数
	friend MyNum My_gcd(const MyNum& a, const MyNum& b);
	friend MyNum My_lcm(const MyNum& a, const MyNum& b);

	//转换函数
	double to_double() const;
	int to_int() const;
	long long to_longlong() const;
	std::string to_string() const;
	MyNum decimalpart() const;
	MyNum addError(int i)const;

	//运算符重载
	bool operator<(const MyNum& other)const;
	bool operator>(const MyNum& other)const;
	bool operator==(const MyNum& other)const;
	bool operator!=(const MyNum& other)const;
	bool operator<=(const MyNum& other)const;
	bool operator>=(const MyNum& other)const;
	MyNum operator+(const MyNum& other)const;
	MyNum operator-()const;
	MyNum operator-(const MyNum& other)const;
	MyNum operator*(const MyNum& other)const;
	MyNum operator/(const MyNum& other)const;
	MyNum operator^(const MyNum& other)const;
	MyNum power_int(int k)const;
	MyNum power_decimal(const MyNum& decimal)const;
	MyNum& operator+=(const MyNum& other);
	MyNum& operator-=(const MyNum& other);
	MyNum& operator*=(const MyNum& other);
	MyNum& operator/=(const MyNum& other);


	//显示
	void show() const;
	void setPrecision(int prec = PRECISION);


private:
	std::deque<int> digits;
	int power;
	int sign;

	friend class Method;
};


MyNum My_gcd(const MyNum& a, const MyNum& b);
MyNum My_lcm(const MyNum& a, const MyNum& b);

#endif


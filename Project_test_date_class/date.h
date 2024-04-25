#pragma once
#include<iostream>
using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date(int year = 2000, int month = 1, int day = 1);//构造函数
	Date(const Date& d);//拷贝构造函数
	~Date();//析构函数
	Date& operator=(const Date& d);//赋值运算符重载

	void Print()const;//打印日期

	bool operator==(const Date&d)const;//等于运算符重载
	bool operator<(const Date&d)const;//小于运算符重载
	bool operator<=(const Date&d)const;//小于等于运算符重载
	bool operator>(const Date&d)const;//大于运算符重载
	bool operator>=(const Date&d)const;//大于等于运算符重载
	bool operator!=(const Date&d)const;//不等于运算符重载

	int getDayOfMonth(int year, int month)const;//获取某年某月的天数
	Date& operator+=(int day);//+=运算符重载
	Date operator+(int day)const;//+运算符重载
	Date& operator++();//前置++运算符重载
	Date operator++(int);//后置++运算符重载
	Date& operator-=(int day);//-=运算符重载
	Date operator-(int day)const;//-运算符重载
	Date& operator--();//前置--运算符重载
	Date operator--(int);//后置--运算符重载

	int operator-(const Date&d)const;//-运算符重载

	friend ostream& operator<<(ostream& _cout, const Date& d);//<<运算符重载
	friend istream& operator>>(istream& _cin, Date& d);//>>运算符重载
};
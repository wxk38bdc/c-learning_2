#pragma once
#include <iostream>
#include <initializer_list>


// 保存位置的类
class seat
{
public:
	int i;      // y 坐标
	int j;      // x 坐标
	int number; // 分数
public:
	seat(int i = 0, int j = 0, int number = 0) : i(i), j(j), number(number) {}
	seat(std::initializer_list<int> list) : i(*list.begin()), j(*(list.begin() + 1)), number(*(list.begin() + 2)) {}
};
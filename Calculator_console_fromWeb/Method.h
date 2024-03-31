#ifndef _METHOD_H_

#define _METHOD_H_
/*
	Method类  存放计算式的原式 后缀表达式 以及 计算答案

	string calstr			//计算的原式
	std::deque<MyNum> rpn	//ReversePolishNotation 逆波兰表示法/后缀表达式
	int type				//0 计算式  1 逻辑条件式
	MyNum ans				//计算结果

*/
#include <iostream>
#include <cmath>
#include <string>

#include "MyNum.h"

using std::string;

extern int SHOW_PRECISION;

class Method {
public:
	//构造
	Method(string s, int t = 0)
		:type(t) {
		input(s);
		changetorpn();
		calculate();
	}

	//操作函数
	void input(std::string str);		///输入 将字符串中计算部分提取出来
	void opstackpushback(std::deque<MyNum>& opstack, MyNum op);	//计算符号入栈
	void changetorpn();	//将计算式转换为后缀表达式
	MyNum calculate();	//计算

	//显示
	void showCalstr();
	void showRPN();
	void showAns(int showprecision = SHOW_PRECISION);
	void show(int type = 0);

private:
	string calstr;
	std::deque<MyNum> rpn;
	int type;
	MyNum ans;
};

#endif //_METHOD_H_

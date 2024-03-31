#define _CRT_SECURE_NO_WARNINGS

/*
* 声明：
* 本项目的原码复制自 https://www.cnblogs.com/xpxpxp/p/17191676.html 
* 原作者：張xp
* 如有侵权，实属抱歉，请联系我删除
*/

#include <iostream>
#include <string>

#include "MyNum.h"	
#include "Method.h"

using namespace std;

int SHOW_PRECISION;	//输出精度

ostream& operator<<(ostream& out, const MyNum& num) {
	num.show();
	return out;
}



deque<Method> history;		//计算历史记录
int showType;		//显示模式 0简洁模式 只有答案    1详细模式  有原式,后缀表达式,答案  

void showHistory() {
	for (auto i : history) {
		i.showCalstr(); printf("\nans = "); i.showAns(); cout << endl;
	}
}

int inputMethod() {
	char s[20000]{ 0 };
	cout << ">> ";
	fflush(stdin);
	cin.getline(s, 20000);
	string str(s);
	if (str.empty()) {
		getchar();
		return -1;
	}
	if (str == "end")
		return 0;
	if (str == "history") {
		return 2;
	}
	if (str == "changeshowtype") {
		showType = 1 - showType;
		return 3;
	}
	if (str.size() > 12 && str.substr(0, 12) == "setprecision") {
		int newprecision = 0;
		for (int i = 13; i < str.size(); i++) {
			newprecision *= 10;
			newprecision += str[i] - '0';
		}
		SHOW_PRECISION = newprecision;
		return 4;
	}
	Method m(str);
	history.push_back(m);
	return 1;
}

void Func() {
	int input = 1;
	while (true) {
		input = inputMethod();
		if (input == 0) break;
		if (input == 1) {
			history.back().show(showType);
			cout << endl;
			getchar();
		}
		if (input == 2) {
			printf("历史计算:\n");
			showHistory();
			getchar();
		}
		if (input == 3) {
			printf("已更改显示模式为:");
			if (showType == 1) printf("详细模式\n");
			else printf("简洁模式\n");
			getchar();
		}
		if (input == 4) {
			printf("输出小数精度已被设置为:%d位小数\n", SHOW_PRECISION);
			getchar();
		}
	}
}

void Welcome() {
	cout << R"(
			大数计算器  v1.0

在">>"后输入计算式 回车即可显现结果  输入"end"回车即结束程序
高级功能:
	* 输入"changeshowtype"即可更改显示模式
		- 简洁模式: 类似Matlab 回车只输出答案
		- 详细模式: 输出原式, 后缀表达式 以及答案
	* 输入"history"即可查看本次运行期间的计算记录
	* 输入"setprecision 数字"即可更改显示答案精度 最高不超过20位

)" << endl;
}

int main() {
	showType = 0;
	SHOW_PRECISION = 6;

	Welcome();
	Func();
	return 0;
}

/*
一些测试数据
(log(0.158^2.333)+exp((2/7)^-0.6))/sin(sqrt(6.66)/5.867^(1.28+0.276))
正确的ans应该为24.618012958794913524198906652290747191348807023896450870419


*/

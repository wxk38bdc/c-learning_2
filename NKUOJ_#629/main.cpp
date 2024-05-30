/*
题目描述:
电商为了增加销量会提出各种优惠策略，如折扣、满减等活动。不同的优惠策略对应不同的算法，如果不对这些策略进行封装，再有新的优惠策略就要修改程序中很多地方;在这种情况下，采用多态的方法会让程序更加灵活，更好维护。请应用多态的思想，设计一个抽象基类CashSuper，其中包含一个纯虚函数AcceptCash，优惠方式均继承自Cashsuper类，根据不同的优惠方式，计算出顾客应付的金额。

输入
第一行一个整数N，表示有N组优惠策略:

第二行一个整数M，表示目前商品的金额:

接下来的N行，每行包括一个整数m(优惠活动类型):

m=1代表折扣活动，紧接着一个整数q(0<=q<=10)，代表商品打q折，如q=8，代表商品打八折;

m=2代表一次性的满减活动，紧接着两个整数a和b，表示若M>=a元，则M减免b元，如a=499，b=50，意思是满499元减50元;

m=3代表先折扣再满减活动，紧接着有一个整数9(0<=q<=10)，表示商品打q折，然后是整数a和b，表示若折后价格>=a元，则折后价格减免b元。

输出：
N 行，每一行一个整数，代表单独使用该优惠活动m后，顾客需要支付的实际金额。

样例输入：
3
500
1 8
2 499 50
3 8 400 50
样例输出：
400
450
350
注意：必须实现多态、纯虚函数、动态联编，否则计0分。
*/
#include <iostream>
#include <cstring>
using namespace std;

class CashSuper
{
public:
	virtual int AcceptCash() { return 0; }
};
class CashSuper1 :public CashSuper
{
public:
	int q;
	int origin;
	CashSuper1(int _q = 0, int _origin = 0) :q(_q), origin(_origin) {}
	int AcceptCash()
	{
		return origin * q / 10;
	}
};
class CashSuper2 :public CashSuper
{
public:
	int a;
	int b;
	int origin;
	CashSuper2(int _a = 0, int _b = 0, int _origin = 0) :a(_a), b(_b), origin(_origin) {}
	int AcceptCash()
	{
		return origin >= a ? origin - b : origin;
	}
};
class CashSuper3 :public CashSuper
{
public:
	int q;
	int a;
	int b;
	int origin;
	CashSuper3(int _q = 0, int _a = 0, int _b = 0, int _origin = 0) :q(_q), a(_a), b(_b), origin(_origin) {}
	int AcceptCash()
	{
		return origin * q / 10 >= a ? origin * q / 10 - b : origin * q / 10;
	}
};
int main()
{
	int N;//N组优惠策略
	cin >> N;
	int M;//目前商品的金额
	cin >> M;
	while (N--)
	{
		int m;
		cin >> m;
		switch (m) {
		case 1:
		{
			int q_1;
			cin >> q_1;
			CashSuper1 c1(q_1, M);
			cout << c1.AcceptCash() << endl;
			break;
		}
		case 2:
		{
			int a_1, b_1;
			cin >> a_1 >> b_1;
			CashSuper2 c2(a_1, b_1, M);
			cout << c2.AcceptCash() << endl;
			break;
		}
		case 3:
		{
			int q_3, a_3, b_3;
			cin >> q_3 >> a_3 >> b_3;
			CashSuper3 c3(q_3, a_3, b_3, M);
			cout << c3.AcceptCash() << endl;
			break;
		}
		}
	}
	return 0;
}
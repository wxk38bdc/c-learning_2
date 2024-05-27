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
/*
题目描述
设计一个复数类Complex，进行复数的运算。要求：

（1）包含两个整数数据成员表示实部和虚部；

（2）包含一个对所有参数明对象初始化的构造函数。未提供参数时，构造函数应提供默认值；

（3）用运算符重载的形式，实现以下操作：a) 两个Complex值相加，b) 两个Complex值相减，c) 两个Complex值相乘；

（4）编写主函数，测试Complex类。

输入
输入四个整数，分别是两个复数的实部和虚部。

输出
以a+bi的形式

第一行输出两个复数的和。

第二行输出两个复数的差。

第三行输出两个复数的乘积。

（注意：若最终结果为0，则输出0。实部和虚部为0则不输出，例如2+0i，则输出2；0+3i，则不输出实部的0以及虚部的+号，直接输出3i。若实部为正数，或为零，则虚部前面的+号。若虚部出现1或者-1，则不输出1，例如8+1i，应直接输出8+i）

提示：
复数的概念：我们把形如z=a+bi (a, b均为实数)的数称为复数。其中，a称为实部，b称为虚部，i称为虚数单位，其中，i的平方等于-1。

特别注意：
此题仅仅涉及两个复数的真确算法，直接输出结果获得AC的同学，记0分。

样例输入
2 2 2 5

样例输出
4+7i
-3i
-6+14i
*/
#include<iostream>
#include<cstdlib>
using namespace std;

class Complex
{
private:
	int re;//实部
	int im;//虚部
public:
	Complex(int _re = 0, int _im = 0) :re(_re), im(_im) {}
	Complex(const Complex& c) :re(c.re), im(c.im) {}
	Complex operator=(const Complex& c)
	{
		if (this != &c) {
			re = c.re;
			im = c.im;
		}
		return *this;
	}
	Complex operator+(const Complex& c)
	{
		Complex tmp(*this);
		tmp.re += c.re;
		tmp.im += c.im;
		return tmp;
	}
	Complex operator-(const Complex& c)
	{
		Complex tmp(*this);
		tmp.re -= c.re;
		tmp.im -= c.im;
		return tmp;
	}
	Complex operator*(const Complex& c)
	{
		int ret_re = re * c.re - im * c.im;
		int ret_im = re * c.im + im * c.re;
		Complex tmp(*this);
		tmp.re = ret_re;
		tmp.im = ret_im;
		return tmp;
	}
	void show()
	{
		if (re == 0 && im == 0)cout << 0 << endl;
		else if (re == 0)cout << im << "i" << endl;
		else if (im == 0)cout << re << endl;
		else if (im == 1)cout << re << "+" << "i" << endl;
		else if (im == -1)cout << re << "-" << "i" << endl;
		else if (im > 0)cout << re << "+" << im << "i" << endl;
		else cout << re << im << "i" << endl;
	}
};
int main()
{
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	Complex c1(a1, b1);
	Complex c2(a2, b2);
	Complex ret1 = c1 + c2;
	Complex ret2 = c1 - c2;
	Complex ret3 = c1 * c2;

	ret1.show();
	ret2.show();
	ret3.show();
	return 0;
}
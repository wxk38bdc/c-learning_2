#include"Rational.h"

int main()
{
	int num1, den1, num2, den2;
	cin >> num1 >> den1 >> num2 >> den2;
	Rational r1(num1, den1), r2(num2, den2);
	Rational r1_tmp(r1);
	Rational r2_tmp(r2);
	cout << r1 + r2 << endl;
	cout << r1 - r2 << endl;
	cout << r1 * r2 << endl;
	cout << r1 / r2 << endl;
	cout << ++r1_tmp <<" "<< ++r2_tmp << endl;
	Rational R1 = r1.invert();
	Rational R2 = r2.invert();
	cout << R1 << " " << R2 << endl;
	return 0;
}
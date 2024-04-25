#include"matrix.h"

int main()
{
	Matrix m1(3, 2);
	m1.set();
	Matrix m2(3, 2);
	m2.set();
	Matrix m3(3, 3);
	m3.set();

	Matrix m4 = m1 + m2;
	m4.print();
	Matrix m5 = m1 - m3;
	m5.print();

	return 0;
}
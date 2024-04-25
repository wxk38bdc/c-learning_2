#pragma once
#include<iostream>
using namespace std;

class Matrix
{
private:
	int row;
	int col;
	double** memory;
public:
	Matrix(int _row, int _col);
	Matrix(const Matrix& m);
	~Matrix();

	void set();
	void print();
	Matrix& operator=(const Matrix& m);
	Matrix operator+(const Matrix& m);//¾ØÕó¼Ó·¨
	Matrix operator-(const Matrix& m);//¾ØÕó¼õ·¨
	//Matrix operator*(const Matrix& m);//¾ØÕó³Ë·¨
	Matrix operator*(int n);//¾ØÕóÊı³Ë
	//Matrix operator~(const Matrix& m);//¾ØÕó×ªÖÃ
};
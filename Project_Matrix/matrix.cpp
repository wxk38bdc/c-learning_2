#include"matrix.h"

//构造函数
Matrix::Matrix(int _row, int _col)
{
	row = _row;
	col = _col;
	memory = new double*[row];
	for(int i = 0; i < row; i++)
	{
		memory[i] = new double[col];
	}
}

//拷贝构造函数
Matrix::Matrix(const Matrix &m)
{
	row = m.row;
	col = m.col;
	memory = new double*[row];
	for(int i = 0; i < row; i++)
	{
		memory[i] = new double[col];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			memory[i][j] = m.memory[i][j];
		}
	}
}

//析构函数
Matrix::~Matrix()
{
	for(int i = 0; i < row; i++)
	{
		delete[] memory[i];
	}
	delete[] memory;
}

//设置矩阵元素
void Matrix::set()
{
	//输入矩阵元素
	for(int i = 0; i < row; i++)
	{
		cout<<"请输入第"<<i+1<<"行的元素,有"<<col<<"个:";
		for(int j = 0; j < col; j++)
		{
			cin >> memory[i][j];
		}
	}
}

//打印矩阵
void Matrix::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << memory[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if(this == &m)
	{
		return *this;
	}
	for(int i = 0; i < row; i++)
	{
		delete[] memory[i];
	}
	delete[] memory;
	row = m.row;
	col = m.col;
	memory = new double*[row];
	for(int i = 0; i < row; i++)
	{
		memory[i] = new double[col];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			memory[i][j] = m.memory[i][j];
		}
	}
	return *this;

}

//重载+
Matrix Matrix::operator+(const Matrix &m)
{
	Matrix temp(row, col);
	if(row != m.row || col != m.col)
	{
		cout<<"矩阵维度不同，无法相加"<<endl;
		return *this;
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			temp.memory[i][j] = memory[i][j] + m.memory[i][j];
		}
	}
	return temp;
}

//重载-
Matrix Matrix::operator-(const Matrix &m)
{
	Matrix temp(row, col);
	if(row != m.row || col != m.col)
	{
		cout<<"矩阵维度不同，无法相减"<<endl;
		return *this;
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			temp.memory[i][j] = memory[i][j] - m.memory[i][j];
		}
	}
	return temp;
}

//重载*（数乘）
Matrix Matrix::operator*(double num)
{
	Matrix temp(row, col);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			temp.memory[i][j] = memory[i][j] * num;
		}
	}
	return temp;
}
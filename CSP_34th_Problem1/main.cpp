/*
矩阵重塑（其一）
题目背景
矩阵（二维）的重塑（reshape）操作是指改变矩阵的行数和列数，同时保持矩阵中元素的总数不变。

输入格式
从标准输入读入数据。

输入共n+1 行。

输入的第一行包含四个正整数n、m 和p、q。

接下来依次输入原矩阵M 的第0 到第n−1 行，每行包含m 个整数，按列下标从0 到m−1 的顺序依次给出。

输出格式
输出到标准输出。

输出共p 行，每行q 个整数，表示重塑后的矩阵M′。输出格式与输入相同，即依次输出M′的第0 行到第p−1 行；行内按列下标从0 到q−1 的顺序输出，且两个整数间仅用一个空格分隔。

样例1输入
2 3 3 2
1 2 3
4 5 6
样例1输出
1 2
3 4
5 6
样例2输入
2 2 1 4
6 6
6 6
样例2输出
6 6 6 6

*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	vector<int>v(n * m);
	for (int i = 0; i < n * m; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cout << v[i * q + j] << " ";
		}
		cout << endl;
	}
	return 0;
}
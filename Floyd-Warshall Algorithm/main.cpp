/*
题目描述
一个有向图中有 n 个顶点和 m 条单向路径，试求任意两点间的最短距离。

Input Format
第一行两个正整数 n 和 m，分别代表顶点的数量和路径的数量。
0 < n < 20, 0 <= m < 50。

之后 m 行每行有三个整数 i, j, k，分别表示路径的起点和终点序号和路径长度。顶点编号从 0 开始，0 <= i, j < n, 0 < k。

Output Format
顶点之间最短路径矩阵(n * n)，-1 代表不连通。

每一行的最后一个数字后面没有空格。

样例输入输出
样例1
输入:
3 5
0 1 6
0 2 13
1 0 10
1 2 4
2 0 5
输出:
0 6 10
9 0 4
5 11 0

样例2
输入:
6 0
输出:
0 -1 -1 -1 -1 -1
-1 0 -1 -1 -1 -1
-1 -1 0 -1 -1 -1
-1 -1 -1 0 -1 -1
-1 -1 -1 -1 0 -1
-1 -1 -1 -1 -1 0

*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<climits>
using namespace std;


class Graph {
private:
	int _vertexnum;//顶点数
	int _edgenum;//边数
	vector<vector<int>> _matrix;//邻接矩阵
public:
	//构造函数
	Graph(int vertexnum, int edgenum)
	{
		_vertexnum = vertexnum;
		_edgenum = edgenum;
		_matrix.resize(vertexnum);
		for (int i = 0; i < vertexnum; i++)
		{
			_matrix[i].resize(vertexnum, INT_MAX);
		}
	}

	void CreateGraph()
	{
		int from, to, weight;
		for (int i = 0; i < _edgenum; i++)
		{
			cin >> from >> to >> weight;
			_matrix[from][to] = weight;
		}
	}
	//打印邻接矩阵
	void PrintMatrix()
	{
		for (int row = 0; row < _vertexnum; row++)
		{
			for (int col = 0; col < _vertexnum; col++)
			{
				if (row == col)cout << 0;
				else if (_matrix[row][col] == INT_MAX)
					cout << -1;
				else {
					cout << _matrix[row][col];
				}
				if (col != _vertexnum - 1)cout << " ";
			}
			if (row != _vertexnum - 1)
				cout << endl;
		}
	}
	void Solve()
	{
		// 使用Floyd-Warshall算法更新邻接矩阵
		for (int k = 0; k < _vertexnum; k++) // 中间顶点
		{
			for (int i = 0; i < _vertexnum; i++) // 起点
			{
				for (int j = 0; j < _vertexnum; j++) // 终点
				{
					// 避免溢出，当_i->k_和_k->j_均可达时更新
					if (_matrix[i][k] != INT_MAX && _matrix[k][j] != INT_MAX)
					{
						_matrix[i][j] = min(_matrix[i][j], _matrix[i][k] + _matrix[k][j]);
					}
				}
			}
		}
	}

	~Graph() {}
};


int main()
{
	int vertexnum, edgenum;
	cin >> vertexnum >> edgenum;
	Graph graph(vertexnum, edgenum);
	graph.CreateGraph();
	graph.Solve();
	graph.PrintMatrix();

	return 0;
}
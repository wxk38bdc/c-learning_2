#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

struct Distance
{
	int value;
	string path;
	bool visit;
	Distance() :value(0), path(""), visit(false) {}
};

class Graph {
private:
	int _vertexnum;//顶点数
	int _edgenum;//边数
	vector<vector<int>> _matrix;//邻接矩阵
	vector<Distance> _distance;//存储最短路径信息
	int _begin;//起点
public:
	//构造函数
	Graph(int vertexnum, int edgenum,int begin = 1)
	{
		_begin = begin;
		_vertexnum = vertexnum;
		_edgenum = edgenum;
		_matrix.resize(vertexnum);
		for (int i = 0; i < vertexnum; i++)
		{
			_matrix[i].resize(vertexnum, INT_MAX);
		}
		_distance.resize(vertexnum);
	}
	void SetBegin(int begin)
	{
		_begin = begin;
	}
	//打印邻接矩阵
	void PrintMatrix()
	{
		cout << "邻接矩阵为：" << endl;
		for (int row = 0; row < _vertexnum; row++)
		{
			for (int col = 0; col < _vertexnum; col++)
			{
				if (_matrix[row][col] == INT_MAX)
					cout << "inf" << " ";
				else {
					//3位对齐宽度
					cout.width(3);
					cout << _matrix[row][col] << " ";
				}
			}
			cout << endl;
		}
	}
	void CreateGraph()
	{
		//cout << "请输入每条边的起点、终点和权值(顶点编号从1开始)：" << endl;
		int from, to, weight;
		for (int i = 0; i < _edgenum; i++)
		{
			cin >> from >> to >> weight;
			if (CheckEdgeValue(from, to, weight))
				_matrix[from - 1][to - 1] = weight;
			else
			{
				cout << "输入的边信息有误，请重新输入！" << endl;
				i--;
			}
		}
	}
	void Dijkstra()
	{
		int begin = _begin;
		for (int i = 0; i < _vertexnum; i++)
		{
			_distance[i].value = _matrix[begin - 1][i];
			_distance[i].path = to_string(begin) + " -> " + to_string(i + 1);
		}
		//设置起点到起点的距离为0，标记为已访问
		_distance[begin - 1].value = 0;
		_distance[begin - 1].visit = true;

		int count = 1;
		while (count < _vertexnum)
		{
			int minIndex = 0; //当前distance数组中距离起点最近的顶点
			int minValue = INT_MAX;//当前distance数组中距离起点最近的顶点的距离
			//找到未访问的顶点中距离起点最近的顶点
			for (int i = 0; i < _vertexnum; i++)
			{
				if (!_distance[i].visit && _distance[i].value < minValue)
				{
					minValue = _distance[i].value;
					minIndex = i;
				}
			}
			_distance[minIndex].visit = true;
			++count;
			//更新distance数组
			for (int i = 0; i < _vertexnum; i++)
			{
				if (!_distance[i].visit && _matrix[minIndex][i] != INT_MAX && _distance[minIndex].value + _matrix[minIndex][i] < _distance[i].value)
				{
					_distance[i].value = _distance[minIndex].value + _matrix[minIndex][i];
					_distance[i].path = _distance[minIndex].path + " -> " + to_string(i + 1);
				}
			}
		}
	}
	void PrintPath()
	{
		int begin = _begin;
		string str = to_string(begin);
		cout << "从顶点" << begin << "到其他顶点的最短路径为：" << endl;
		for (int i = 0; i < _vertexnum; i++)
		{
			if (_distance[i].value != INT_MAX)
				cout << "顶点" << begin << "到顶点" << i + 1 << "的最短路径为：" << _distance[i].path << "，最短距离为：" << _distance[i].value << endl;
			else
				cout << "顶点" << begin << "到顶点" << i + 1 << "不可达" << endl;
		}
	}
	void PrintPath2()
	{
		int begin = _begin;
		int No = 1;
		set<int>noReach;
		set<pair<int, string>>sortedPath;
		for (int i = 0; i < _vertexnum; i++)
		{
			if (i + 1 == begin)
				continue;
			if (_distance[i].value != INT_MAX )
			{
				sortedPath.insert(make_pair(_distance[i].value, _distance[i].path));
			}
			else {
				noReach.insert(i + 1);
			}
		}
		if (!sortedPath.empty())
		{
			for (auto i : sortedPath)
			{
				cout << "No." << No++ << " : ";
				cout << i.second << " , d = " << i.first << endl;
			}
		}
		if (!noReach.empty())
		{
			cout << "No." << No++ << " : ";
			cout << "No Path to ";
			for (auto i : noReach)
			{
				cout << i << " ";
			}
		}
	}
	~Graph() {}
private:
	bool CheckEdgeValue(int from, int to, int weight)
	{
		return from > 0 && from <= _vertexnum && to > 0 && to <= _vertexnum && weight >= 0;
	}
};
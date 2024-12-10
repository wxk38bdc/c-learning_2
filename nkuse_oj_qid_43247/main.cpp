/*
题目描述
给出一个工程中N个阶段的时间消耗和依赖关系，试求出工程的最短时间消耗。

Input Format
输入N  0<N<=20。

随后输入N行数据，每行包含从1起始的阶段编号S、时间消耗T、以及用分号隔开的所依赖的不同阶段编号【如果不依赖其他阶段则此项为空】

Output Format

输出一行，为完成N个阶段的时间消耗。如果依赖关系不为DAG则输出"error"

样例输入输出
样例1
输入:
4
1 3
2 4
3 5 1;2;
4 3 3;
输出:
12
样例2
输入:
4
1 3 3;
2 4
3 5 1;2;
4 3 3;
输出:
error

*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <queue>

using namespace std;

struct point {
	int stage;
	int time;
	vector<int> reliance;
};

void replaceWithSpace(string& s) {
	for (auto& ch : s)
		if (ch == ';')
			ch = ' ';
}

bool topologicalSort(const vector<vector<int>>& matrix, vector<int>& order, int N) {
	vector<int> inDegree(N + 1, 0);
	//初始化入度
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (matrix[i][j]) {
				inDegree[j]++;
			}
		}
	}
	//初始化 将入度为0的点入队列
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		order.push_back(node);

		for (int i = 1; i <= N; i++) {
			if (matrix[node][i]) {
				inDegree[i]--;
				if (inDegree[i] == 0) {
					q.push(i);
				}
			}
		}
	}

	return order.size() == N; // 如果所有节点都被排序，说明是DAG（有向无环图）
}

int main() {
	int N;
	cin >> N;
	getchar();
	vector<point> graph(N + 1);// graph[i]: i==stage
	for (int i = 1; i <= N; i++) {
		int s, t, reliNo;
		string line;
		getline(cin, line);
		replaceWithSpace(line);
		stringstream ss(line);
		ss >> s >> t;
		graph[i].stage = s;
		graph[i].time = t;
		while (ss >> reliNo) {
			graph[i].reliance.push_back(reliNo);
		}
	}

	vector<vector<int>> matrix(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (auto& n : graph[i].reliance) {
			matrix[n][i] = 1; // 表示有一条n->i的边，1<=n,i<=N
		}
	}
	vector<int> order;
	if (!topologicalSort(matrix, order, N)) {
		cout << "error" << endl;
		return 0;
	}

	vector<int> minTime(N + 1, 0);
	for (int node : order) {
		for (int i = 1; i <= N; i++) {
			if (matrix[i][node]) {
				minTime[node] = max(minTime[node], minTime[i]);
			}
		}
		minTime[node] += graph[node].time;
	}

	int totalTime = 0;
	for (int i = 1; i <= N; i++) {
		totalTime = max(totalTime, minTime[i]);
	}

	cout << totalTime << endl;
	return 0;
}

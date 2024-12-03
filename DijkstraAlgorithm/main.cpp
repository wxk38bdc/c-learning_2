#include"Dijkstra.h"

bool CheckVertexAndEdge(int vertexnum, int edgenum)
{
	return vertexnum > 0 && edgenum > 0 && edgenum <= vertexnum * (vertexnum - 1) / 2;//边数不超过最大边数
}

int main()
{
	int vertexnum, edgenum;
	//cout << "请输入顶点数和边数：" << endl;
	cin >> vertexnum >> edgenum;
	while (!CheckVertexAndEdge(vertexnum, edgenum))
	{
		cout << "输入的顶点数和边数有误，请重新输入！" << endl;
		cin >> vertexnum >> edgenum;
	}
	Graph graph(vertexnum, edgenum);
	graph.CreateGraph();
	//graph.PrintMatrix();
	int begin;
	//cout << "请输入起点：" << endl;
	cin >> begin;
	graph.SetBegin(begin);
	graph.Dijkstra();
	graph.PrintPath2();
	return 0;
}
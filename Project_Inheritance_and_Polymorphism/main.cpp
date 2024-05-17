#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class Distance
{
protected:
	int x;
	int y;
public:
	Distance(int _x = 0, int _y = 0) :x(_x), y(_y)
	{}
	virtual int getDistance(Distance d1)
	{
		return 0;
	}
};
class ManhattanDistance :public Distance
{
public:
	ManhattanDistance(int _x = 0, int _y = 0) :Distance(_x, _y)
	{}
	int getDistance(ManhattanDistance m1)
	{
		return abs(x - m1.x) + abs(y - m1.y);
	}
};
class EuclideanDistance :public Distance
{
public:
	EuclideanDistance(int _x = 0, int _y = 0) :Distance(_x, _y)
	{}
	int getDistance(EuclideanDistance e1)
	{
		return pow(x - e1.x, 2) + pow(y - e1.y, 2);
	}
};
int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ManhattanDistance m1(x1, y1), m2(x2, y2);
	EuclideanDistance e1(x1, y1), e2(x2, y2);
	cout << m1.getDistance(m2) << " " << e1.getDistance(e2);
	return 0;
}
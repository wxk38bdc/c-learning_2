#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
	srand(time(nullptr));
	
	// 初始化图形窗口，设置窗口大小和背景颜色
	initgraph(500, 450);
	setbkcolor(WHITE); // 设置背景色为白色
	cleardevice(); // 清除屏幕，刷新背景色
	
	int x, y; // 图形中心坐标
	int distance; // 圆心和图形中心的距离
	int gap; // 相邻圆心之间的度数差
	int r; // 小圆半径
	
	setcolor(BLACK); // 设置文字颜色为黑色
	settextstyle(16, 0, _T("宋体")); // 设置文字样式，注意使用_T宏来确保字符串为宽字符
	outtextxy(30, 30, L"欢迎使用圆形排列程序!"); // 输出提示文本
	
	
	// 输入图形的中心坐标
	outtextxy(30, 60, L"请输入图形中心坐标(x,y)：");
	cin >> x >> y;
	
	// 输入圆心和图形中心的距离
	outtextxy(30, 90, L"请输入小圆心和图形中心的距离：");
	cin >> distance;
	
	// 输入相邻圆心之间的度数差
	outtextxy(30, 120, L"请输入相邻圆心之间的度数差：");
	cin >> gap;
	
	// 输入小圆的半径
	outtextxy(30, 150, L"请输入小圆的半径：");
	cin >> r;
	
	cleardevice(); // 清除屏幕，刷新背景色
	outtextxy(30, 30, L"您画出的图案如下：");
	
	if (gap <= 0 || r <= 0 || distance <= 0) {
		outtextxy(30, 180, L"度数差、半径和距离必须大于0！");
		closegraph();
		return -1;
	}
	
	// 使用精确的pi值
	const double PI = 3.14159265358979323846;
	
	int num = 360 / gap; // 圆的个数
	for (int i = 0; i < num; i++) {
		// 计算每个圆的新中心点坐标
		int circleX = x + distance * cos(i * gap * PI / 180);
		int circleY = y + distance * sin(i * gap * PI / 180);
		
		// 绘制圆，设置圆的颜色，使用渐变色
		int color = RGB(rand() % 255, rand() % 255, rand() % 255); // 设置渐变色
		setcolor(color); // 设置圆的边框颜色
		circle(circleX, circleY, r); // 绘制填充圆
	}
	
	// 等待用户按任意键退出
	system("pause");
	closegraph();
	return 0;
}



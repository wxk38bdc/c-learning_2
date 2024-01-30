#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

#include <graphics.h>
#include <time.h>
#include <conio.h>


void test_rainbow()
{
	// 创建更大的绘图窗口
	initgraph(1024, 768);

	// 画渐变的天空(通过亮度逐渐增加)
	float H = 190;      // 色相
	float S = 1;        // 饱和度
	float L = 0.7f;     // 亮度
	for (int y = 0; y < 768; y++)
	{
		L += 0.0004f;  // 调整亮度增加的速率
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 1023, y);
	}

	// 画彩虹(通过色相逐渐增加)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);      // 设置线宽为 2
	for (int r = 400; r > 344; r--)
	{
		H += 5;
		setlinecolor(HSLtoRGB(H, S, L));
		circle(512, 768, r);  // 调整圆心位置以适应新窗口
	}

	// 在中间打印“再见”
	settextcolor(WHITE);
	settextstyle(200, 0, _T("Consolas"));
	static int i = 0;
	if (i == 0)
	{
		outtextxy(200, 120, _T("欢迎！"));
		i++;
	}
	else
		outtextxy(200, 120, _T("再见！"));

	// 按任意键退出
	//_getch();
	Sleep(1500);//延迟1.5秒
	closegraph();
}

void test()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do {
		Snake snake = { 0 };
		GameStart(&snake);//游戏开始
		GameRun(&snake);//游戏运行
		GameEnd(&snake);//游戏结束
		SetPos(20, 15);
		printf("再来一局吗？(1:是 0:否):");
		scanf("%d", &choice);
	} while (choice);

	SetPos(0, 27);
}
int main()
{
	//修改适配本地中文环境
	setlocale(LC_ALL, "");
	//测试函数
	test_rainbow();
	test();
	test_rainbow();

	return 0;
}



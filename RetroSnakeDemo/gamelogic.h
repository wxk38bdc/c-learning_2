#pragma once
#include <graphics.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <cassert>
using namespace std;

const int ROW = 24;
const int COL = 24;
const int GRAPH_LENGTH = 700;
const int GRAPH_WIDTH = 700;
const int BLOCK_SIZE = 25;
enum Direction {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
};

void drawTable(int col, int row);
void fillBlock(int x, int y, int color = YELLOW);
void drawGameOver();

// 蛇类
class Snake
{
public:
	Snake(const vector<vector<int>>& body) : body(body) {}
	Snake(initializer_list<vector<int>> body) : body(body) {}
	Snake() {}

	void addBody(const vector<int>& newBody)
	{
		if (newBody.size() != 2)
		{
			cerr << "The size of newBody must be 2" << endl;
			assert(false);
		}
		body.push_back(newBody);
	}

	void draw(int color = YELLOW)
	{   //设置背景为白色并刷新
		setbkcolor(WHITE);
		cleardevice();

		//绘制表格
		drawTable(COL, ROW);

		//绘制蛇
		for (int i = 0; i < body.size(); i++)
		{
			if (i == 0)
				fillBlock(body[i][0], body[i][1], RED);
			else
				fillBlock(body[i][0], body[i][1], color);
		}
	}

	//打印蛇身坐标到控制台
	void printBodyCoordinate()
	{
		//格式美观一些
		cout << "body: {";
		for (int i = 0; i < body.size(); i++)
		{
			cout << "{" << body[i][0] << ", " << body[i][1] << "}";
			if (i != body.size() - 1)
				cout << ", ";
		}
		cout << "}" << endl;
	}

	//生成食物
	void generateFood(int color = RED)
	{
		// 生成随机数
		int x = rand() % COL;
		int y = rand() % ROW;

		// 判断食物是否在蛇身上
		for (int i = 0; i < body.size(); i++)
		{
			if (body[i][0] == x && body[i][1] == y)
			{
				generateFood();//递归调用
				return;
			}
		}

		fillBlock(x, y, color);
	}

	//检测键盘输入
	void checkKeyBoard()
	{
		// 检测键盘输入，使用 GetAsyncKeyState 检测按键
		if (GetAsyncKeyState('W') & 0x8000)  // 如果 W 键按下
			currentDir = Direction::UP;
		else if (GetAsyncKeyState('S') & 0x8000)  // 如果 S 键按下
			currentDir = Direction::DOWN;
		else if (GetAsyncKeyState('A') & 0x8000)  // 如果 A 键按下
			currentDir = Direction::LEFT;
		else if (GetAsyncKeyState('D') & 0x8000)  // 如果 D 键按下
			currentDir = Direction::RIGHT;
		else if (GetAsyncKeyState('Q') & 0x8000)  // 如果 Q 键按下，退出游戏
			gameOver = true;
	}

	//与checkKeyBoard()为同一功能，只是checkKeyBoard()更加合理
	void moveSnake() {
		checkKeyBoard();
	}

	//自动移动
	void autoMove()
	{
		vector<int> head = body[0];
		vector<int> newHead = head;
		//添加新的头部
		switch (currentDir)
		{
		case LEFT:
			newHead[0]--;
			break;
		case RIGHT:
			newHead[0]++;
			break;
		case UP:
			newHead[1]--;
			break;
		case DOWN:
			newHead[1]++;
			break;
		default:
			break;
		}
		//把新的头部插入到头部
		body.insert(body.begin(), newHead);
		//删除尾部
		body.pop_back();
		//检测是否撞到自己
		for (int i = 1; i < body.size(); i++)
		{
			if (body[i][0] == newHead[0] && body[i][1] == newHead[1])
			{
				gameOver = true;
				break;
			}
		}
		//检测是否撞到墙
		if (newHead[0] < 0 || newHead[0] >= COL || newHead[1] < 0 || newHead[1] >= ROW)
		{
			gameOver = true;
		}
		//绘制蛇
		draw(GREEN);
	}

	//检测是否游戏结束
	void checkGameOver()
	{
		if (gameOver)
		{
			drawGameOver();
			Sleep(2000);
			closegraph();
			exit(0);
		}
	}
private:
	vector<vector<int>> body;
	bool gameOver = false;
	Direction currentDir = Direction::RIGHT;
};

// 绘制表格
void drawTable(int col, int row)
{
	setlinecolor(BLACK);
	settextstyle(16, 0, _T("Consolas"));
	settextcolor(BLACK);

	// 计算表格起始坐标，使其居中
	int startX = (GRAPH_WIDTH - BLOCK_SIZE * row) / 2;
	int startY = (GRAPH_LENGTH - BLOCK_SIZE * col) / 2;

	// 绘制行
	for (int i = 0; i <= col; i++)
	{
		line(startX, startY + i * BLOCK_SIZE, startX + BLOCK_SIZE * row, startY + i * BLOCK_SIZE); // 绘制水平线

		// 标出行号
		char rowNum[10];
		sprintf(rowNum, "%d", i);

		// 将char数组转换为TCHAR类型
		TCHAR rowNumTCHAR[10];
		mbstowcs(rowNumTCHAR, rowNum, strlen(rowNum) + 1);  // 转换为宽字符

		// 行号显示在左侧
		outtextxy(startX - 20, startY + i * BLOCK_SIZE - 8, rowNumTCHAR);
	}

	// 绘制列
	for (int i = 0; i <= row; i++)
	{
		line(startX + i * BLOCK_SIZE, startY, startX + i * BLOCK_SIZE, startY + BLOCK_SIZE * col); // 绘制竖线

		// 标出列号
		char colNum[10];
		sprintf(colNum, "%d", i);

		// 将char数组转换为TCHAR类型
		TCHAR colNumTCHAR[10];
		mbstowcs(colNumTCHAR, colNum, strlen(colNum) + 1);  // 转换为宽字符

		// 列号显示在上方
		outtextxy(startX + i * BLOCK_SIZE - 5, startY - 20, colNumTCHAR);
	}
}

// 填充方块
void fillBlock(int x, int y, int color)
{
	int startX = (GRAPH_WIDTH - BLOCK_SIZE * COL) / 2;
	int startY = (GRAPH_LENGTH - BLOCK_SIZE * ROW) / 2;
	setfillcolor(color);
	fillrectangle(startX + x * BLOCK_SIZE, startY + y * BLOCK_SIZE, startX + (x + 1) * BLOCK_SIZE, startY + (y + 1) * BLOCK_SIZE);
}

// 绘制游戏结束画面
void drawGameOver()
{
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(64, 0, _T("Consolas"));
	settextcolor(RED);
	outtextxy(200, 300, _T("Game Over!"));
}
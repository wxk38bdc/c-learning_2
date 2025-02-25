#pragma once
#include <graphics.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int ROW = 24;
const int COL = 24;
const int GRAPH_LENGTH = 700;
const int GRAPH_WIDTH = 700;
const int BLOCK_SIZE = 25;

void drawTable(int col, int row);
void fillBlock(int x, int y, int color = YELLOW);

// 蛇类
class Snake 
{
public:
	Snake(const vector<vector<int>>& body) : body(body) {}
	Snake(initializer_list<vector<int>> body) : body(body) {}
	Snake() {}
	void addBody(const vector<int>& newBody)
	{
		body.push_back(newBody);
	}
	void drawSnake(int color = YELLOW)
	{
		for (int i = 0; i < body.size(); i++)
		{
			fillBlock(body[i][0], body[i][1], color);
		}
	}
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
    
private:
    vector<vector<int>> body;
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
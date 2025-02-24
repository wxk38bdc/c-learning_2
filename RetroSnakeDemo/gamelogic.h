#pragma once
#include <graphics.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int ROW = 23;
const int COL = 23;
const int GRAPH_LENGTH = 700;
const int GRAPH_WIDTH = 700;
const int BLOCK_SIZE = 25;

void drawTable(int col, int row)
{
    // 设置线条颜色为黑色
    setlinecolor(BLACK);

    // 计算表格起始坐标，使其居中
    int startX = (GRAPH_WIDTH - BLOCK_SIZE * row) / 2;
    int startY = (GRAPH_LENGTH - BLOCK_SIZE * col) / 2;

    // 绘制行
    for (int i = 0; i <= col; i++)
    {
        line(startX, startY + i * BLOCK_SIZE, startX + BLOCK_SIZE * row, startY + i * BLOCK_SIZE); // 绘制水平线
        // 标出行号
        //...
    }

    // 绘制列
    for (int i = 0; i <= row; i++)
    {
        line(startX + i * BLOCK_SIZE, startY, startX + i * BLOCK_SIZE, startY + BLOCK_SIZE * col); // 绘制竖线
        // 标出列号
		//...
    }
}

void fillBlock(int x, int y, int color = YELLOW)
{
    int startX = (GRAPH_WIDTH - BLOCK_SIZE * COL) / 2;
    int startY = (GRAPH_LENGTH - BLOCK_SIZE * ROW) / 2;
    setfillcolor(color);
    fillrectangle(startX + x * BLOCK_SIZE, startY + y * BLOCK_SIZE, startX + (x + 1) * BLOCK_SIZE, startY + (y + 1) * BLOCK_SIZE);
}

void drawSnake(const vector<vector<int>>& snake, int color = YELLOW)
{
    for (int i = 0; i < snake.size(); i++)
    {
        fillBlock(snake[i][0], snake[i][1], color);
    }
}

void generateFood(const vector<vector<int>>& snake)
{
    // 生成随机数
    int x = rand() % COL;
    int y = rand() % ROW;

    // 判断食物是否在蛇身上
    for (int i = 0; i < snake.size(); i++)
    {
        if (snake[i][0] == x && snake[i][1] == y)
        {
			generateFood(snake);//递归调用
            return;
        }
    }

    fillBlock(x, y, RED);
}
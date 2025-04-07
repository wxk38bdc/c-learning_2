#pragma once

#include <graphics.h>
#include <string>
#include "constants.h"

class Board {
public:
    Board() {
        // 初始化图形窗口
        initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
        cleardevice();
        loadBackground();
    }

    ~Board() {
        closegraph();
    }

    void draw() {
        drawGrid();
        drawCoordinates();
        drawStarPoints();  // 绘制星位点
    }

private:
    void loadBackground() {
        IMAGE background;
        // 加载图片，并调整大小为窗口大小
        loadimage(&background, _T("pictures/background.png"), WINDOW_WIDTH, WINDOW_HEIGHT, true);

        // 绘制图片到窗口，左上角坐标为 (0, 0)
        putimage(0, 0, &background);
    }

    void drawGrid() {
        // 设置内层网格线样式
        setlinecolor(LINE_COLOR);
        setlinestyle(PS_SOLID, BOARD_LINE_WIDTH);

        // 计算棋盘起始位置
        int startX = BOARD_MARGIN;
        int startY = BOARD_MARGIN;
        int endX = BOARD_MARGIN + (BOARD_SIZE - 1) * GRID_SIZE;
        int endY = BOARD_MARGIN + (BOARD_SIZE - 1) * GRID_SIZE;

        // 绘制内层横线
        for (int i = 1; i < BOARD_SIZE - 1; i++) {
            int y = startY + i * GRID_SIZE;
            line(startX, y, endX, y);
        }

        // 绘制内层竖线
        for (int i = 1; i < BOARD_SIZE - 1; i++) {
            int x = startX + i * GRID_SIZE;
            line(x, startY, x, endY);
        }

        // 绘制外层边框（加粗）
        setlinestyle(PS_SOLID, BOARD_LINE_WIDTH * 2);

        // 上边框
        line(startX, startY, endX, startY);
        // 下边框
        line(startX, endY, endX, endY);
        // 左边框
        line(startX, startY, startX, endY);
        // 右边框
        line(endX, startY, endX, endY);
    }

    void drawCoordinates() {
        settextcolor(TEXT_COLOR);
        settextstyle(20, 0, _T("Arial"));
        setbkmode(TRANSPARENT);

        // 绘制顶部数字坐标 (1-15)
        for (int i = 0; i < BOARD_SIZE; i++) {
            int x = BOARD_MARGIN + i * GRID_SIZE - 10;
            int y = BOARD_MARGIN - 30;

            TCHAR numStr[3];
            _stprintf(numStr, _T("%d"), i + 1);
            outtextxy(x, y, numStr);
        }

        // 绘制左侧字母坐标 (A-O)
        for (int i = 0; i < BOARD_SIZE; i++) {
            int x = BOARD_MARGIN - 30;
            int y = BOARD_MARGIN + i * GRID_SIZE - 10;

            TCHAR charStr[2] = { static_cast<TCHAR>('A' + i), 0 };
            outtextxy(x, y, charStr);
        }
    }

    void drawStarPoints() {
        // 星位点半径
        const int STAR_POINT_RADIUS = 5;

        // 设置填充颜色为黑色
        setfillcolor(BLACK);

        // 计算星位点位置（15x15棋盘的标准星位点位置）
        // 四个角星位点（3,3), (3,11), (11,3), (11,11) 和中心点(7,7)
        // 注意：数组索引从0开始，所以实际是(3,3)对应第4行第4列

        // 中心点 (7,7)
        int centerX = BOARD_MARGIN + 7 * GRID_SIZE;
        int centerY = BOARD_MARGIN + 7 * GRID_SIZE;
        fillcircle(centerX, centerY, STAR_POINT_RADIUS);

        // 左上角 (3,3)
        int x1 = BOARD_MARGIN + 3 * GRID_SIZE;
        int y1 = BOARD_MARGIN + 3 * GRID_SIZE;
        fillcircle(x1, y1, STAR_POINT_RADIUS);

        // 右上角 (11,3)
        int x2 = BOARD_MARGIN + 11 * GRID_SIZE;
        int y2 = BOARD_MARGIN + 3 * GRID_SIZE;
        fillcircle(x2, y2, STAR_POINT_RADIUS);

        // 左下角 (3,11)
        int x3 = BOARD_MARGIN + 3 * GRID_SIZE;
        int y3 = BOARD_MARGIN + 11 * GRID_SIZE;
        fillcircle(x3, y3, STAR_POINT_RADIUS);

        // 右下角 (11,11)
        int x4 = BOARD_MARGIN + 11 * GRID_SIZE;
        int y4 = BOARD_MARGIN + 11 * GRID_SIZE;
        fillcircle(x4, y4, STAR_POINT_RADIUS);
    }
};
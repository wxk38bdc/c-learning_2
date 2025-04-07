#pragma once

// 窗口大小
const int WINDOW_WIDTH = 670;
const int WINDOW_HEIGHT = 670;

// 棋盘相关常量
const int BOARD_SIZE = 15;          // 15x15的棋盘
const int GRID_SIZE = 40;           // 每个格子的大小
const int BOARD_MARGIN = 60;        // 棋盘边距
const int BOARD_LINE_WIDTH = 2;     // 棋盘线宽

// 颜色定义
const COLORREF BOARD_COLOR = RGB(210, 180, 140);  // 棋盘颜色
const COLORREF LINE_COLOR = RGB(0, 0, 0);         // 线条颜色
const COLORREF TEXT_COLOR = RGB(0, 0, 0);         // 文字颜色

// 棋子半径（格子大小的40%）
const float PIECE_RADIUS = GRID_SIZE * 0.3f;
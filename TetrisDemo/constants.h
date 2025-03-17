#pragma once

// 定义常量
const int WIDTH = 10;               // 游戏区域的宽度（列数）
const int HEIGHT = 25;              // 游戏区域的高度（行数）
const int CELL_SIZE = 30;           // 每个格子的大小（像素）
const int PREVIEW_WIDTH = 4;        // 预览区域的宽度（列数）
const int PREVIEW_HEIGHT = 4;       // 预览区域的高度（行数）
const int MARGIN = 40;              // 边距
const int GAME_AREA_WIDTH = WIDTH * CELL_SIZE;          // 游戏区域的宽度
const int GAME_AREA_HEIGHT = HEIGHT * CELL_SIZE;        // 游戏区域的高度
const int PREVIEW_AREA_WIDTH = PREVIEW_WIDTH * CELL_SIZE; // 预览区域的宽度
const int SCREEN_WIDTH = GAME_AREA_WIDTH + PREVIEW_AREA_WIDTH + MARGIN * 3; // 窗口的总宽度
const int SCREEN_HEIGHT = GAME_AREA_HEIGHT + MARGIN * 2; // 窗口的总高度


#pragma once

#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include "block_data.h"

class TetrisBlock {
private:
    int type;         // 方块类型（0-6）
    int rotation;     // 当前旋转状态（0-3）
    int x, y;         // 方块的位置（中心坐标）
    COLORREF color;   // 方块颜色

public:
    // 构造函数：支持随机颜色、指定颜色或RGB颜色
    TetrisBlock(int type = 0, int rotation = 0, int x = 0, int y = 0, COLORREF color = -1)
        : type(type), rotation(rotation), x(x), y(y) {
        if (color == -1) {
            // 若不指定颜色，生成随机颜色
            this->color = RGB(rand() % 256, rand() % 256, rand() % 256);
        }
        else {
            // 若指定颜色，使用指定颜色
            this->color = color;
        }
    }

    // 绘制方块
    void Draw(int offsetX, int offsetY) const {
        for (const auto& point : Block[type][rotation]) {
            int px = x + point.first;
            int py = y + point.second;
			if (px < 0 || py < 0) continue; // 超出边界不绘制
            setfillcolor(color);
            solidrectangle(offsetX + px * CELL_SIZE, offsetY + py * CELL_SIZE,
                offsetX + (px + 1) * CELL_SIZE, offsetY + (py + 1) * CELL_SIZE);
        }
    }

    // 获取方块颜色
    COLORREF GetColor() const {
        return color;
    }

    // 设置方块颜色
    void SetColor(COLORREF newColor) {
        color = newColor;
    }

    // 方块下移一格
    void MoveDown() {
        y++;
    }

	// 方块左移一格
	void MoveLeft() {
		x--;
	}

	// 方块右移一格
	void MoveRight() {
		x++;
	}

    // 方块旋转（中心坐标不变）
    void Rotate() {
        rotation = (rotation + 1) % 4; // 旋转到下一个状态
    }

    // 获取方块位置
    int GetX() const { return x; }
    int GetY() const { return y; }

	// 设置方块位置
	void SetX(int newX) { x = newX; }
	void SetY(int newY) { y = newY; }

    // 获取方块类型和旋转状态
    int GetType() const { return type; }
    int GetRotation() const { return rotation; }

};


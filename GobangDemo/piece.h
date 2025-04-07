#pragma once
#include <graphics.h>
#include <string>
#include "constants.h"


void transparentimage(int x, int y, IMAGE img) {
    IMAGE img1;
    DWORD* d1;
    img1 = img;
    d1 = GetImageBuffer(&img1);
    float h, s, l;
    for (int i = 0; i < img1.getheight() * img1.getwidth(); i++) {
        RGBtoHSL(BGR(d1[i]), &h, &s, &l);
        if (l < 0.03) {
            d1[i] = BGR(WHITE);
        }
        if (d1[i] != BGR(WHITE)) {
            d1[i] = 0;
        }
    }
    putimage(x, y, &img1, SRCAND);
    putimage(x, y, &img, SRCPAINT);
}

class Piece {
private:
    static IMAGE blackPieceImg;
    static IMAGE whitePieceImg;
    static bool imagesLoaded;

public:
    // 棋子类型枚举
    enum Type {
        PIECE_NONE = 0,
        PIECE_BLACK = 1,
        PIECE_WHITE = 2
    };

    // 初始化贴图资源
    static void initImages() {
        if (!imagesLoaded) {
            // 计算棋子显示大小（格子大小的80%）
            int pieceSize = static_cast<int>(GRID_SIZE * 0.8);

            // 加载并缩放棋子图片
            loadimage(&blackPieceImg, _T("pictures/blackpiece.png"), pieceSize, pieceSize, true);
            loadimage(&whitePieceImg, _T("pictures/whitepiece.png"), pieceSize, pieceSize, true);

            imagesLoaded = true;
        }
    }

    // 绘制棋子
    static void draw(int row, int col, Type type) {
        if (!imagesLoaded) initImages();

        // 计算棋子在屏幕上的位置（居中显示）
        int x = BOARD_MARGIN + col * GRID_SIZE - blackPieceImg.getwidth() / 2;
        int y = BOARD_MARGIN + row * GRID_SIZE - blackPieceImg.getheight() / 2;

        // 绘制对应棋子
        switch (type) {
        case PIECE_BLACK:
			transparentimage(x, y, blackPieceImg);
            break;
        case PIECE_WHITE:
            transparentimage(x, y, whitePieceImg);
            break;
        default:
            break;
        }
    }

};
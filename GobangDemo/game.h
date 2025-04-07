#pragma once
#include "board.h"
#include "piece.h"
#include <vector>
#include <iostream>

class Game {
private:
    Board board;
    std::vector<std::vector<Piece::Type>> boardState;
    Piece::Type currentPlayer;

public:
    Game() : currentPlayer(Piece::PIECE_WHITE) {
        boardState.resize(BOARD_SIZE, std::vector<Piece::Type>(BOARD_SIZE, Piece::PIECE_NONE));
        Piece::initImages();
        board.draw();
    }

    // 将屏幕坐标转换为棋盘行列
    bool screenToBoard(int screenX, int screenY, int& row, int& col) const {
        col = static_cast<int>((screenX - BOARD_MARGIN + GRID_SIZE / 2) / GRID_SIZE);
        row = static_cast<int>((screenY - BOARD_MARGIN + GRID_SIZE / 2) / GRID_SIZE);
        return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
    }

    // 处理鼠标点击
    void handleMouseClick(int x, int y) {
        int row, col;
        if (screenToBoard(x, y, row, col)) {
            placePiece(row, col);
        }
    }

    // 获取当前玩家
    Piece::Type getCurrentPlayer() const {
        return currentPlayer;
    }

    // 切换玩家
    void switchPlayer() {
        currentPlayer = (currentPlayer == Piece::PIECE_WHITE) ?
            Piece::PIECE_BLACK : Piece::PIECE_WHITE;
    }

    // 判断位置是否为空
    bool isEmpty(int row, int col) const {
        return (row >= 0 && row < BOARD_SIZE &&
            col >= 0 && col < BOARD_SIZE &&
            boardState[row][col] == Piece::PIECE_NONE);
    }

    // 落子
    void placePiece(int row, int col) {
        if (isEmpty(row, col)) {
            boardState[row][col] = currentPlayer;
            Piece::draw(row, col, currentPlayer);

            // 输出落子信息
            std::cout << "落子位置: " << (char)('A' + row) << col + 1
                << " 玩家: " << (currentPlayer == Piece::PIECE_WHITE ? "白" : "黑")
                << std::endl;

            switchPlayer();
        }
    }
};
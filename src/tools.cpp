// Copyright 2023 PY Inc.
// Author: YaoHuizai PingShilong

#include "tools.h"
#include "config.h"

bool isRowValid(const std::vector<std::vector<int>> &grid, int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isColValid(const std::vector<std::vector<int>> &grid, int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isBoxValid(const std::vector<std::vector<int>> &grid,
                int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(const std::vector<std::vector<int>> &grid,
             int row, int col, int num) {
    return isRowValid(grid, row, num) && isColValid(grid, col, num) &&
           isBoxValid(grid, row - row % 3, col - col % 3, num);
}

bool isEmpty(const std::vector<std::vector<int>> &grid, int *row, int *col) {
    for ((*row) = 0; (*row) < SIZE; (*row)++) {
        for ((*col) = 0; (*col) < SIZE; (*col)++) {
            if (grid[*row][*col] == 0)
                return true;
        }
    }
    return false;
}

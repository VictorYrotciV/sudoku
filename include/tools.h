// Copyright 2023 PY Inc.
// Author: YaoHuizai PingShilong

#ifndef SUDOKU_INCLUDE_TOOLS_H_
#define SUDOKU_INCLUDE_TOOLS_H_

#include <vector>


bool isRowValid(const std::vector<std::vector<int>> &grid, int row, int num);

bool isColValid(const std::vector<std::vector<int>> &grid, int col, int num);

bool isBoxValid(const std::vector<std::vector<int>> &grid,
                int startRow, int startCol, int num);

bool isValid(const std::vector<std::vector<int>> &grid,
             int row, int col, int num);

bool isEmpty(const std::vector<std::vector<int>> &grid, int *row, int *col);

#endif  // SUDOKU_INCLUDE_TOOLS_H_

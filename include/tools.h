#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include "config.h"


bool isRowValid(const std::vector<std::vector<int>> &grid, int row, int num);

bool isColValid(const std::vector<std::vector<int>> &grid, int col, int num);

bool isBoxValid(const std::vector<std::vector<int>> &grid, int startRow, int startCol, int num);

bool isValid(const std::vector<std::vector<int>> &grid, int row, int col, int num);

bool isEmpty(const std::vector<std::vector<int>> &grid, int &row, int &col);

#endif


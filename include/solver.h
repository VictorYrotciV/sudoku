#ifndef SOLVE_H
#define SOLVE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>
#include <string>
#include "config.h"


bool solveSudoku(std::vector<std::vector<int>> &grid, std::function<void()> handleSolution);

bool findEmptyLocation(const std::vector<std::vector<int>> &grid, int &row, int &col);

bool isSafe(const std::vector<std::vector<int>> &grid, int row, int col, int num);

int countSolutionsForSingleGame(const std::vector<std::vector<int>> &grid);

void solveSudokuFromFile(const std::string &in_file, const std::string &out_file);


#endif
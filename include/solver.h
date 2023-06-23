#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>
#include <string>
#include "config.h"
#include "tools.h"


bool solveSudoku(std::vector<std::vector<int>> &grid, std::function<void()> handleSolution);

int countSolutionsForSingleGame(const std::vector<std::vector<int>> &grid);

void solveSudokuFromFile(const std::string &in_file, const std::string &out_file);


#endif
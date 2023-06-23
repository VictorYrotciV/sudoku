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


bool solveSudokuCount(std::vector<std::vector<int>> &grid, int &solutionCount);

bool solveSudokuStep(std::vector<std::vector<int>> &grid, int &step, int &solutionCount);

bool solveSudokuSave(std::vector<std::vector<int>> &grid, std::ofstream &outFile);

void solveFileSudoku(const std::string &in_file, const std::string &out_file);


#endif
// Copyright [2023] <PingShilong YaoHuizai>
#ifndef SUDOKU_INCLUDE_SOLVER_H_
#define SUDOKU_INCLUDE_SOLVER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>
#include <string>


bool solveSudokuCount(std::vector<std::vector<int>> *grid, int *solutionCount);

bool solveSudokuStep(std::vector<std::vector<int>> *grid,
                     int *step, int *solutionCount);

bool solveSudokuSave(std::vector<std::vector<int>> *grid,
                     std::ofstream *outFile);

void solveFileSudoku(const std::string &in_file, const std::string &out_file);


#endif  // SUDOKU_INCLUDE_SOLVER_H_"

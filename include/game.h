// Copyright [2023] <PingShilong YaoHuizai>
#ifndef SUDOKU_INCLUDE_GAME_H_
#define SUDOKU_INCLUDE_GAME_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include "solver.h"
#include "config.h"
#include "tools.h"

bool fillBoard(std::vector<std::vector<int>> &grid, int row, int col);

bool isInLevel(int step, int solutionCount, int r, int level);

std::vector<std::vector<int>> genFinalBoard();

std::vector<std::vector<int>> genGameBoard(int r, int level);

std::vector<std::vector<int>> genOneSoluGameBoard(int r, int level);

void printBoard(const std::vector<std::vector<int>> &grid);

void saveBoard(const std::vector<std::vector<std::vector<int>>> &games,
               const std::string &file_path);

void genAndSaveFinalBoards(int n, const std::string &file_path);

void genAndSaveGameBoards(int n, int r_lower, int r_upper, int level,
                          const std::string &file_path);

void genAndSaveOneSoluGameBoards(int n, int r_lower, int r_upper, int level,
                                 const std::string &file_path);

#endif  // SUDOKU_INCLUDE_GAME_H_

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include "solver.h"
#include "config.h"
#include "tools.h"

bool fillBoard(std::vector<std::vector<int>> &grid, int row, int col);

std::vector<std::vector<int>> genFinalBoard();

std::vector<std::vector<int>> genGameBoard(int r, int level);

void printBoard(const std::vector<std::vector<int>> &grid);

void saveBoard(const std::vector<std::vector<std::vector<int>>> &games, const std::string &file_path);

void genAndSaveFinalBoards(int n, const std::string &file_path);

void genAndSaveGameBoards(int n, int r_lower, int r_upper, int level, const std::string &file_path);

#endif
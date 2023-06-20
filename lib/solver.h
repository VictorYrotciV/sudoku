#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

#include "macro.h"


bool solveSudoku(std::vector<std::vector<int>>& grid, std::function<void()> handleSolution);
bool findEmptyLocation(const std::vector<std::vector<int>>& grid, int& row, int& col);
bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num);
int solveSudokuAndPrintAllSolutions(const std::vector<std::vector<int>>& grid, const std::string& file_path);

bool solveSudoku(std::vector<std::vector<int>>& grid, std::function<void()> handleSolution) {
    int row, col;
    if (!findEmptyLocation(grid, row, col)) {
        // 找到了一个解
        handleSolution();
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, handleSolution))
                return true;

            grid[row][col] = 0; // 回溯，将当前位置重置为0
        }
    }

    return false;
}

bool findEmptyLocation(const std::vector<std::vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // 检查行是否安全
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num)
            return false;
    }

    // 检查列是否安全
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num)
            return false;
    }

    // 检查3x3方格是否安全
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}


int solveSudokuAndPrintAllSolutions(const std::vector<std::vector<int>>& grid, const std::string& file_path) {
    std::ofstream file(file_path);
    if (!file.is_open()) {
        std::cout << "Failed to open the file: " << file_path << std::endl;
        return 0;
    }

    int solutionCount = 0;
    std::vector<std::vector<int>> copyGrid = grid; // 复制数独游戏

    // 定义一个回调函数来处理每个解
    std::function<void()> handleSolution = [&]() {
        solutionCount++;
        file << "Solution " << solutionCount << ":\n";
        for (const auto& row : copyGrid) {
            for (int num : row) {
                file << num << " ";
            }
            file << "\n";
        }
        file << "\n";
    };

    // 调用 solveSudoku 函数来解决数独游戏，并在回调函数中处理每个解
    solveSudoku(copyGrid, handleSolution);

    file.close();

    return solutionCount;
}









#endif

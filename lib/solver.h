#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

#include "macro.h"


bool solveSudoku(std::vector<std::vector<int>>& grid, std::function<void()> handleSolution);
bool findEmptyLocation(const std::vector<std::vector<int>>& grid, int& row, int& col);
bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num);
int solveSudokuAndPrintAllSolutions(const std::vector<std::vector<int>>& grid, const std::string& file_path);

bool solveSudoku(std::vector<std::vector<int>>& grid, std::function<void()> handleSolution)
{
    int row, col;
    if (!findEmptyLocation(grid, row, col))
    {
        // �ҵ���һ����
        handleSolution();
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid, handleSolution))
                return true;

            grid[row][col] = 0; // ���ݣ�����ǰλ������Ϊ0
        }
    }

    return false;
}

bool findEmptyLocation(const std::vector<std::vector<int>>& grid, int& row, int& col)
{
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num)
{
    // ������Ƿ�ȫ
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[row][i] == num)
            return false;
    }

    // ������Ƿ�ȫ
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[i][col] == num)
            return false;
    }

    // ���3x3�����Ƿ�ȫ
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}


int solveSudokuAndPrintAllSolutions(const std::vector<std::vector<int>>& grid, const std::string& file_path)
{
    std::ofstream file(file_path);
    if (!file.is_open())
    {
        std::cout << "Failed to open the file: " << file_path << std::endl;
        return 0;
    }

    int solutionCount = 0;
    std::vector<std::vector<int>> copyGrid = grid; // ����������Ϸ

    // ����һ���ص�����������ÿ����
    std::function<void()> handleSolution = [&]()
    {
        solutionCount++;
        file << "Solution " << solutionCount << ":\n";
        for (const auto& row : copyGrid) {
            for (int num : row)
            {
                file << num << " ";
            }
            file << "\n";
        }
        file << "\n";
    };

    // ���� solveSudoku ���������������Ϸ�����ڻص������д���ÿ����
    solveSudoku(copyGrid, handleSolution);

    file.close();

    return solutionCount;
}

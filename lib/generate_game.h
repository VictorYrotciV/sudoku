#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "macro.h"
#include "solver.h"

bool isRowValid(const std::vector<std::vector<int>>& grid, int row, int num);
bool isColValid(const std::vector<std::vector<int>>& grid, int col, int num);
bool isBoxValid(const std::vector<std::vector<int>>& grid, int startRow, int startCol, int num);
bool isValid(const std::vector<std::vector<int>>& grid, int row, int col, int num);
bool fillNumber(std::vector<std::vector<int>>& grid, int row, int col);
std::vector<std::vector<int>> generateSudokuFinalBoard();
std::vector<std::vector<int>> generateSudokuGameBoard(int r);
std::vector<std::vector<int>> generateSudokuSolutionOnlyGameBoard(int r);

// 检查数字在指定行是否重复
bool isRowValid(const std::vector<std::vector<int>>& grid, int row, int num)
{
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[row][col] == num)
        {
            return false;
        }
    }
    return true;
}

// 检查数字在指定列是否重复
bool isColValid(const std::vector<std::vector<int>>& grid, int col, int num)
{
    for (int row = 0; row < SIZE; row++)
    {
        if (grid[row][col] == num)
        {
            return false;
        }
    }
    return true;
}

// 检查数字在指定的小方块是否重复
bool isBoxValid(const std::vector<std::vector<int>>& grid, int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + startRow][col + startCol] == num)
            {
                return false;
            }
        }
    }
    return true;
}

// 检查数字在指定位置是否满足数独规则
bool isValid(const std::vector<std::vector<int>>& grid, int row, int col, int num)
{
    return isRowValid(grid, row, num) && isColValid(grid, col, num) && isBoxValid(grid, row - row % 3, col - col % 3, num);
}

// 在指定位置填充数字
bool fillNumber(std::vector<std::vector<int>>& grid, int row, int col)
{
    // 数独已填满，返回 true 表示成功生成终盘
    if (row == SIZE)
    {
        return true;
    }

    // 列遍历完成，转到下一行
    if (col == SIZE)
    {
        return fillNumber(grid, row + 1, 0);
    }

    // 如果当前位置已经有数字，跳到下一列
    if (grid[row][col] != 0)
    {
        return fillNumber(grid, row, col + 1);
    }

    // 随机生成 1-9 的数字序列
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(nums.begin(), nums.end(), rng);

    // 尝试在当前位置填入符合规则的数字
    for (int num : nums)
    {
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;
            if (fillNumber(grid, row, col + 1))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

// 生成数独终盘
std::vector<std::vector<int>> generateSudokuFinalBoard()
{
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));

    // 填充数独
    fillNumber(grid, 0, 0);

    return grid;
}

//挖空法生成数独游戏
std::vector<std::vector<int>> generateSudokuGameBoard(int r)
{
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));

    // 填充数独
    fillNumber(grid, 0, 0);

    // 挖空指定数量的数字
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, SIZE - 1);

    int count = 0;
    while (count < r)
    {
        int row = distribution(rng);
        int col = distribution(rng);

        if (grid[row][col] != 0)
        {
            grid[row][col] = 0;
            count++;
        }
    }

    return grid;
}

std::vector<std::vector<int>> generateSudokuSolutionOnlyGameBoard(int r)
{
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));

    // 填充数独
    fillNumber(grid, 0, 0);

    // 挖空指定数量的数字
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, SIZE - 1);

    int count = 0;
    int maxAttempts = r * 10; // 设置最大尝试次数
    int attempts = 0;

    while (count < r)
    {
        int row = distribution(rng);
        int col = distribution(rng);

        if (grid[row][col] != 0)
        {
            int temp = grid[row][col];
            grid[row][col] = 0;
            count++;

            // 验证解的唯一性
            std::vector<std::vector<int>> copyGrid = grid;
            int solutionCount = 0;

            solveSudoku(copyGrid, [&]()
            {
                solutionCount++;
            });

            if (solutionCount != 1)
            {
                // 如果有多于一个解，则恢复原来的数字
                grid[row][col] = temp;
                count--;
            }

            attempts++;

            if (attempts >= maxAttempts)
            {
                // 尝试次数超过阈值，返回当前数独游戏并打印警告
                std::cout << "未能生成挖空 " << r << " 个数的解唯一的数独游戏。当前挖空数量：" << count << std::endl;
                return grid;
            }
        }
    }

    return grid;
}



// 打印数独
void printSudokuBoard(const std::vector<std::vector<int>>& grid)
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}
#include "solver.h"

bool solveSudoku(std::vector<std::vector<int>> &grid, std::function<void()> handleSolution) {
    int row, col;
    if (!findEmptyLocation(grid, row, col)) {
        handleSolution();
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, handleSolution)) {
                grid[row][col] = 0;  // Backtrack to find other solutions
            } else {
                grid[row][col] = 0;
            }
        }
    }

    return false;
}

bool findEmptyLocation(const std::vector<std::vector<int>> &grid, int &row, int &col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafe(const std::vector<std::vector<int>> &grid, int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num)
            return false;
    }

    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num)
            return false;
    }

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

int countSolutionsForSingleGame(const std::vector<std::vector<int>> &grid) {
    int solutionCount = 0;
    std::vector<std::vector<int>> copyGrid = grid;

    std::function<void()> handleSolution = [&]() {
        solutionCount++;
    };

    solveSudoku(copyGrid, handleSolution);

    return solutionCount;
}

void solveSudokuFromFile(const std::string &in_file, const std::string &out_file) {
    std::ifstream file(in_file);
    if (!file.is_open()) {
        std::cout << "Failed to open the input file: " << in_file << std::endl;
        return;
    }

    std::ofstream outFile(out_file);
    if (!outFile.is_open()) {
        std::cout << "Failed to open the output file: " << out_file << std::endl;
        file.close();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;  // Skip empty lines
        }

        std::vector<std::vector<int>> sudokuGrid;
        std::stringstream ss(line);

        int num;
        while (ss >> num) {
            sudokuGrid.push_back({num});
        }

        if (sudokuGrid.size() != SIZE) {
            std::cout << "Invalid input: Each Sudoku game should have " << SIZE << " rows." << std::endl;
            continue;
        }

        for (int i = 1; i < SIZE; i++) {
            std::getline(file, line);
            if (line.empty()) {
                std::cout << "Invalid input: Incomplete Sudoku game." << std::endl;
                break;
            }
            std::stringstream ss(line);

            for (int j = 0; j < SIZE; j++) {
                ss >> num;
                sudokuGrid[j].push_back(num);
            }
        }

        int solutionCount = countSolutionsForSingleGame(sudokuGrid);
        outFile << "Number of solutions: " << solutionCount << std::endl;

        if (solutionCount > 0) {
            std::vector<std::vector<int>> copyGrid = sudokuGrid;

            std::function<void()> handleSolution = [&]() {
                for (const auto &row: copyGrid) {
                    for (int num: row) {
                        outFile << num << " ";
                    }
                    outFile << std::endl;
                }
                outFile << std::endl;
            };

            solveSudoku(copyGrid, handleSolution);
        }
    }

    file.close();
    outFile.close();
}
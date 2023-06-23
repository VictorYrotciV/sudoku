#include "solver.h"

bool solveSudokuCount(std::vector<std::vector<int>> &grid, int &solutionCount) {
    int row, col;
    if (!isEmpty(grid, row, col)) {
        solutionCount++;
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            solveSudokuCount(grid, solutionCount);
            grid[row][col] = 0;
        }
    }

    return false;
}

bool solveSudokuStep(std::vector<std::vector<int>> &grid, int &step, int &solutionCount) {
    int row, col;
    if (!isEmpty(grid, row, col)) {
        solutionCount++;
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            step++;
            grid[row][col] = num;
            solveSudokuStep(grid, step, solutionCount);
            grid[row][col] = 0;
        }
    }

    return false;
}

bool solveSudokuSave(std::vector<std::vector<int>> &grid, std::ofstream &outFile) {
    int row, col;
    if (!isEmpty(grid, row, col)) {
        for (const auto &row: grid) {
            for (int num: row) {
                outFile << num << " ";
            }
            outFile << std::endl;
        }
        outFile << std::endl;
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            solveSudokuSave(grid, outFile);
            grid[row][col] = 0;
        }
    }

    return false;
}

void solveFileSudoku(const std::string &in_file, const std::string &out_file) {
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
        int solutionCount = 0;
        solveSudokuCount(sudokuGrid, solutionCount);
        outFile << "Number of solutions: " << solutionCount << std::endl;

        if (solutionCount > 0) {
            std::vector<std::vector<int>> copyGrid = sudokuGrid;
            solveSudokuSave(copyGrid, outFile);
        }
    }

    file.close();
    outFile.close();
}
#include "solver.h"
#include "config.h"
#include "tools.h"
#include "string.h"


bool solveSudokuCount(std::vector<std::vector<int>> *grid, int *solutionCount) {
    int row, col;
    if (!isEmpty(*grid, &row, &col)) {
        (*solutionCount)++;
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(*grid, row, col, num)) {
            (*grid)[row][col] = num;
            solveSudokuCount(grid, solutionCount);
            (*grid)[row][col] = 0;
        }
    }

    return false;
}

bool solveSudokuStep(std::vector<std::vector<int>> *grid,
                     int *step, int *solutionCount) {
    int row, col;
    if (!isEmpty(*grid, &row, &col)) {
        (*solutionCount)++;
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(*grid, row, col, num)) {
            (*step)++;
            (*grid)[row][col] = num;
            solveSudokuStep(grid, step, solutionCount);
            (*grid)[row][col] = 0;
        }
    }

    return false;
}

bool solveSudokuSave(std::vector<std::vector<int>> *grid,
                     std::ofstream *outFile) {
    int row, col;
    if (!isEmpty(*grid, &row, &col)) {
        for (const auto &one_row: *grid) {
            for (int num: one_row) {
                (*outFile) << num << " ";
            }
            (*outFile) << std::endl;
        }
        (*outFile) << std::endl;
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(*grid, row, col, num)) {
            (*grid)[row][col] = num;
            solveSudokuSave(grid, outFile);
            (*grid)[row][col] = 0;
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
        std::cout << "Failed to open the output file: "
                  << out_file << std::endl;
        file.close();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;  // Skip empty lines
        }

        std::vector<std::vector<int>> sudokuGrid;
        std::vector<int> test_one_row;
        char *test_token = NULL;
        char *test_ptr = NULL;
        char *test_str = const_cast<char *>(line.c_str());
        test_token = strtok_s(test_str, " ", &test_ptr);
        while (test_token != NULL) {
            if (!strcmp(test_token, "$")) {
                test_one_row.push_back(0);
            } else {
                test_one_row.push_back(atoi(test_token));
            }
            test_token = strtok_s(NULL, " ", &test_ptr);
        }

        if (test_one_row.size() != SIZE) {
            std::cout << "Invalid input: Each Sudoku game should have " << SIZE
                      << " cols." << std::endl;
            continue;
        }
        sudokuGrid.push_back(test_one_row);
        for (int i = 1; i < SIZE; i++) {
            std::getline(file, line);
            if (line.empty()) {
                std::cout << "Invalid input: Incomplete Sudoku game."
                          << std::endl;
                break;
            }
            char *token = NULL;
            char *ptr = NULL;
            char *str = const_cast<char *>(line.c_str());
            std::vector<int> one_row;
            token = strtok_s(str, " ", &ptr);
            for (int j = 0; j < SIZE; j++) {
                if (!strcmp(token, "$")) {
                    one_row.push_back(0);
                } else {
                    one_row.push_back(atoi(token));
                }
                token = strtok_s(NULL, " ", &ptr);
            }
            sudokuGrid.push_back(one_row);
        }

        int solutionCount = 0;
        std::vector<std::vector<int>> copyGrid(sudokuGrid);
        solveSudokuCount(&copyGrid, &solutionCount);
        outFile << "Number of solutions: " << solutionCount << std::endl;

        if (solutionCount > 0) {
            std::vector<std::vector<int>> saveGrid(sudokuGrid);
            solveSudokuSave(&saveGrid, &outFile);
        }
    }

    file.close();
    outFile.close();
}

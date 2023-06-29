// Copyright 2023 PY Inc.
// Author: YaoHuizai PingShilong

#include <string.h>
#include "../include/game.h."
#include "../include/solver.h"
#include "../include/tools.h"
#include "../include/config.h"


bool fillBoard(std::vector<std::vector<int>> *grid, int row, int col) {
    if (row == SIZE) {
        return true;
    }

    if (col == SIZE) {
        return fillBoard(grid, row + 1, 0);
    }

    if ((*grid)[row][col] != 0) {
        return fillBoard(grid, row, col + 1);
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(nums.begin(), nums.end(), rng);

    for (int num: nums) {
        if (isValid((*grid), row, col, num)) {
            (*grid)[row][col] = num;
            if (fillBoard(grid, row, col + 1)) {
                return true;
            }
            (*grid)[row][col] = 0;
        }
    }

    return false;
}

bool isInLevel(int step, int solutionCount, int r, int level) {
    /*
     * step/solutionCount < 2*r : level1
     * 2*r <= step/solutionCount < 5*r : level2
     * 5*r <= step/solutionCount : level3
     */
    bool result = false;
    switch (level) {
        case 1: {
            if (step / solutionCount < 2 * static_cast<float>(r)) {
                result = true;
            }
            break;
        }
        case 2: {
            if (step / solutionCount >= 2 * static_cast<float>(r)
                && step / solutionCount < 5 * static_cast<float>(r)) {
                result = true;
            }
            break;
        }
        case 3: {
            if (step / solutionCount >= 5 * static_cast<float>(r)) {
                result = true;
            }
            break;
        }
    }
    return result;
}

std::vector<std::vector<int>> genFinalBoard() {
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));
    fillBoard(&grid, 0, 0);
    return grid;
}

std::vector<std::vector<int>> genGameBoard(
        const std::vector<std::vector<int>> &final_board,
        int r, int level) {
    int max_try_num = r * DEFAULT_MAX_TRY_NUM, try_num = 0;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, SIZE - 1);

    while (1) {
        std::vector<std::vector<int>> grid(final_board);
        int count = 0;
        while (count < r) {
            int row = distribution(rng);
            int col = distribution(rng);
            if (grid[row][col] != 0) {
                grid[row][col] = 0;
                count++;
            }
        }
        try_num++;
        int step = 0, solutionCount = 0;
        std::vector<std::vector<int>> copyGrid(grid);
        solveSudokuStep(&copyGrid, &step, &solutionCount);
        if (isInLevel(step, solutionCount, r, level)) {
            return grid;
        }
        if (try_num >= max_try_num) {
            std::cout << "failed in genGameBoard" << std::endl;
            break;
        }
    }
    return {};
}

void saveBoard(const std::vector<std::vector<std::vector<int>>> &games,
               const std::string &file_path) {
    std::ofstream file(file_path);
    if (!file) {
        std::cerr << "file error" << file_path << std::endl;
        return;
    }
    for (const auto &game: games) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (game[row][col] == 0)
                    file << "$" << " ";
                else
                    file << game[row][col] << " ";
            }
            file << std::endl;
        }
        file << std::endl;
    }
    file.close();
}

std::vector<std::vector<std::vector<int>>> loadBoard(const std::string &file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return {};
    }
    std::vector<std::vector<std::vector<int>>> boards;
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
        boards.push_back(sudokuGrid);
    }
    file.close();
    return boards;
}

void genAndSaveFinalBoards(int n, const std::string &file_path) {
    std::vector<std::vector<std::vector<int>>> sudoku_final_boards;
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> sudoku = genFinalBoard();
        sudoku_final_boards.push_back(sudoku);
    }
    saveBoard(sudoku_final_boards, file_path);
}

void genAndSaveGameBoards(int n, int r_lower, int r_upper, int level,
                          const std::string &final_file_path,
                          const std::string &game_file_path) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower, r_upper);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(final_file_path);
    int index=0;
    for (int i = 0; i < n; i++) {
        int r = distribution(rng);
        std::vector<std::vector<int>> sudoku = genGameBoard(final_boards[index], r, level);
        index = (++index) % final_boards.size();
        sudoku_games.push_back(sudoku);
    }
    saveBoard(sudoku_games, game_file_path);
}

void genAndSaveOneSoluGameBoards(int n, int r_lower, int r_upper, int level,
                                 const std::string &final_file_path,
                                 const std::string &game_file_path) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower, r_upper);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(final_file_path);
    int index = 0;
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> sudoku;
        int r, try_num = 0;
        while (1) {
            r = distribution(rng);
            sudoku = genGameBoard(final_boards[index], r, level);
            index = (++index) % final_boards.size();
            try_num++;
            int solucount = 0;
            std::vector<std::vector<int>> copyGrid(sudoku);
            solveSudokuCount(&copyGrid, &solucount);
            if (solucount == 1) {
                break;
            }
            if (try_num >= r * DEFAULT_MAX_TRY_NUM) {
                std::cout << "failed in genOneSoluGameBoard" << std::endl;
                break;
            }
        }
        sudoku_games.push_back(sudoku);
    }
    saveBoard(sudoku_games, game_file_path);
}

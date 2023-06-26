#include "game.h"

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

std::vector<std::vector<int>> genGameBoard(int r, int level) {
    int max_try_num = r * DEFAULT_MAX_TRY_NUM, try_num = 0;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, SIZE - 1);

    while (1) {
        std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));
        fillBoard(&grid, 0, 0);

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

std::vector<std::vector<int>> genOneSoluGameBoard(int r, int level) {
    int max_try_num = r * DEFAULT_MAX_TRY_NUM, try_num = 0;
    while (1) {
        std::vector<std::vector<int>> sudoku = genGameBoard(r, level);
        try_num++;
        int solucount = 0;
        std::vector<std::vector<int>> copyGrid(sudoku);
        solveSudokuCount(&copyGrid, &solucount);
        if (solucount == 1) {
            return sudoku;
        }
        if (try_num >= max_try_num) {
            std::cout << "failed in genOneSoluGameBoard" << std::endl;
            break;
        }
    }
    return {};
}

void printBoard(const std::vector<std::vector<int>> &grid) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                std::cout << "$" << " ";
            } else {
                std::cout << grid[row][col] << " ";
            }
        }
        std::cout << std::endl;
    }
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
    std::cout << "save" << file_path << std::endl;
}

void genAndSaveFinalBoards(int n, const std::string &file_path) {
    std::vector<std::vector<std::vector<int>>> sudoku_final_boards;
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> sudoku = genFinalBoard();
        sudoku_final_boards.push_back(sudoku);
    }
    saveBoard(sudoku_final_boards, file_path);
}

void genAndSaveGameBoards(int n, int r_lower, int r_upper,
                          int level, const std::string &file_path) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower, r_upper);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    for (int i = 0; i < n; i++) {
        int r = distribution(rng);
        std::vector<std::vector<int>> sudoku = genGameBoard(r, level);
        sudoku_games.push_back(sudoku);
    }
    saveBoard(sudoku_games, file_path);
}

void genAndSaveOneSoluGameBoards(int n, int r_lower, int r_upper,
                                 int level, const std::string &file_path) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower, r_upper);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    for (int i = 0; i < n; i++) {
        int r = distribution(rng);
        std::vector<std::vector<int>> sudoku = genOneSoluGameBoard(r, level);
        sudoku_games.push_back(sudoku);
    }
    saveBoard(sudoku_games, file_path);
}

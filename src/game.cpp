#include "game.h"

bool fillBoard(std::vector<std::vector<int>> &grid, int row, int col) {
    if (row == SIZE) {
        return true;
    }

    if (col == SIZE) {
        return fillBoard(grid, row + 1, 0);
    }

    if (grid[row][col] != 0) {
        return fillBoard(grid, row, col + 1);
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(nums.begin(), nums.end(), rng);

    for (int num: nums) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (fillBoard(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

std::vector<std::vector<int>> genFinalBoard() {
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));
    fillBoard(grid, 0, 0);
    return grid;
}

std::vector<std::vector<int>> genGameBoard(int r, int level) {
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));
    fillBoard(grid, 0, 0);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, SIZE - 1);
    int count = 0;
    while (count < r) {
        int row = distribution(rng);
        int col = distribution(rng);
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            count++;
        }
    }
    return grid;
}

std::vector<std::vector<int>> genOneSoluGameBoard(int r, int level) {
    int max_try_num = r * 10, try_num = 0;
    while (1) {
        std::vector<std::vector<int>> sudoku = genGameBoard(r, level);
        try_num++;
        int solucount = 0;
        solveSudokuCount(sudoku, solucount);
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
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void saveBoard(const std::vector<std::vector<std::vector<int>>> &games, const std::string &file_path) {
    std::ofstream file(file_path);
    if (!file) {
        std::cerr << "file error" << file_path << std::endl;
        return;
    }
    for (const auto &game: games) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                file << game[row][col] << " ";
            }
            file << std::endl;
        }
        file << std::endl;
    }
    file.close();
    std::cout << "save board:" << file_path << std::endl;
}

void genAndSaveFinalBoards(int n, const std::string &file_path) {
    std::vector<std::vector<std::vector<int>>> sudoku_final_boards;
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> sudoku = genFinalBoard();
        sudoku_final_boards.push_back(sudoku);
    }
    saveBoard(sudoku_final_boards, file_path);
}

void genAndSaveGameBoards(int n, int r_lower, int r_upper, int level, const std::string &file_path) {
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

void genAndSaveOneSoluGameBoards(int n, int r_lower, int r_upper, int level, const std::string &file_path) {
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
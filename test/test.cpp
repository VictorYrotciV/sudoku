// Copyright 2023 PY Inc.
// Author: YaoHuizai PingShilong

#include <iostream>
#include <string.h>
#include <vector>
#include "../include/config.h"
#include "../include/solver.h"
#include "../include/game.h"
#include "../include/tools.h"
#include <gtest/gtest.h>

bool isRight(const std::vector<std::vector<int>> &grid,
             int mrow, int mcol, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[mrow][col] == num && mcol != col) {
            return false;
        }
    }
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][mcol] == num && row != mrow) {
            return false;
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + mrow / 3 * 3][col + mcol / 3 * 3] == num && (mcol != col + mcol / 3 * 3 || mrow != row + mrow / 3 * 3)) {
                return false;
            }
        }
    }
    return true;
}

int getEmptyNum(const std::vector<std::vector<int>> &grid) {
    int count = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                count++;
            }
        }
    }
    return count;
}

TEST(TestCases, correctness_case_1) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    std::string temp_file_path = DEFAULT_TEMP_FILE_PATH;
    int game_num = 1,
            game_level = DEFAULT_LEVEL,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    genAndSaveGameBoards(game_num, r_lower_num, r_upper_num,
                         game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    std::ofstream tempFile(temp_file_path);
    for (const auto &board : boards) {
        std::vector<std::vector<int>> copyBoard(board);
        solveSudokuSave(&copyBoard, &tempFile);
    }
    tempFile.close();
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(temp_file_path);
    for (const auto &board : final_boards) {
        std::vector<std::vector<int>> copyBoard(board);
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int num = copyBoard[row][col];
                ASSERT_TRUE(isRight(copyBoard, row, col, num));
            }
        }
    }

}

TEST(TestCases, correctness_case_5) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    std::string temp_file_path = DEFAULT_TEMP_FILE_PATH;
    int game_num = 5,
            game_level = DEFAULT_LEVEL,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    genAndSaveGameBoards(game_num, r_lower_num, r_upper_num,
                         game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    std::ofstream tempFile(temp_file_path);
    for (const auto &board : boards) {
        std::vector<std::vector<int>> copyBoard(board);
        solveSudokuSave(&copyBoard, &tempFile);
    }
    tempFile.close();
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(temp_file_path);
    for (const auto &board : final_boards) {
        std::vector<std::vector<int>> copyBoard(board);
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int num = copyBoard[row][col];
                ASSERT_TRUE(isRight(copyBoard, row, col, num));
            }
        }
    }

}

TEST(TestCases, correctness_case_10) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    std::string temp_file_path = DEFAULT_TEMP_FILE_PATH;
    int game_num = 10,
            game_level = DEFAULT_LEVEL,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    genAndSaveGameBoards(game_num, r_lower_num, r_upper_num,
                         game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    std::ofstream tempFile(temp_file_path);
    for (const auto &board : boards) {
        std::vector<std::vector<int>> copyBoard(board);
        solveSudokuSave(&copyBoard, &tempFile);
    }
    tempFile.close();
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(temp_file_path);
    for (const auto &board : final_boards) {
        std::vector<std::vector<int>> copyBoard(board);
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int num = copyBoard[row][col];
                ASSERT_TRUE(isRight(copyBoard, row, col, num));
            }
        }
    }

}

TEST(TestCases, range_case_1) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    std::string temp_file_path = DEFAULT_TEMP_FILE_PATH;
    int game_num = DEFAULT_GAME_NUM,
            game_level = DEFAULT_LEVEL,
            r_lower_num = 20,
            r_upper_num = 40;
    genAndSaveGameBoards(game_num, r_lower_num, r_upper_num,
                         game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    for (const auto &board : boards) {
        int num = getEmptyNum(board);
        ASSERT_TRUE(num >= r_lower_num && num <= r_upper_num);
    }

}

TEST(TestCases, range_case_2) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = DEFAULT_GAME_NUM,
            game_level = DEFAULT_LEVEL,
            r_lower_num = 25,
            r_upper_num = 45;
    genAndSaveGameBoards(game_num, r_lower_num, r_upper_num,
                         game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    for (const auto &board : boards) {
        int num = getEmptyNum(board);
        ASSERT_TRUE(num >= r_lower_num && num <= r_upper_num);
    }

}

TEST(TestCases, level_case_1) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = DEFAULT_GAME_NUM,
            game_level = 1,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower_num, r_upper_num);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(final_file_path);
    int index = 0;
    std::vector<int> rs;
    for (int i = 0; i < game_num; i++) {
        int r = distribution(rng);
        rs.push_back(r);
        std::vector<std::vector<int>> sudoku = genGameBoard(final_boards[index], r, game_level);
        index = (++index) % final_boards.size();
        sudoku_games.push_back(sudoku);
    }
    for (int i = 0; i < game_num; i++) {
        int r = rs[i];
        int step = 0, solutionCount = 0;
        std::vector<std::vector<int>> copyGrid(sudoku_games[i]);
        solveSudokuStep(&copyGrid, &step, &solutionCount);
        ASSERT_TRUE(isInLevel(step, solutionCount, r, game_level));
    }

}

TEST(TestCases, level_case_2) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = DEFAULT_GAME_NUM,
            game_level = 2,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower_num, r_upper_num);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(final_file_path);
    int index = 0;
    std::vector<int> rs;
    for (int i = 0; i < game_num; i++) {
        int r = distribution(rng);
        rs.push_back(r);
        std::vector<std::vector<int>> sudoku = genGameBoard(final_boards[index], r, game_level);
        sudoku_games.push_back(sudoku);
    }
    for (int i = 0; i < game_num; i++) {
        int r = rs[i];
        int step = 0, solutionCount = 0;
        std::vector<std::vector<int>> copyGrid(sudoku_games[i]);
        solveSudokuStep(&copyGrid, &step, &solutionCount);
        ASSERT_TRUE(isInLevel(step, solutionCount, r, game_level));
    }

}

TEST(TestCases, level_case_3) {
    std::string games_file_path = DEFAULT_GAME_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = DEFAULT_GAME_NUM,
            game_level = 3,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(r_lower_num, r_upper_num);
    std::vector<std::vector<std::vector<int>>> sudoku_games;
    std::vector<std::vector<std::vector<int>>> final_boards = loadBoard(final_file_path);
    int index = 0;
    std::vector<int> rs;
    for (int i = 0; i < game_num; i++) {
        int r = distribution(rng);
        rs.push_back(r);
        std::vector<std::vector<int>> sudoku = genGameBoard(final_boards[index], r, game_level);
        sudoku_games.push_back(sudoku);
    }
    for (int i = 0; i < game_num; i++) {
        int r = rs[i];
        int step = 0, solutionCount = 0;
        std::vector<std::vector<int>> copyGrid(sudoku_games[i]);
        solveSudokuStep(&copyGrid, &step, &solutionCount);
        ASSERT_TRUE(isInLevel(step, solutionCount, r, game_level));
    }

}

TEST(TestCases, uniqueness_case_1) {
    std::string games_file_path = DEFAULT_TEMP_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = 1,
            game_level = DEFAULT_LEVEL,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    genAndSaveOneSoluGameBoards(game_num, r_lower_num, r_upper_num,
                                game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    for (const auto &board : boards) {
        std::vector<std::vector<int>> copyBoard(board);
        int solveCount=0;
        solveSudokuCount(&copyBoard, &solveCount);
        ASSERT_TRUE(solveCount==1);
    }
}

TEST(TestCases, uniqueness_case_5) {
    std::string games_file_path = DEFAULT_TEMP_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = 5,
            game_level = DEFAULT_LEVEL,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    genAndSaveOneSoluGameBoards(game_num, r_lower_num, r_upper_num,
                                game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    for (const auto &board : boards) {
        std::vector<std::vector<int>> copyBoard(board);
        int solveCount=0;
        solveSudokuCount(&copyBoard, &solveCount);
        ASSERT_TRUE(solveCount==1);
    }
}

TEST(TestCases, uniqueness_case_10) {
    std::string games_file_path = DEFAULT_TEMP_FILE_PATH;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    int game_num = 10,
            game_level = DEFAULT_LEVEL,
            r_lower_num = DEFAULT_R_LOWER,
            r_upper_num = DEFAULT_R_UPPER;
    genAndSaveOneSoluGameBoards(game_num, r_lower_num, r_upper_num,
                                game_level, final_file_path, games_file_path);
    std::vector<std::vector<std::vector<int>>> boards = loadBoard(games_file_path);
    for (const auto &board : boards) {
        std::vector<std::vector<int>> copyBoard(board);
        int solveCount=0;
        solveSudokuCount(&copyBoard, &solveCount);
        ASSERT_TRUE(solveCount==1);
    }
}

int main(int argc, char **argv) {
     testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

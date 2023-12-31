// Copyright 2023 PY Inc.
// Author: YaoHuizai PingShilong

#include <string.h>
#include <iostream>
#include "../include/config.h"
#include "../include/solver.h"
#include "../include/game.h"


int main(int argc, char const *argv[]) {
    int is_n = 0, n_flag = 0;
    int n_index = 0, m_index = 0, r_index = 0, u_index = 0;
    std::string final_file_path = DEFAULT_FINAL_FILE_PATH;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-c")) {
            int final_board_num = atoi(argv[++i]);
            if (final_board_num < 1 || final_board_num > 1000000)
                return -1;
            genAndSaveFinalBoards(final_board_num, final_file_path);
        } else if (!strcmp(argv[i], "-s")) {
            std::string games_file_path = std::string(argv[++i]);
            std::string sudoku_file_path = DEFAULT_SUDOKU_FILE_PATH;
            solveFileSudoku(games_file_path, sudoku_file_path);
        } else if (!strcmp(argv[i], "-n")) {
            is_n = 1;
            n_index = ++i;
        } else if (!strcmp(argv[i], "-m")) {
            n_flag = 1;
            m_index = ++i;
        } else if (!strcmp(argv[i], "-r")) {
            n_flag = 1;
            r_index = ++i;
        } else if (!strcmp(argv[i], "-u")) {
            n_flag = 1;
            u_index = i;
        } else {
            std::cerr << "param error:" << argv[i] << std::endl;
            return -1;
        }
    }
    if (!is_n && n_flag) {
        std::cerr << "n error" << std::endl;
        return -1;
    } else if (is_n) {
        int game_num = atoi(argv[n_index]);
        if (game_num < 1 || game_num > 10000)
            return -1;
        std::string games_file_path = DEFAULT_GAME_FILE_PATH;
        int game_level = DEFAULT_LEVEL,
                r_lower_num = DEFAULT_R_LOWER,
                r_upper_num = DEFAULT_R_UPPER,
                is_solution_only = DEFAULT_IS_SOLUTION_ONLY;
        if (m_index) {
            game_level = atoi(argv[m_index]);
            if (game_level < 1 || game_level > 3)
                return -1;
        }
        if (r_index) {
            char *token = NULL;
            char *ptr = NULL;
            char *str = const_cast<char *>(argv[r_index]);
            token = strtok_s(str, "~", &ptr);
            r_lower_num = atoi(token);
            token = strtok_s(NULL, "~", &ptr);
            r_upper_num = atoi(token);
        }
        if (u_index) {
            is_solution_only = 1;
        }
        if (!is_solution_only) {
            genAndSaveGameBoards(game_num, r_lower_num, r_upper_num,
                                 game_level, final_file_path,
                                 games_file_path);
        } else {
            genAndSaveOneSoluGameBoards(game_num, r_lower_num, r_upper_num,
                                        game_level, final_file_path,
                                        games_file_path);
        }
    }

    return 0;
}

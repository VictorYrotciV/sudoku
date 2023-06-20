#ifndef SAVE_GAME_H
#define SAVE_GAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include "generate_game.h"
#include "macro.h"
// �洢������Ϸ���ļ���

void saveSudokuGamesToFile(const std::vector<std::vector<std::vector<int>>>& games, const std::string& file_path);
void generateAndSaveSudokuGames(int n, int r, const std::string& file_path);


void saveSudokuGamesToFile(const std::vector<std::vector<std::vector<int>>>& games, const std::string& file_path) {
    std::ofstream file(file_path);

    if (!file) {
        std::cerr << "�޷����ļ���"<< file_path << std::endl;
        return;
    }

    for (const auto& game : games) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                file << game[row][col] << " ";
            }
            file << std::endl;
        }
        file << std::endl;
    }

    file.close();

    std::cout << "������Ϸ�ѱ��浽�ļ���"<< file_path << std::endl;
}
void generateAndSaveSudokuGames(int n, int r, const std::string& file_path) {
    std::vector<std::vector<std::vector<int>>> sudoku_games;

    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> sudoku = generateSudokuGameBoard(r);
        sudoku_games.push_back(sudoku);
    }

    saveSudokuGamesToFile(sudoku_games, file_path);
}

#endif
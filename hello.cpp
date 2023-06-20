#include <iostream>
#include "lib/generate_game.h"
#include "lib/save_game.h"
#include "lib/macro.h"
using namespace std;
int main()
{

    int r = 30;


    int n = 5; // 生成 5 个数独游戏
    std::string file_path = "./games/game.txt"; // 文件路径和名称

    generateAndSaveSudokuGames(n, r, file_path);

    return 0;
}
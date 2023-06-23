#include <iostream>
#include "string.h"
#include "../include/game.h"
#include "../include/config.h"
using namespace std;
int main(int argc, char const *argv[])
{
    // int final_board_num,game_num,game_level,blank_lower_num,blank_upper_num,is_solution_only;
    // std::string file_path;
    // for(int i=1;i<argc;i++)
    // {
    //     if(!strcmp(argv[i], "-c"))
    //     {
    //         final_board_num=(int)atoi(argv[++i]);
    //         if(final_board_num<1 || final_board_num>1000000)
    //             return -1;
    //     }
    //     else if(!strcmp(argv[i], "-s"))
    //     {
    //         file_path=string(argv[++i]);
    //     }
    //     else if(!strcmp(argv[i], "-n"))
    //     {
    //         game_num=(int)atoi(argv[++i]);
    //         if(game_num<1 || game_num>10000)
    //             return -1;
    //     }
    //     else if(!strcmp(argv[i], "-m"))
    //     {
    //         game_level=(int)atoi(argv[++i]);
    //     }
    //     else if(!strcmp(argv[i], "-r"))
    //     {
    //         char *token=NULL;
    //         char *ptr=NULL;
    //         char *str=const_cast<char*>(argv[++i]);
    //         token=strtok_s(str,"~",&ptr);
    //         blank_lower_num=(int)atoi(token);
    //         token=strtok_s(NULL,"~",&ptr);
    //         blank_upper_num=(int)atoi(token);
    //     }
    //     else if(!strcmp(argv[i], "-u"))
    //     {
    //         is_solution_only=(int)atoi(argv[++i]);
    //     }
    //     else
    //     {
    //         std::cerr << "param error"<< file_path << std::endl;
    //         return -1;
    //     }
        
    // }
    int n=DEFAULT_FINAL_BOARD_NUM;
    int r=DEFAULT_BLANK_LOWER_NUM;
    std::string file_path = "./games/game.txt"; // 文件路径和名称
    std::string outfile_path = "./games/sudoku.txt";
    generateAndSaveSudokuGames(n, r, file_path);
    solveSudokuFromFile(file_path,outfile_path);

    return 0;
}
#include <iostream>
#include "string.h"
#include "../include/game.h"
using namespace std;
int main(int argc, char const *argv[])
{
    int final_board_num=5;
    std::string file_path="../games/game.txt";
    int game_num=5;
    int game_level=1;
    int blank_num=20;
    int is_solution_only=0;
    for(int i=1;i<argc;i++)
    {
        if(!strcmp(argv[i], "-c"))
        {
            final_board_num=(int)atoi(argv[++i]);
            if(final_board_num<1 || final_board_num>1000000)
                return -1;
        }
        else if(!strcmp(argv[i], "-s"))
        {
            file_path=string(argv[++i]);
        }
        else if(!strcmp(argv[i], "-n"))
        {
            game_num=(int)atoi(argv[++i]);
            if(game_num<1 || game_num>10000)
                return -1;
        }
        else if(!strcmp(argv[i], "-m"))
        {
            game_level=(int)atoi(argv[++i]);
        }
        else if(!strcmp(argv[i], "-r"))
        {
            
        }
        else if(!strcmp(argv[i], "-u"))
        {
            is_solution_only=(int)atoi(argv[++i]);
        }
        else
        {
            std::cerr << "param error"<< file_path << std::endl;
            return -1;
        }
    }

    return 0;
}
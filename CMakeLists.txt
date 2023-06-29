# run
cmake_minimum_required(VERSION 3.21)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(sudoku
        include/config.h
        include/game.h
        include/solver.h
        include/tools.h
        src/game.cpp
        src/solver.cpp
        src/tools.cpp
        src/main.cpp
        )

# # test
# cmake_minimum_required(VERSION 3.21)
# project(sudoku)

# set(CMAKE_CXX_STANDARD 14)

# include_directories(
#         include
#         gtest/include
# )

# link_directories(gtest/lib)

# add_executable(sudoku
#         include/config.h
#         include/game.h
#         include/solver.h
#         include/tools.h
#         src/game.cpp
#         test/test.cpp
#         src/solver.cpp
#         src/tools.cpp
#         )

# target_link_libraries(sudoku
#        libgtest
#        libgtest_main
# )
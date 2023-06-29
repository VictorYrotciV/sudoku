rm -rf CMakeFiles
rm cmake_install.cmake
rm CMakeCache.txt
cmake -G "MinGW Makefiles"
mingw32-make
# rm ./gtest/lib/sudoku.exe
# mv sudoku.exe ./gtest/lib/
# ./gtest/lib/sudoku.exe
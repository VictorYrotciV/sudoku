# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\VSCode\sudoku

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\VSCode\sudoku

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	D:\CMake\bin\cmake-gui.exe -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	D:\CMake\bin\cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start D:\VSCode\sudoku\CMakeFiles D:\VSCode\sudoku\\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start D:\VSCode\sudoku\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named sudoku

# Build rule for target.
sudoku: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 sudoku
.PHONY : sudoku

# fast build rule for target.
sudoku/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/build
.PHONY : sudoku/fast

src/game.obj: src/game.cpp.obj
.PHONY : src/game.obj

# target to build an object file
src/game.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/game.cpp.obj
.PHONY : src/game.cpp.obj

src/game.i: src/game.cpp.i
.PHONY : src/game.i

# target to preprocess a source file
src/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/game.cpp.i
.PHONY : src/game.cpp.i

src/game.s: src/game.cpp.s
.PHONY : src/game.s

# target to generate assembly for a file
src/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/game.cpp.s
.PHONY : src/game.cpp.s

src/main.obj: src/main.cpp.obj
.PHONY : src/main.obj

# target to build an object file
src/main.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/main.cpp.obj
.PHONY : src/main.cpp.obj

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/solver.obj: src/solver.cpp.obj
.PHONY : src/solver.obj

# target to build an object file
src/solver.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/solver.cpp.obj
.PHONY : src/solver.cpp.obj

src/solver.i: src/solver.cpp.i
.PHONY : src/solver.i

# target to preprocess a source file
src/solver.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/solver.cpp.i
.PHONY : src/solver.cpp.i

src/solver.s: src/solver.cpp.s
.PHONY : src/solver.s

# target to generate assembly for a file
src/solver.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/solver.cpp.s
.PHONY : src/solver.cpp.s

src/tools.obj: src/tools.cpp.obj
.PHONY : src/tools.obj

# target to build an object file
src/tools.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/tools.cpp.obj
.PHONY : src/tools.cpp.obj

src/tools.i: src/tools.cpp.i
.PHONY : src/tools.i

# target to preprocess a source file
src/tools.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/tools.cpp.i
.PHONY : src/tools.cpp.i

src/tools.s: src/tools.cpp.s
.PHONY : src/tools.s

# target to generate assembly for a file
src/tools.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\sudoku.dir\build.make CMakeFiles/sudoku.dir/src/tools.cpp.s
.PHONY : src/tools.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... sudoku
	@echo ... src/game.obj
	@echo ... src/game.i
	@echo ... src/game.s
	@echo ... src/main.obj
	@echo ... src/main.i
	@echo ... src/main.s
	@echo ... src/solver.obj
	@echo ... src/solver.i
	@echo ... src/solver.s
	@echo ... src/tools.obj
	@echo ... src/tools.i
	@echo ... src/tools.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system


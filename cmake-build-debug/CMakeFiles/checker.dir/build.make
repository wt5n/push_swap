# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hlikely/CLionProjects/push_swap/mygit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/checker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checker.dir/flags.make

CMakeFiles/checker.dir/operations.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/operations.c.o: ../operations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/checker.dir/operations.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/operations.c.o   -c /Users/hlikely/CLionProjects/push_swap/mygit/operations.c

CMakeFiles/checker.dir/operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/operations.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hlikely/CLionProjects/push_swap/mygit/operations.c > CMakeFiles/checker.dir/operations.c.i

CMakeFiles/checker.dir/operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/operations.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hlikely/CLionProjects/push_swap/mygit/operations.c -o CMakeFiles/checker.dir/operations.c.s

CMakeFiles/checker.dir/checker.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/checker.c.o: ../checker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/checker.dir/checker.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/checker.c.o   -c /Users/hlikely/CLionProjects/push_swap/mygit/checker.c

CMakeFiles/checker.dir/checker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/checker.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hlikely/CLionProjects/push_swap/mygit/checker.c > CMakeFiles/checker.dir/checker.c.i

CMakeFiles/checker.dir/checker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/checker.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hlikely/CLionProjects/push_swap/mygit/checker.c -o CMakeFiles/checker.dir/checker.c.s

CMakeFiles/checker.dir/validation.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/validation.c.o: ../validation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/checker.dir/validation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/validation.c.o   -c /Users/hlikely/CLionProjects/push_swap/mygit/validation.c

CMakeFiles/checker.dir/validation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/validation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hlikely/CLionProjects/push_swap/mygit/validation.c > CMakeFiles/checker.dir/validation.c.i

CMakeFiles/checker.dir/validation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/validation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hlikely/CLionProjects/push_swap/mygit/validation.c -o CMakeFiles/checker.dir/validation.c.s

# Object files for target checker
checker_OBJECTS = \
"CMakeFiles/checker.dir/operations.c.o" \
"CMakeFiles/checker.dir/checker.c.o" \
"CMakeFiles/checker.dir/validation.c.o"

# External object files for target checker
checker_EXTERNAL_OBJECTS =

checker: CMakeFiles/checker.dir/operations.c.o
checker: CMakeFiles/checker.dir/checker.c.o
checker: CMakeFiles/checker.dir/validation.c.o
checker: CMakeFiles/checker.dir/build.make
checker: CMakeFiles/checker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable checker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checker.dir/build: checker

.PHONY : CMakeFiles/checker.dir/build

CMakeFiles/checker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checker.dir/clean

CMakeFiles/checker.dir/depend:
	cd /Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hlikely/CLionProjects/push_swap/mygit /Users/hlikely/CLionProjects/push_swap/mygit /Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug /Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug /Users/hlikely/CLionProjects/push_swap/mygit/cmake-build-debug/CMakeFiles/checker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checker.dir/depend

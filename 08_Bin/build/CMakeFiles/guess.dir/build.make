# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/MyGitProject/08_Bin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/MyGitProject/08_Bin/build

# Include any dependencies generated for this target.
include CMakeFiles/guess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/guess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/guess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/guess.dir/flags.make

CMakeFiles/guess.dir/src/guess.c.o: CMakeFiles/guess.dir/flags.make
CMakeFiles/guess.dir/src/guess.c.o: ../src/guess.c
CMakeFiles/guess.dir/src/guess.c.o: CMakeFiles/guess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/MyGitProject/08_Bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/guess.dir/src/guess.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/guess.dir/src/guess.c.o -MF CMakeFiles/guess.dir/src/guess.c.o.d -o CMakeFiles/guess.dir/src/guess.c.o -c /root/MyGitProject/08_Bin/src/guess.c

CMakeFiles/guess.dir/src/guess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/guess.dir/src/guess.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/MyGitProject/08_Bin/src/guess.c > CMakeFiles/guess.dir/src/guess.c.i

CMakeFiles/guess.dir/src/guess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/guess.dir/src/guess.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/MyGitProject/08_Bin/src/guess.c -o CMakeFiles/guess.dir/src/guess.c.s

# Object files for target guess
guess_OBJECTS = \
"CMakeFiles/guess.dir/src/guess.c.o"

# External object files for target guess
guess_EXTERNAL_OBJECTS =

guess: CMakeFiles/guess.dir/src/guess.c.o
guess: CMakeFiles/guess.dir/build.make
guess: CMakeFiles/guess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/MyGitProject/08_Bin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable guess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/guess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/guess.dir/build: guess
.PHONY : CMakeFiles/guess.dir/build

CMakeFiles/guess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/guess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/guess.dir/clean

CMakeFiles/guess.dir/depend:
	cd /root/MyGitProject/08_Bin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/MyGitProject/08_Bin /root/MyGitProject/08_Bin /root/MyGitProject/08_Bin/build /root/MyGitProject/08_Bin/build /root/MyGitProject/08_Bin/build/CMakeFiles/guess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/guess.dir/depend


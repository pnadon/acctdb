# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/acctdb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/acctdb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/acctdb.dir/flags.make

CMakeFiles/acctdb.dir/acctdb.c.o: CMakeFiles/acctdb.dir/flags.make
CMakeFiles/acctdb.dir/acctdb.c.o: ../acctdb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/acctdb.dir/acctdb.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/acctdb.dir/acctdb.c.o   -c /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/acctdb.c

CMakeFiles/acctdb.dir/acctdb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/acctdb.dir/acctdb.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/acctdb.c > CMakeFiles/acctdb.dir/acctdb.c.i

CMakeFiles/acctdb.dir/acctdb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/acctdb.dir/acctdb.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/acctdb.c -o CMakeFiles/acctdb.dir/acctdb.c.s

CMakeFiles/acctdb.dir/transaction_processor.c.o: CMakeFiles/acctdb.dir/flags.make
CMakeFiles/acctdb.dir/transaction_processor.c.o: ../transaction_processor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/acctdb.dir/transaction_processor.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/acctdb.dir/transaction_processor.c.o   -c /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/transaction_processor.c

CMakeFiles/acctdb.dir/transaction_processor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/acctdb.dir/transaction_processor.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/transaction_processor.c > CMakeFiles/acctdb.dir/transaction_processor.c.i

CMakeFiles/acctdb.dir/transaction_processor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/acctdb.dir/transaction_processor.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/transaction_processor.c -o CMakeFiles/acctdb.dir/transaction_processor.c.s

CMakeFiles/acctdb.dir/acctdbEX.c.o: CMakeFiles/acctdb.dir/flags.make
CMakeFiles/acctdb.dir/acctdbEX.c.o: ../acctdbEX.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/acctdb.dir/acctdbEX.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/acctdb.dir/acctdbEX.c.o   -c /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/acctdbEX.c

CMakeFiles/acctdb.dir/acctdbEX.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/acctdb.dir/acctdbEX.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/acctdbEX.c > CMakeFiles/acctdb.dir/acctdbEX.c.i

CMakeFiles/acctdb.dir/acctdbEX.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/acctdb.dir/acctdbEX.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/acctdbEX.c -o CMakeFiles/acctdb.dir/acctdbEX.c.s

# Object files for target acctdb
acctdb_OBJECTS = \
"CMakeFiles/acctdb.dir/acctdb.c.o" \
"CMakeFiles/acctdb.dir/transaction_processor.c.o" \
"CMakeFiles/acctdb.dir/acctdbEX.c.o"

# External object files for target acctdb
acctdb_EXTERNAL_OBJECTS =

acctdb: CMakeFiles/acctdb.dir/acctdb.c.o
acctdb: CMakeFiles/acctdb.dir/transaction_processor.c.o
acctdb: CMakeFiles/acctdb.dir/acctdbEX.c.o
acctdb: CMakeFiles/acctdb.dir/build.make
acctdb: CMakeFiles/acctdb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable acctdb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/acctdb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/acctdb.dir/build: acctdb

.PHONY : CMakeFiles/acctdb.dir/build

CMakeFiles/acctdb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/acctdb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/acctdb.dir/clean

CMakeFiles/acctdb.dir/depend:
	cd /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug /Users/phil/Dropbox/Courses/CS380/4_assignment2/acctdb/cmake-build-debug/CMakeFiles/acctdb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/acctdb.dir/depend

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chenxx/jsontest/jsontest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chenxx/jsontest/jsontest/build

# Include any dependencies generated for this target.
include src/CMakeFiles/sendtest.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/sendtest.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/sendtest.dir/flags.make

src/CMakeFiles/sendtest.dir/sendtest.cpp.o: src/CMakeFiles/sendtest.dir/flags.make
src/CMakeFiles/sendtest.dir/sendtest.cpp.o: ../src/sendtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chenxx/jsontest/jsontest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/sendtest.dir/sendtest.cpp.o"
	cd /home/chenxx/jsontest/jsontest/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sendtest.dir/sendtest.cpp.o -c /home/chenxx/jsontest/jsontest/src/sendtest.cpp

src/CMakeFiles/sendtest.dir/sendtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sendtest.dir/sendtest.cpp.i"
	cd /home/chenxx/jsontest/jsontest/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chenxx/jsontest/jsontest/src/sendtest.cpp > CMakeFiles/sendtest.dir/sendtest.cpp.i

src/CMakeFiles/sendtest.dir/sendtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sendtest.dir/sendtest.cpp.s"
	cd /home/chenxx/jsontest/jsontest/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chenxx/jsontest/jsontest/src/sendtest.cpp -o CMakeFiles/sendtest.dir/sendtest.cpp.s

# Object files for target sendtest
sendtest_OBJECTS = \
"CMakeFiles/sendtest.dir/sendtest.cpp.o"

# External object files for target sendtest
sendtest_EXTERNAL_OBJECTS =

../bin/sendtest: src/CMakeFiles/sendtest.dir/sendtest.cpp.o
../bin/sendtest: src/CMakeFiles/sendtest.dir/build.make
../bin/sendtest: src/CMakeFiles/sendtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chenxx/jsontest/jsontest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/sendtest"
	cd /home/chenxx/jsontest/jsontest/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sendtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/sendtest.dir/build: ../bin/sendtest

.PHONY : src/CMakeFiles/sendtest.dir/build

src/CMakeFiles/sendtest.dir/clean:
	cd /home/chenxx/jsontest/jsontest/build/src && $(CMAKE_COMMAND) -P CMakeFiles/sendtest.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/sendtest.dir/clean

src/CMakeFiles/sendtest.dir/depend:
	cd /home/chenxx/jsontest/jsontest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chenxx/jsontest/jsontest /home/chenxx/jsontest/jsontest/src /home/chenxx/jsontest/jsontest/build /home/chenxx/jsontest/jsontest/build/src /home/chenxx/jsontest/jsontest/build/src/CMakeFiles/sendtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/sendtest.dir/depend

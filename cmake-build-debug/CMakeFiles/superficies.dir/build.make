# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mbordin/workspace/FEI/comp-graph/superficies

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/superficies.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/superficies.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/superficies.dir/flags.make

CMakeFiles/superficies.dir/main.cpp.o: CMakeFiles/superficies.dir/flags.make
CMakeFiles/superficies.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/superficies.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/superficies.dir/main.cpp.o -c /home/mbordin/workspace/FEI/comp-graph/superficies/main.cpp

CMakeFiles/superficies.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/superficies.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mbordin/workspace/FEI/comp-graph/superficies/main.cpp > CMakeFiles/superficies.dir/main.cpp.i

CMakeFiles/superficies.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/superficies.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mbordin/workspace/FEI/comp-graph/superficies/main.cpp -o CMakeFiles/superficies.dir/main.cpp.s

# Object files for target superficies
superficies_OBJECTS = \
"CMakeFiles/superficies.dir/main.cpp.o"

# External object files for target superficies
superficies_EXTERNAL_OBJECTS =

superficies: CMakeFiles/superficies.dir/main.cpp.o
superficies: CMakeFiles/superficies.dir/build.make
superficies: /usr/lib/x86_64-linux-gnu/libGL.so
superficies: /usr/lib/x86_64-linux-gnu/libGLU.so
superficies: /usr/lib/x86_64-linux-gnu/libglut.so
superficies: /usr/lib/x86_64-linux-gnu/libXmu.so
superficies: /usr/lib/x86_64-linux-gnu/libXi.so
superficies: CMakeFiles/superficies.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable superficies"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/superficies.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/superficies.dir/build: superficies

.PHONY : CMakeFiles/superficies.dir/build

CMakeFiles/superficies.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/superficies.dir/cmake_clean.cmake
.PHONY : CMakeFiles/superficies.dir/clean

CMakeFiles/superficies.dir/depend:
	cd /home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mbordin/workspace/FEI/comp-graph/superficies /home/mbordin/workspace/FEI/comp-graph/superficies /home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug /home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug /home/mbordin/workspace/FEI/comp-graph/superficies/cmake-build-debug/CMakeFiles/superficies.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/superficies.dir/depend


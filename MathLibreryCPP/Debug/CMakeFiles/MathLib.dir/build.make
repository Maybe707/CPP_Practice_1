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
CMAKE_SOURCE_DIR = /home/cyberdemon/Coding/CPP/MathLibreryCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug

# Include any dependencies generated for this target.
include CMakeFiles/MathLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MathLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MathLib.dir/flags.make

CMakeFiles/MathLib.dir/mathlibrery.cpp.o: CMakeFiles/MathLib.dir/flags.make
CMakeFiles/MathLib.dir/mathlibrery.cpp.o: ../mathlibrery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MathLib.dir/mathlibrery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MathLib.dir/mathlibrery.cpp.o -c /home/cyberdemon/Coding/CPP/MathLibreryCPP/mathlibrery.cpp

CMakeFiles/MathLib.dir/mathlibrery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MathLib.dir/mathlibrery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyberdemon/Coding/CPP/MathLibreryCPP/mathlibrery.cpp > CMakeFiles/MathLib.dir/mathlibrery.cpp.i

CMakeFiles/MathLib.dir/mathlibrery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MathLib.dir/mathlibrery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyberdemon/Coding/CPP/MathLibreryCPP/mathlibrery.cpp -o CMakeFiles/MathLib.dir/mathlibrery.cpp.s

# Object files for target MathLib
MathLib_OBJECTS = \
"CMakeFiles/MathLib.dir/mathlibrery.cpp.o"

# External object files for target MathLib
MathLib_EXTERNAL_OBJECTS =

../MathLib: CMakeFiles/MathLib.dir/mathlibrery.cpp.o
../MathLib: CMakeFiles/MathLib.dir/build.make
../MathLib: CMakeFiles/MathLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../MathLib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MathLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MathLib.dir/build: ../MathLib

.PHONY : CMakeFiles/MathLib.dir/build

CMakeFiles/MathLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MathLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MathLib.dir/clean

CMakeFiles/MathLib.dir/depend:
	cd /home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyberdemon/Coding/CPP/MathLibreryCPP /home/cyberdemon/Coding/CPP/MathLibreryCPP /home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug /home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug /home/cyberdemon/Coding/CPP/MathLibreryCPP/Debug/CMakeFiles/MathLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MathLib.dir/depend


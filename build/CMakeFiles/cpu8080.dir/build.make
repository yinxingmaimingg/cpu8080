# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/else/Documents/cpu8080

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/else/Documents/cpu8080/build

# Include any dependencies generated for this target.
include CMakeFiles/cpu8080.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpu8080.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpu8080.dir/flags.make

CMakeFiles/cpu8080.dir/src/main.cpp.o: CMakeFiles/cpu8080.dir/flags.make
CMakeFiles/cpu8080.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/else/Documents/cpu8080/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpu8080.dir/src/main.cpp.o"
	/usr/lib/ccache/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu8080.dir/src/main.cpp.o -c /home/else/Documents/cpu8080/src/main.cpp

CMakeFiles/cpu8080.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu8080.dir/src/main.cpp.i"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/else/Documents/cpu8080/src/main.cpp > CMakeFiles/cpu8080.dir/src/main.cpp.i

CMakeFiles/cpu8080.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu8080.dir/src/main.cpp.s"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/else/Documents/cpu8080/src/main.cpp -o CMakeFiles/cpu8080.dir/src/main.cpp.s

CMakeFiles/cpu8080.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/cpu8080.dir/src/main.cpp.o.requires

CMakeFiles/cpu8080.dir/src/main.cpp.o.provides: CMakeFiles/cpu8080.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpu8080.dir/build.make CMakeFiles/cpu8080.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/cpu8080.dir/src/main.cpp.o.provides

CMakeFiles/cpu8080.dir/src/main.cpp.o.provides.build: CMakeFiles/cpu8080.dir/src/main.cpp.o


CMakeFiles/cpu8080.dir/src/Cpu.cpp.o: CMakeFiles/cpu8080.dir/flags.make
CMakeFiles/cpu8080.dir/src/Cpu.cpp.o: ../src/Cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/else/Documents/cpu8080/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpu8080.dir/src/Cpu.cpp.o"
	/usr/lib/ccache/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpu8080.dir/src/Cpu.cpp.o -c /home/else/Documents/cpu8080/src/Cpu.cpp

CMakeFiles/cpu8080.dir/src/Cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpu8080.dir/src/Cpu.cpp.i"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/else/Documents/cpu8080/src/Cpu.cpp > CMakeFiles/cpu8080.dir/src/Cpu.cpp.i

CMakeFiles/cpu8080.dir/src/Cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpu8080.dir/src/Cpu.cpp.s"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/else/Documents/cpu8080/src/Cpu.cpp -o CMakeFiles/cpu8080.dir/src/Cpu.cpp.s

CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.requires:

.PHONY : CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.requires

CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.provides: CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpu8080.dir/build.make CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.provides.build
.PHONY : CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.provides

CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.provides.build: CMakeFiles/cpu8080.dir/src/Cpu.cpp.o


# Object files for target cpu8080
cpu8080_OBJECTS = \
"CMakeFiles/cpu8080.dir/src/main.cpp.o" \
"CMakeFiles/cpu8080.dir/src/Cpu.cpp.o"

# External object files for target cpu8080
cpu8080_EXTERNAL_OBJECTS =

cpu8080: CMakeFiles/cpu8080.dir/src/main.cpp.o
cpu8080: CMakeFiles/cpu8080.dir/src/Cpu.cpp.o
cpu8080: CMakeFiles/cpu8080.dir/build.make
cpu8080: CMakeFiles/cpu8080.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/else/Documents/cpu8080/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpu8080"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpu8080.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpu8080.dir/build: cpu8080

.PHONY : CMakeFiles/cpu8080.dir/build

CMakeFiles/cpu8080.dir/requires: CMakeFiles/cpu8080.dir/src/main.cpp.o.requires
CMakeFiles/cpu8080.dir/requires: CMakeFiles/cpu8080.dir/src/Cpu.cpp.o.requires

.PHONY : CMakeFiles/cpu8080.dir/requires

CMakeFiles/cpu8080.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpu8080.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpu8080.dir/clean

CMakeFiles/cpu8080.dir/depend:
	cd /home/else/Documents/cpu8080/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/else/Documents/cpu8080 /home/else/Documents/cpu8080 /home/else/Documents/cpu8080/build /home/else/Documents/cpu8080/build /home/else/Documents/cpu8080/build/CMakeFiles/cpu8080.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpu8080.dir/depend


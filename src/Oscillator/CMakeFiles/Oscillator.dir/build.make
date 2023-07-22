# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shawn/dev/synth-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shawn/dev/synth-c

# Include any dependencies generated for this target.
include src/Oscillator/CMakeFiles/Oscillator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Oscillator/CMakeFiles/Oscillator.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Oscillator/CMakeFiles/Oscillator.dir/progress.make

# Include the compile flags for this target's objects.
include src/Oscillator/CMakeFiles/Oscillator.dir/flags.make

src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.o: src/Oscillator/CMakeFiles/Oscillator.dir/flags.make
src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.o: src/Oscillator/Oscillator.cpp
src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.o: src/Oscillator/CMakeFiles/Oscillator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shawn/dev/synth-c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.o"
	cd /Users/shawn/dev/synth-c/src/Oscillator && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.o -MF CMakeFiles/Oscillator.dir/Oscillator.cpp.o.d -o CMakeFiles/Oscillator.dir/Oscillator.cpp.o -c /Users/shawn/dev/synth-c/src/Oscillator/Oscillator.cpp

src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Oscillator.dir/Oscillator.cpp.i"
	cd /Users/shawn/dev/synth-c/src/Oscillator && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shawn/dev/synth-c/src/Oscillator/Oscillator.cpp > CMakeFiles/Oscillator.dir/Oscillator.cpp.i

src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Oscillator.dir/Oscillator.cpp.s"
	cd /Users/shawn/dev/synth-c/src/Oscillator && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shawn/dev/synth-c/src/Oscillator/Oscillator.cpp -o CMakeFiles/Oscillator.dir/Oscillator.cpp.s

# Object files for target Oscillator
Oscillator_OBJECTS = \
"CMakeFiles/Oscillator.dir/Oscillator.cpp.o"

# External object files for target Oscillator
Oscillator_EXTERNAL_OBJECTS =

src/Oscillator/libOscillator.a: src/Oscillator/CMakeFiles/Oscillator.dir/Oscillator.cpp.o
src/Oscillator/libOscillator.a: src/Oscillator/CMakeFiles/Oscillator.dir/build.make
src/Oscillator/libOscillator.a: src/Oscillator/CMakeFiles/Oscillator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shawn/dev/synth-c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libOscillator.a"
	cd /Users/shawn/dev/synth-c/src/Oscillator && $(CMAKE_COMMAND) -P CMakeFiles/Oscillator.dir/cmake_clean_target.cmake
	cd /Users/shawn/dev/synth-c/src/Oscillator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Oscillator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Oscillator/CMakeFiles/Oscillator.dir/build: src/Oscillator/libOscillator.a
.PHONY : src/Oscillator/CMakeFiles/Oscillator.dir/build

src/Oscillator/CMakeFiles/Oscillator.dir/clean:
	cd /Users/shawn/dev/synth-c/src/Oscillator && $(CMAKE_COMMAND) -P CMakeFiles/Oscillator.dir/cmake_clean.cmake
.PHONY : src/Oscillator/CMakeFiles/Oscillator.dir/clean

src/Oscillator/CMakeFiles/Oscillator.dir/depend:
	cd /Users/shawn/dev/synth-c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shawn/dev/synth-c /Users/shawn/dev/synth-c/src/Oscillator /Users/shawn/dev/synth-c /Users/shawn/dev/synth-c/src/Oscillator /Users/shawn/dev/synth-c/src/Oscillator/CMakeFiles/Oscillator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Oscillator/CMakeFiles/Oscillator.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\pog\CLionProjects\labwork-5-ISKorobov

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug

# Include any dependencies generated for this target.
include lib/CMakeFiles/argparser.dir/depend.make
# Include the progress variables for this target.
include lib/CMakeFiles/argparser.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/argparser.dir/flags.make

lib/CMakeFiles/argparser.dir/ArgParser.cpp.obj: lib/CMakeFiles/argparser.dir/flags.make
lib/CMakeFiles/argparser.dir/ArgParser.cpp.obj: ../lib/ArgParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/argparser.dir/ArgParser.cpp.obj"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\argparser.dir\ArgParser.cpp.obj -c C:\pog\CLionProjects\labwork-5-ISKorobov\lib\ArgParser.cpp

lib/CMakeFiles/argparser.dir/ArgParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/ArgParser.cpp.i"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\pog\CLionProjects\labwork-5-ISKorobov\lib\ArgParser.cpp > CMakeFiles\argparser.dir\ArgParser.cpp.i

lib/CMakeFiles/argparser.dir/ArgParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/ArgParser.cpp.s"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\pog\CLionProjects\labwork-5-ISKorobov\lib\ArgParser.cpp -o CMakeFiles\argparser.dir\ArgParser.cpp.s

# Object files for target argparser
argparser_OBJECTS = \
"CMakeFiles/argparser.dir/ArgParser.cpp.obj"

# External object files for target argparser
argparser_EXTERNAL_OBJECTS =

lib/libargparser.a: lib/CMakeFiles/argparser.dir/ArgParser.cpp.obj
lib/libargparser.a: lib/CMakeFiles/argparser.dir/build.make
lib/libargparser.a: lib/CMakeFiles/argparser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libargparser.a"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib && $(CMAKE_COMMAND) -P CMakeFiles\argparser.dir\cmake_clean_target.cmake
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\argparser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/argparser.dir/build: lib/libargparser.a
.PHONY : lib/CMakeFiles/argparser.dir/build

lib/CMakeFiles/argparser.dir/clean:
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib && $(CMAKE_COMMAND) -P CMakeFiles\argparser.dir\cmake_clean.cmake
.PHONY : lib/CMakeFiles/argparser.dir/clean

lib/CMakeFiles/argparser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\pog\CLionProjects\labwork-5-ISKorobov C:\pog\CLionProjects\labwork-5-ISKorobov\lib C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\lib\CMakeFiles\argparser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/argparser.dir/depend


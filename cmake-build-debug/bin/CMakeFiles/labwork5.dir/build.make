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
include bin/CMakeFiles/labwork5.dir/depend.make
# Include the progress variables for this target.
include bin/CMakeFiles/labwork5.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/labwork5.dir/flags.make

bin/CMakeFiles/labwork5.dir/main.cpp.obj: bin/CMakeFiles/labwork5.dir/flags.make
bin/CMakeFiles/labwork5.dir/main.cpp.obj: bin/CMakeFiles/labwork5.dir/includes_CXX.rsp
bin/CMakeFiles/labwork5.dir/main.cpp.obj: ../bin/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/labwork5.dir/main.cpp.obj"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\labwork5.dir\main.cpp.obj -c C:\pog\CLionProjects\labwork-5-ISKorobov\bin\main.cpp

bin/CMakeFiles/labwork5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/labwork5.dir/main.cpp.i"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\pog\CLionProjects\labwork-5-ISKorobov\bin\main.cpp > CMakeFiles\labwork5.dir\main.cpp.i

bin/CMakeFiles/labwork5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/labwork5.dir/main.cpp.s"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\pog\CLionProjects\labwork-5-ISKorobov\bin\main.cpp -o CMakeFiles\labwork5.dir\main.cpp.s

# Object files for target labwork5
labwork5_OBJECTS = \
"CMakeFiles/labwork5.dir/main.cpp.obj"

# External object files for target labwork5
labwork5_EXTERNAL_OBJECTS =

bin/labwork5.exe: bin/CMakeFiles/labwork5.dir/main.cpp.obj
bin/labwork5.exe: bin/CMakeFiles/labwork5.dir/build.make
bin/labwork5.exe: lib/libargparser.a
bin/labwork5.exe: bin/CMakeFiles/labwork5.dir/linklibs.rsp
bin/labwork5.exe: bin/CMakeFiles/labwork5.dir/objects1.rsp
bin/labwork5.exe: bin/CMakeFiles/labwork5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable labwork5.exe"
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\labwork5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/labwork5.dir/build: bin/labwork5.exe
.PHONY : bin/CMakeFiles/labwork5.dir/build

bin/CMakeFiles/labwork5.dir/clean:
	cd /d C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin && $(CMAKE_COMMAND) -P CMakeFiles\labwork5.dir\cmake_clean.cmake
.PHONY : bin/CMakeFiles/labwork5.dir/clean

bin/CMakeFiles/labwork5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\pog\CLionProjects\labwork-5-ISKorobov C:\pog\CLionProjects\labwork-5-ISKorobov\bin C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin C:\pog\CLionProjects\labwork-5-ISKorobov\cmake-build-debug\bin\CMakeFiles\labwork5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/labwork5.dir/depend


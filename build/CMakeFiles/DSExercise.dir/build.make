# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Coding\Projects\DSExercise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Coding\Projects\DSExercise\build

# Include any dependencies generated for this target.
include CMakeFiles/DSExercise.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DSExercise.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DSExercise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSExercise.dir/flags.make

CMakeFiles/DSExercise.dir/hw6.c.obj: CMakeFiles/DSExercise.dir/flags.make
CMakeFiles/DSExercise.dir/hw6.c.obj: ../hw6.c
CMakeFiles/DSExercise.dir/hw6.c.obj: CMakeFiles/DSExercise.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Coding\Projects\DSExercise\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DSExercise.dir/hw6.c.obj"
	C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DSExercise.dir/hw6.c.obj -MF CMakeFiles\DSExercise.dir\hw6.c.obj.d -o CMakeFiles\DSExercise.dir\hw6.c.obj -c C:\Coding\Projects\DSExercise\hw6.c

CMakeFiles/DSExercise.dir/hw6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSExercise.dir/hw6.c.i"
	C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Coding\Projects\DSExercise\hw6.c > CMakeFiles\DSExercise.dir\hw6.c.i

CMakeFiles/DSExercise.dir/hw6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSExercise.dir/hw6.c.s"
	C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Coding\Projects\DSExercise\hw6.c -o CMakeFiles\DSExercise.dir\hw6.c.s

# Object files for target DSExercise
DSExercise_OBJECTS = \
"CMakeFiles/DSExercise.dir/hw6.c.obj"

# External object files for target DSExercise
DSExercise_EXTERNAL_OBJECTS =

DSExercise.exe: CMakeFiles/DSExercise.dir/hw6.c.obj
DSExercise.exe: CMakeFiles/DSExercise.dir/build.make
DSExercise.exe: CMakeFiles/DSExercise.dir/linklibs.rsp
DSExercise.exe: CMakeFiles/DSExercise.dir/objects1.rsp
DSExercise.exe: CMakeFiles/DSExercise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Coding\Projects\DSExercise\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DSExercise.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DSExercise.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSExercise.dir/build: DSExercise.exe
.PHONY : CMakeFiles/DSExercise.dir/build

CMakeFiles/DSExercise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DSExercise.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DSExercise.dir/clean

CMakeFiles/DSExercise.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Coding\Projects\DSExercise C:\Coding\Projects\DSExercise C:\Coding\Projects\DSExercise\build C:\Coding\Projects\DSExercise\build C:\Coding\Projects\DSExercise\build\CMakeFiles\DSExercise.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSExercise.dir/depend


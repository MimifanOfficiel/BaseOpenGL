# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024"

# Include any dependencies generated for this target.
include exosTP/tp02/CMakeFiles/tp02.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include exosTP/tp02/CMakeFiles/tp02.dir/compiler_depend.make

# Include the progress variables for this target.
include exosTP/tp02/CMakeFiles/tp02.dir/progress.make

# Include the compile flags for this target's objects.
include exosTP/tp02/CMakeFiles/tp02.dir/flags.make

exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj: exosTP/tp02/CMakeFiles/tp02.dir/flags.make
exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj: exosTP/tp02/CMakeFiles/tp02.dir/includes_CXX.rsp
exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj: exosTP/tp02/src/main.cpp
exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj: exosTP/tp02/CMakeFiles/tp02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\exosTP\tp02 && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj -MF CMakeFiles\tp02.dir\src\main.cpp.obj.d -o CMakeFiles\tp02.dir\src\main.cpp.obj -c "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\exosTP\tp02\src\main.cpp"

exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tp02.dir/src/main.cpp.i"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\exosTP\tp02 && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\exosTP\tp02\src\main.cpp" > CMakeFiles\tp02.dir\src\main.cpp.i

exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tp02.dir/src/main.cpp.s"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\exosTP\tp02 && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\exosTP\tp02\src\main.cpp" -o CMakeFiles\tp02.dir\src\main.cpp.s

# Object files for target tp02
tp02_OBJECTS = \
"CMakeFiles/tp02.dir/src/main.cpp.obj"

# External object files for target tp02
tp02_EXTERNAL_OBJECTS =

exosTP/tp02/tp02.exe: exosTP/tp02/CMakeFiles/tp02.dir/src/main.cpp.obj
exosTP/tp02/tp02.exe: exosTP/tp02/CMakeFiles/tp02.dir/build.make
exosTP/tp02/tp02.exe: stbimage/libstbimage.a
exosTP/tp02/tp02.exe: glad/libglad.a
exosTP/tp02/tp02.exe: glfw-3.3.8/src/libglfw3.a
exosTP/tp02/tp02.exe: imgui-1.91.1/libimgui.a
exosTP/tp02/tp02.exe: glengine/libglengine.a
exosTP/tp02/tp02.exe: exosTP/tp02/CMakeFiles/tp02.dir/linkLibs.rsp
exosTP/tp02/tp02.exe: exosTP/tp02/CMakeFiles/tp02.dir/objects1.rsp
exosTP/tp02/tp02.exe: exosTP/tp02/CMakeFiles/tp02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tp02.exe"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\exosTP\tp02 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tp02.dir\link.txt --verbose=$(VERBOSE)
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\exosTP\tp02 && C:\mingw64\bin\cmake.exe -E copy_directory "C:/Users/Lila/Documents/Cours/Semestre 5/Programmation avancee/baseGL-2024/exosTP/tp02/resources" "C:/Users/Lila/Documents/Cours/Semestre 5/Programmation avancee/baseGL-2024/exosTP/tp02/resources"

# Rule to build all files generated by this target.
exosTP/tp02/CMakeFiles/tp02.dir/build: exosTP/tp02/tp02.exe
.PHONY : exosTP/tp02/CMakeFiles/tp02.dir/build

exosTP/tp02/CMakeFiles/tp02.dir/clean:
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\exosTP\tp02 && $(CMAKE_COMMAND) -P CMakeFiles\tp02.dir\cmake_clean.cmake
.PHONY : exosTP/tp02/CMakeFiles/tp02.dir/clean

exosTP/tp02/CMakeFiles/tp02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\exosTP\tp02" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\exosTP\tp02" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\exosTP\tp02\CMakeFiles\tp02.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : exosTP/tp02/CMakeFiles/tp02.dir/depend


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
include glengine/CMakeFiles/glengine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glengine/CMakeFiles/glengine.dir/compiler_depend.make

# Include the progress variables for this target.
include glengine/CMakeFiles/glengine.dir/progress.make

# Include the compile flags for this target's objects.
include glengine/CMakeFiles/glengine.dir/flags.make

glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj: glengine/CMakeFiles/glengine.dir/flags.make
glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj: glengine/CMakeFiles/glengine.dir/includes_CXX.rsp
glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj: glengine/src/orbitalCamera.cpp
glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj: glengine/CMakeFiles/glengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj -MF CMakeFiles\glengine.dir\src\orbitalCamera.cpp.obj.d -o CMakeFiles\glengine.dir\src\orbitalCamera.cpp.obj -c "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\src\orbitalCamera.cpp"

glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/glengine.dir/src/orbitalCamera.cpp.i"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\src\orbitalCamera.cpp" > CMakeFiles\glengine.dir\src\orbitalCamera.cpp.i

glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/glengine.dir/src/orbitalCamera.cpp.s"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\src\orbitalCamera.cpp" -o CMakeFiles\glengine.dir\src\orbitalCamera.cpp.s

glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj: glengine/CMakeFiles/glengine.dir/flags.make
glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj: glengine/CMakeFiles/glengine.dir/includes_CXX.rsp
glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj: glengine/src/glengine.cpp
glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj: glengine/CMakeFiles/glengine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj -MF CMakeFiles\glengine.dir\src\glengine.cpp.obj.d -o CMakeFiles\glengine.dir\src\glengine.cpp.obj -c "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\src\glengine.cpp"

glengine/CMakeFiles/glengine.dir/src/glengine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/glengine.dir/src/glengine.cpp.i"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\src\glengine.cpp" > CMakeFiles\glengine.dir\src\glengine.cpp.i

glengine/CMakeFiles/glengine.dir/src/glengine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/glengine.dir/src/glengine.cpp.s"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\src\glengine.cpp" -o CMakeFiles\glengine.dir\src\glengine.cpp.s

# Object files for target glengine
glengine_OBJECTS = \
"CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj" \
"CMakeFiles/glengine.dir/src/glengine.cpp.obj"

# External object files for target glengine
glengine_EXTERNAL_OBJECTS =

glengine/libglengine.a: glengine/CMakeFiles/glengine.dir/src/orbitalCamera.cpp.obj
glengine/libglengine.a: glengine/CMakeFiles/glengine.dir/src/glengine.cpp.obj
glengine/libglengine.a: glengine/CMakeFiles/glengine.dir/build.make
glengine/libglengine.a: glengine/CMakeFiles/glengine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libglengine.a"
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && $(CMAKE_COMMAND) -P CMakeFiles\glengine.dir\cmake_clean_target.cmake
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glengine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glengine/CMakeFiles/glengine.dir/build: glengine/libglengine.a
.PHONY : glengine/CMakeFiles/glengine.dir/build

glengine/CMakeFiles/glengine.dir/clean:
	cd /d C:\Users\Lila\DOCUME~1\Cours\SEMEST~4\PROGRA~1\BASEGL~1\glengine && $(CMAKE_COMMAND) -P CMakeFiles\glengine.dir\cmake_clean.cmake
.PHONY : glengine/CMakeFiles/glengine.dir/clean

glengine/CMakeFiles/glengine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine" "C:\Users\Lila\Documents\Cours\Semestre 5\Programmation avancee\baseGL-2024\glengine\CMakeFiles\glengine.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : glengine/CMakeFiles/glengine.dir/depend


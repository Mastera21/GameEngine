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
CMAKE_COMMAND = C:\cmake-3.22.0\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.22.0\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\user\GitHub Repositorys\GameEngine\build"

# Include any dependencies generated for this target.
include sdl/CMakeFiles/sdl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sdl/CMakeFiles/sdl.dir/compiler_depend.make

# Include the progress variables for this target.
include sdl/CMakeFiles/sdl.dir/progress.make

# Include the compile flags for this target's objects.
include sdl/CMakeFiles/sdl.dir/flags.make

sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/Event.cpp
sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj -MF CMakeFiles\sdl.dir\src\Event.cpp.obj.d -o CMakeFiles\sdl.dir\src\Event.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Event.cpp"

sdl/CMakeFiles/sdl.dir/src/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/Event.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Event.cpp" > CMakeFiles\sdl.dir\src\Event.cpp.i

sdl/CMakeFiles/sdl.dir/src/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/Event.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Event.cpp" -o CMakeFiles\sdl.dir\src\Event.cpp.s

sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/MonitorWindow.cpp
sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj -MF CMakeFiles\sdl.dir\src\MonitorWindow.cpp.obj.d -o CMakeFiles\sdl.dir\src\MonitorWindow.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\MonitorWindow.cpp"

sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/MonitorWindow.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\MonitorWindow.cpp" > CMakeFiles\sdl.dir\src\MonitorWindow.cpp.i

sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/MonitorWindow.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\MonitorWindow.cpp" -o CMakeFiles\sdl.dir\src\MonitorWindow.cpp.s

sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/SDLLoader.cpp
sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj -MF CMakeFiles\sdl.dir\src\SDLLoader.cpp.obj.d -o CMakeFiles\sdl.dir\src\SDLLoader.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\SDLLoader.cpp"

sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/SDLLoader.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\SDLLoader.cpp" > CMakeFiles\sdl.dir\src\SDLLoader.cpp.i

sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/SDLLoader.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\SDLLoader.cpp" -o CMakeFiles\sdl.dir\src\SDLLoader.cpp.s

sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/Texture.cpp
sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj -MF CMakeFiles\sdl.dir\src\Texture.cpp.obj.d -o CMakeFiles\sdl.dir\src\Texture.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Texture.cpp"

sdl/CMakeFiles/sdl.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/Texture.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Texture.cpp" > CMakeFiles\sdl.dir\src\Texture.cpp.i

sdl/CMakeFiles/sdl.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/Texture.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Texture.cpp" -o CMakeFiles\sdl.dir\src\Texture.cpp.s

sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/Renderer.cpp
sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj -MF CMakeFiles\sdl.dir\src\Renderer.cpp.obj.d -o CMakeFiles\sdl.dir\src\Renderer.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Renderer.cpp"

sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/Renderer.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Renderer.cpp" > CMakeFiles\sdl.dir\src\Renderer.cpp.i

sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/Renderer.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\Renderer.cpp" -o CMakeFiles\sdl.dir\src\Renderer.cpp.s

sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/containers/ImageContainer.cpp
sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj -MF CMakeFiles\sdl.dir\src\containers\ImageContainer.cpp.obj.d -o CMakeFiles\sdl.dir\src\containers\ImageContainer.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\ImageContainer.cpp"

sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\ImageContainer.cpp" > CMakeFiles\sdl.dir\src\containers\ImageContainer.cpp.i

sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\ImageContainer.cpp" -o CMakeFiles\sdl.dir\src\containers\ImageContainer.cpp.s

sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/containers/TextContainer.cpp
sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj -MF CMakeFiles\sdl.dir\src\containers\TextContainer.cpp.obj.d -o CMakeFiles\sdl.dir\src\containers\TextContainer.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\TextContainer.cpp"

sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\TextContainer.cpp" > CMakeFiles\sdl.dir\src\containers\TextContainer.cpp.i

sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\TextContainer.cpp" -o CMakeFiles\sdl.dir\src\containers\TextContainer.cpp.s

sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/flags.make
sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/includes_CXX.rsp
sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj: C:/Users/user/GitHub\ Repositorys/GameEngine/Game-Engine/sdl/src/containers/FboContainer.cpp
sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj: sdl/CMakeFiles/sdl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj -MF CMakeFiles\sdl.dir\src\containers\FboContainer.cpp.obj.d -o CMakeFiles\sdl.dir\src\containers\FboContainer.cpp.obj -c "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\FboContainer.cpp"

sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.i"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\FboContainer.cpp" > CMakeFiles\sdl.dir\src\containers\FboContainer.cpp.i

sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.s"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl\src\containers\FboContainer.cpp" -o CMakeFiles\sdl.dir\src\containers\FboContainer.cpp.s

# Object files for target sdl
sdl_OBJECTS = \
"CMakeFiles/sdl.dir/src/Event.cpp.obj" \
"CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj" \
"CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj" \
"CMakeFiles/sdl.dir/src/Texture.cpp.obj" \
"CMakeFiles/sdl.dir/src/Renderer.cpp.obj" \
"CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj" \
"CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj" \
"CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj"

# External object files for target sdl
sdl_EXTERNAL_OBJECTS =

sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/Event.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/MonitorWindow.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/SDLLoader.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/Texture.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/Renderer.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/containers/ImageContainer.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/containers/TextContainer.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/src/containers/FboContainer.cpp.obj
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/build.make
sdl/libsdl.a: sdl/CMakeFiles/sdl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\user\GitHub Repositorys\GameEngine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libsdl.a"
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && $(CMAKE_COMMAND) -P CMakeFiles\sdl.dir\cmake_clean_target.cmake
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sdl.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdl/CMakeFiles/sdl.dir/build: sdl/libsdl.a
.PHONY : sdl/CMakeFiles/sdl.dir/build

sdl/CMakeFiles/sdl.dir/clean:
	cd /d C:\Users\user\GITHUB~1\GAMEEN~1\build\sdl && $(CMAKE_COMMAND) -P CMakeFiles\sdl.dir\cmake_clean.cmake
.PHONY : sdl/CMakeFiles/sdl.dir/clean

sdl/CMakeFiles/sdl.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine" "C:\Users\user\GitHub Repositorys\GameEngine\Game-Engine\sdl" "C:\Users\user\GitHub Repositorys\GameEngine\build" "C:\Users\user\GitHub Repositorys\GameEngine\build\sdl" "C:\Users\user\GitHub Repositorys\GameEngine\build\sdl\CMakeFiles\sdl.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : sdl/CMakeFiles/sdl.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/gameEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gameEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameEngine.dir/flags.make

CMakeFiles/gameEngine.dir/engine/Engine.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/engine/Engine.cpp.o: ../engine/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gameEngine.dir/engine/Engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/engine/Engine.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/engine/Engine.cpp

CMakeFiles/gameEngine.dir/engine/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/engine/Engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/engine/Engine.cpp > CMakeFiles/gameEngine.dir/engine/Engine.cpp.i

CMakeFiles/gameEngine.dir/engine/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/engine/Engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/engine/Engine.cpp -o CMakeFiles/gameEngine.dir/engine/Engine.cpp.s

CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.requires

CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.provides: CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.provides

CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.provides.build: CMakeFiles/gameEngine.dir/engine/Engine.cpp.o


CMakeFiles/gameEngine.dir/sdl/Event.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/sdl/Event.cpp.o: ../sdl/Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gameEngine.dir/sdl/Event.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/sdl/Event.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/Event.cpp

CMakeFiles/gameEngine.dir/sdl/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/sdl/Event.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/Event.cpp > CMakeFiles/gameEngine.dir/sdl/Event.cpp.i

CMakeFiles/gameEngine.dir/sdl/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/sdl/Event.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/Event.cpp -o CMakeFiles/gameEngine.dir/sdl/Event.cpp.s

CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.requires

CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.provides: CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.provides

CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.provides.build: CMakeFiles/gameEngine.dir/sdl/Event.cpp.o


CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o: ../sdl/MonitorWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/MonitorWindow.cpp

CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/MonitorWindow.cpp > CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.i

CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/MonitorWindow.cpp -o CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.s

CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.requires

CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.provides: CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.provides

CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.provides.build: CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o


CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o: ../sdl/SDLLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/SDLLoader.cpp

CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/SDLLoader.cpp > CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.i

CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/SDLLoader.cpp -o CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.s

CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.requires

CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.provides: CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.provides

CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.provides.build: CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o


CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o: ../sdl/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/Texture.cpp

CMakeFiles/gameEngine.dir/sdl/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/sdl/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/Texture.cpp > CMakeFiles/gameEngine.dir/sdl/Texture.cpp.i

CMakeFiles/gameEngine.dir/sdl/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/sdl/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/sdl/Texture.cpp -o CMakeFiles/gameEngine.dir/sdl/Texture.cpp.s

CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.requires

CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.provides: CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.provides

CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.provides.build: CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o


CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o: ../utils/drawing/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/utils/drawing/Point.cpp

CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/utils/drawing/Point.cpp > CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.i

CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/utils/drawing/Point.cpp -o CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.s

CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.requires

CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.provides: CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.provides

CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.provides.build: CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o


CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o: ../utils/drawing/Rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/utils/drawing/Rectangle.cpp

CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/utils/drawing/Rectangle.cpp > CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.i

CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/utils/drawing/Rectangle.cpp -o CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.s

CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.requires

CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.provides: CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.provides

CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.provides.build: CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o


CMakeFiles/gameEngine.dir/main.cpp.o: CMakeFiles/gameEngine.dir/flags.make
CMakeFiles/gameEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/gameEngine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameEngine.dir/main.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/main.cpp

CMakeFiles/gameEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameEngine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/main.cpp > CMakeFiles/gameEngine.dir/main.cpp.i

CMakeFiles/gameEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameEngine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/main.cpp -o CMakeFiles/gameEngine.dir/main.cpp.s

CMakeFiles/gameEngine.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/gameEngine.dir/main.cpp.o.requires

CMakeFiles/gameEngine.dir/main.cpp.o.provides: CMakeFiles/gameEngine.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gameEngine.dir/build.make CMakeFiles/gameEngine.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/gameEngine.dir/main.cpp.o.provides

CMakeFiles/gameEngine.dir/main.cpp.o.provides.build: CMakeFiles/gameEngine.dir/main.cpp.o


# Object files for target gameEngine
gameEngine_OBJECTS = \
"CMakeFiles/gameEngine.dir/engine/Engine.cpp.o" \
"CMakeFiles/gameEngine.dir/sdl/Event.cpp.o" \
"CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o" \
"CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o" \
"CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o" \
"CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o" \
"CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o" \
"CMakeFiles/gameEngine.dir/main.cpp.o"

# External object files for target gameEngine
gameEngine_EXTERNAL_OBJECTS =

gameEngine: CMakeFiles/gameEngine.dir/engine/Engine.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/sdl/Event.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/main.cpp.o
gameEngine: CMakeFiles/gameEngine.dir/build.make
gameEngine: /usr/lib/x86_64-linux-gnu/libSDL2main.a
gameEngine: /usr/lib/x86_64-linux-gnu/libSDL2.so
gameEngine: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
gameEngine: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
gameEngine: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
gameEngine: CMakeFiles/gameEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable gameEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameEngine.dir/build: gameEngine

.PHONY : CMakeFiles/gameEngine.dir/build

CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/engine/Engine.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/sdl/Event.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/sdl/MonitorWindow.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/sdl/SDLLoader.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/sdl/Texture.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/utils/drawing/Point.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/utils/drawing/Rectangle.cpp.o.requires
CMakeFiles/gameEngine.dir/requires: CMakeFiles/gameEngine.dir/main.cpp.o.requires

.PHONY : CMakeFiles/gameEngine.dir/requires

CMakeFiles/gameEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameEngine.dir/clean

CMakeFiles/gameEngine.dir/depend:
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles/gameEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gameEngine.dir/depend


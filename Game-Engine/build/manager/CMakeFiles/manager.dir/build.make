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
include manager/CMakeFiles/manager.dir/depend.make

# Include the progress variables for this target.
include manager/CMakeFiles/manager.dir/progress.make

# Include the compile flags for this target's objects.
include manager/CMakeFiles/manager.dir/flags.make

manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o: ../manager/src/managers/DrawMgr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/DrawMgr.cpp

manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/DrawMgr.cpp > CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.i

manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/DrawMgr.cpp -o CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.s

manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.requires

manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.provides: manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.provides

manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o


manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o: ../manager/src/managers/RsrcMgr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/RsrcMgr.cpp

manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/RsrcMgr.cpp > CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.i

manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/RsrcMgr.cpp -o CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.s

manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.requires

manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.provides: manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.provides

manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o


manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o: ../manager/src/managers/ManagerHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/ManagerHandler.cpp

manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/ManagerHandler.cpp > CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.i

manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/ManagerHandler.cpp -o CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.s

manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.requires

manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.provides: manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.provides

manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o


manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o: ../manager/src/managers/TimerMgr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/TimerMgr.cpp

manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/TimerMgr.cpp > CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.i

manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/managers/TimerMgr.cpp -o CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.s

manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.requires

manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.provides: manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.provides

manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o


manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o: ../manager/src/drawing/Widget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/drawing/Widget.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Widget.cpp

manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/drawing/Widget.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Widget.cpp > CMakeFiles/manager.dir/src/drawing/Widget.cpp.i

manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/drawing/Widget.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Widget.cpp -o CMakeFiles/manager.dir/src/drawing/Widget.cpp.s

manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.requires

manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.provides: manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.provides

manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o


manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o: ../manager/src/drawing/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/drawing/Image.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Image.cpp

manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/drawing/Image.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Image.cpp > CMakeFiles/manager.dir/src/drawing/Image.cpp.i

manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/drawing/Image.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Image.cpp -o CMakeFiles/manager.dir/src/drawing/Image.cpp.s

manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.requires

manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.provides: manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.provides

manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o


manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o: ../manager/src/drawing/Text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/drawing/Text.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Text.cpp

manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/drawing/Text.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Text.cpp > CMakeFiles/manager.dir/src/drawing/Text.cpp.i

manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/drawing/Text.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/drawing/Text.cpp -o CMakeFiles/manager.dir/src/drawing/Text.cpp.s

manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.requires

manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.provides: manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.provides

manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o


manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o: ../manager/src/buttonBase/ButtonBase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/buttonBase/ButtonBase.cpp

manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/buttonBase/ButtonBase.cpp > CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.i

manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/buttonBase/ButtonBase.cpp -o CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.s

manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.requires

manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.provides: manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.provides

manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o


manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o: manager/CMakeFiles/manager.dir/flags.make
manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o: ../manager/src/time/TimerClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/src/time/TimerClient.cpp.o -c /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/time/TimerClient.cpp

manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/src/time/TimerClient.cpp.i"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/time/TimerClient.cpp > CMakeFiles/manager.dir/src/time/TimerClient.cpp.i

manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/src/time/TimerClient.cpp.s"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager/src/time/TimerClient.cpp -o CMakeFiles/manager.dir/src/time/TimerClient.cpp.s

manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.requires:

.PHONY : manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.requires

manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.provides: manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.requires
	$(MAKE) -f manager/CMakeFiles/manager.dir/build.make manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.provides.build
.PHONY : manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.provides

manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.provides.build: manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o


# Object files for target manager
manager_OBJECTS = \
"CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o" \
"CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o" \
"CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o" \
"CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o" \
"CMakeFiles/manager.dir/src/drawing/Widget.cpp.o" \
"CMakeFiles/manager.dir/src/drawing/Image.cpp.o" \
"CMakeFiles/manager.dir/src/drawing/Text.cpp.o" \
"CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o" \
"CMakeFiles/manager.dir/src/time/TimerClient.cpp.o"

# External object files for target manager
manager_EXTERNAL_OBJECTS =

manager/libmanager.a: manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o
manager/libmanager.a: manager/CMakeFiles/manager.dir/build.make
manager/libmanager.a: manager/CMakeFiles/manager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libmanager.a"
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && $(CMAKE_COMMAND) -P CMakeFiles/manager.dir/cmake_clean_target.cmake
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/manager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
manager/CMakeFiles/manager.dir/build: manager/libmanager.a

.PHONY : manager/CMakeFiles/manager.dir/build

manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/managers/DrawMgr.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/managers/RsrcMgr.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/managers/ManagerHandler.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/managers/TimerMgr.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/drawing/Widget.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/drawing/Image.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/drawing/Text.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/buttonBase/ButtonBase.cpp.o.requires
manager/CMakeFiles/manager.dir/requires: manager/CMakeFiles/manager.dir/src/time/TimerClient.cpp.o.requires

.PHONY : manager/CMakeFiles/manager.dir/requires

manager/CMakeFiles/manager.dir/clean:
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager && $(CMAKE_COMMAND) -P CMakeFiles/manager.dir/cmake_clean.cmake
.PHONY : manager/CMakeFiles/manager.dir/clean

manager/CMakeFiles/manager.dir/depend:
	cd /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/manager /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager /home/svetoslav/Documents/GitHub/GameEngine/Game-Engine/build/manager/CMakeFiles/manager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : manager/CMakeFiles/manager.dir/depend


cmake_minimum_required (VERSION 3.5.1)

project (manager LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_INC_DIR ${_BASE_DIR}/manager)
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#You have to include every file here
add_library(
	${PROJECT_NAME} STATIC
	
		 #For header files
		 ${_INC_DIR}/config/DrawMgrCfg.h
		 ${_INC_DIR}/config/RsrcMgrCfg.h
		 ${_INC_DIR}/config/ManagerHandlerCfg.h
		 ${_INC_DIR}/managers/MgrBase.h
		 ${_INC_DIR}/managers/DrawMgr.h
		 ${_INC_DIR}/managers/RsrcMgr.h
		 ${_INC_DIR}/managers/ManagerHandler.h
		 ${_INC_DIR}/managers/TimerMgr.h
		 ${_INC_DIR}/drawing/Widget.h
		 ${_INC_DIR}/drawing/Image.h
		 ${_INC_DIR}/drawing/Text.h
		 ${_INC_DIR}/buttonBase/ButtonBase.h
		 ${_INC_DIR}/time/TimerClient.h
		 ${_INC_DIR}/time/TimerData.h
		 
	
		 #For src files
		 ${_SRC_DIR}/managers/DrawMgr.cpp
		 ${_SRC_DIR}/managers/RsrcMgr.cpp
		 ${_SRC_DIR}/managers/ManagerHandler.cpp
		 ${_SRC_DIR}/managers/TimerMgr.cpp
		 ${_SRC_DIR}/drawing/Widget.cpp
		 ${_SRC_DIR}/drawing/Image.cpp
		 ${_SRC_DIR}/drawing/Text.cpp
		 ${_SRC_DIR}/buttonBase/ButtonBase.cpp
		 ${_SRC_DIR}/time/TimerClient.cpp
)
		 
set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
	${PROJECT_NAME} 
		PUBLIC 
			${_BASE_DIR}
)
target_link_libraries(
	${PROJECT_NAME} 
		PUBLIC 
			sdl
)



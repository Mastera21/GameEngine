cmake_minimum_required (VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH
${CMAKE_MODULE_PATH}
${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

project (gameEngine LANGUAGES CXX)

if(UNIX)
	set(SDL2_image_name SDL2_image)
	set(SDL2_ttf_name SDL2_ttf)
	set(SDL2_mixer_name SDL2_mixer)
elseif(WIN32 OR APPLE)
	set(SDL2_image_name SDL2_IMAGE)
	set(SDL2_ttf_name SDL2_TTF)
	set(SDL2_mixer_name SDL2_MIXER)
endif()

find_package(SDL2 REQUIRED)
find_package(${SDL2_image_name} REQUIRED)
find_package(${SDL2_ttf_name} REQUIRED)
find_package(${SDL2_mixer_name} REQUIRED)


#SDL2_INCLUDE_DIR
#SDL2_LIBRARY

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#You have to include every file here
add_executable(
	${PROJECT_NAME} 
	
		 #For application folder
		 ${_BASE_DIR}/application/Application.h
		 ${_BASE_DIR}/application/Application.cpp
		 
		 #For common folder
		 ${_BASE_DIR}/common/CommonDefines.h
		 

		 #For engine folder
		 ${_BASE_DIR}/engine/Engine.h
		 ${_BASE_DIR}/engine/EngineConfigLoader.h
		 ${_BASE_DIR}/engine/config/EngineConfig.h
		 ${_BASE_DIR}/engine/Engine.cpp
		 ${_BASE_DIR}/engine/EngineConfigLoader.cpp
		 
		 #For game folder
		 ${_BASE_DIR}/game/config/GameCfg.h
		 ${_BASE_DIR}/game/board/GameBoard.h
		 ${_BASE_DIR}/game/board/GameBoard.cpp
		 ${_BASE_DIR}/game/board/MoveSelector.h
		 ${_BASE_DIR}/game/board/MoveSelector.cpp
		 ${_BASE_DIR}/game/utils/BoardPos.h
		 ${_BASE_DIR}/game/utils/BoardUtils.h
		 ${_BASE_DIR}/game/utils/BoardUtils.cpp
		 ${_BASE_DIR}/game/pieces/types/ChessPiece.h
		 ${_BASE_DIR}/game/pieces/types/ChessPiece.cpp
		 ${_BASE_DIR}/game/pieces/types/UnfinishedPiece.h
		 ${_BASE_DIR}/game/pieces/types/UnfinishedPiece.cpp
		 ${_BASE_DIR}/game/pieces/types/Rook.h
		 ${_BASE_DIR}/game/pieces/types/Rook.cpp
		 ${_BASE_DIR}/game/defines/ChessDefines.h
		 ${_BASE_DIR}/game/defines/ChessStructs.h
		 ${_BASE_DIR}/game/pieces/PieceHandler.h
		 ${_BASE_DIR}/game/pieces/PieceHandler.cpp
		 ${_BASE_DIR}/game/pieces/PieceHandlerPopulator.h
		 ${_BASE_DIR}/game/pieces/PieceHandlerPopulator.cpp
		 ${_BASE_DIR}/game/interfaces/GameBoardInterface.h
		 ${_BASE_DIR}/game/Game.h
		 ${_BASE_DIR}/game/Game.cpp
		 
		 	 
		${_BASE_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
${PROJECT_NAME} 
	PRIVATE 
		${_BASE_DIR}
)

target_link_libraries(
${PROJECT_NAME} 
	PRIVATE 
		#Adding file name on lib "manager"
		manager
)

if(CMAKE_BUILD_TYPE MATCHES RELEASE)
	add_custom_command(
		TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory
				${CMAKE_CURRENT_SOURCE_DIR}/assets/
				$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets/
	)
endif()

#Adding own lib 
add_subdirectory(utils)
add_subdirectory(sdl)
add_subdirectory(manager)






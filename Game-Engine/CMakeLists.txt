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
		 
		 #For sdl folder
		 ${_BASE_DIR}/sdl/MonitorWindow.h
		 ${_BASE_DIR}/sdl/MonitorWindow.cpp
		 ${_BASE_DIR}/sdl/SDLLoader.h
		 ${_BASE_DIR}/sdl/SDLLoader.cpp
		 ${_BASE_DIR}/sdl/config/MonitorWindowCfg.h
		 
		 
		 #For utils folder
		 ${_BASE_DIR}/utils/drawing/Point.h
		 ${_BASE_DIR}/utils/drawing/Point.cpp
		 ${_BASE_DIR}/utils/drawing/Rectangle.h
		 ${_BASE_DIR}/utils/drawing/Rectangle.cpp
		 
		 
		 
		 
		 
		${_BASE_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
${PROJECT_NAME} 
	PRIVATE 
		${_BASE_DIR}
		${SDL2_INCLUDE_DIR} 
		${SDL2_IMAGE_INCLUDE_DIR} 
		${SDL2_TTF_INCLUDE_DIR}
		${SDL2_MIXER_INCLUDE_DIR}
)

target_link_libraries(
${PROJECT_NAME} 
	PRIVATE 
		${SDL2_LIBRARY} 
		${SDL2_IMAGE_LIBRARY} 
		${SDL2_TTF_LIBRARY}
		${SDL2_MIXER_LIBRARY}
)

if(CMAKE_BUILD_TYPE MATCHES RELEASE)
	add_custom_command(
		TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory
				${CMAKE_CURRENT_SOURCE_DIR}/assets/
				$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets/
	)
endif()








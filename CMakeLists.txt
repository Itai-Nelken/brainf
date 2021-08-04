cmake_minimum_required(VERSION 3.16)
project(brainf VERSION 0.0.1 LANGUAGES C)

add_definitions(-Wall)
include_directories(brainf PRIVATE "include/")

add_library(stack STATIC
			src/stack.c
			include/stack.h
)

add_executable(brainf src/main.c)
add_executable(b2c b2c.c)
target_link_libraries(brainf stack)

install(TARGETS brainf b2c
	DESTINATION /usr/local/bin
)

if(NOT TARGET uninstall)
	configure_file(
		"${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
		"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
		IMMEDIATE @ONLY)
	add_custom_target(uninstall
		COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
	)
endif()

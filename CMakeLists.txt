cmake_minimum_required(VERSION 3.16)
project(brainf VERSION 1.1 LANGUAGES C)
enable_testing()

option(STACK_SIZE "size of the stack, default is 100." 100)
option(MEM_SIZE "Size of the \"memory\", default is 30000" 30000)

if(STACK_SIZE)
	add_compile_definitions(STACK_SIZE=${STACK_SIZE})
endif()
if(MEM_SIZE)
	add_compile_definitions(MEM_SIZE=${MEM_SIZE})
endif()

add_definitions(-Wall)
include_directories(brainf PRIVATE "include/")

add_library(stack STATIC
			src/stack.c
			include/stack.h
)
add_library(run STATIC
			src/run.c
			include/run.h
)

add_compile_definitions(VER="${CMAKE_PROJECT_VERSION}")
add_executable(brainf src/main.c)
target_link_libraries(brainf stack run)
target_link_libraries(run stack)

install(TARGETS brainf
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

add_test(print_H brainf -p ">+++++++++[<++++++++>-]<.")
set_tests_properties(print_H PROPERTIES PASS_REGULAR_EXPRESSION "H")
add_test(hello brainf ../examples/hello.b)
set_tests_properties(hello PROPERTIES PASS_REGULAR_EXPRESSION "Hello, world!")

set(ARCH ${CMAKE_HOST_SYSTEM_PROCESSOR})
if(NOT CPACK_GENERATOR)
	set(CPACK_GENERATOR "STGZ")
endif()
set(CPACK_PACKAGE_NAME "brainf")
set(CPACK_PACKAGE_DESCRIPTION "A brainfuck interpreter and compiler (to C) written in C")
set(CPACK_PACKAGE_CONTACT "itainelken@gmail.com")
set(CPACK_DEBIAN_PACKAGE_DEPENDS libc6)
set(CPACK_VERSION_MAJOR ${CMAKE_PROJECT_VERSION_MAJOR})
set(CPACK_VERSION_MIOR ${CMAKE_PROJECT_VERSION_MINOR})
set(CPACK_VERSION_PATCH ${CMAKE_PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
if(CPACK_GENERATOR STREQUAL "DEB")
	set(CPACK_PACKAGE_FILE_NAME "0:${CPACK_PACKAGE_NAME}-${CPACK-PACKAGE_VERSION}_Linux-${ARCH}")
else()
	set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}_Linux-${ARCH}")
endif()
include(CPack)

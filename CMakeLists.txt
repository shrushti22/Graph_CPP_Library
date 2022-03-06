
   
# VERSION
cmake_minimum_required(VERSION 3.16.3)

# variables
set(PROJECT_NAME "Graph")
set(LIBRARY "cpplib")

set(MAIN_CPP "./example/main.cpp")
set(SRC_DIR "./src" )
# set(TEST_DIR "./tests")
# set(TEST_EXE "tests.exe")

# files
file(GLOB INC_DIRS "./include/*/" "./include" "./src/*/")
file(GLOB INC_FILES "./include/cpplib.hpp")

# main project name 
project(${PROJECT_NAME})

# add main executable
add_executable(${PROJECT_NAME} ${MAIN_CPP})

# include path
include_directories(${INC_DIRS})

# cpplib building src
# add_subdirectory(${SRC_DIR})
# add_subdirectory(${TEST_DIR})

# linking cpplib with main project
# target_link_libraries(${PROJECT_NAME} ${LIBRARY})

# installation 
# install(FILES ${INC_FILES} DESTINATION include)

# unistall
# xargs rm < install_manifest.txt
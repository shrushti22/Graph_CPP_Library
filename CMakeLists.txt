
   
# VERSION
cmake_minimum_required(VERSION 3.16.3)

# variables
set(PROJECT_NAME "Graph")
set(LIBRARY "cpplib")

set(MAIN_CPP "./example/main.cpp")
set(SRC_DIR "./src" )
set(TEST_DIR "./tests")
set(TEST_EXE "tests.exe")

# files
file(GLOB INC_DIRS "./include/*/" "./include" "./src/*/" "./ext/*")
file(GLOB INSTALL_DIR "./src" )
file(GLOB INSTALL_FILE "./cpplib.hpp")

# main project name 
project(${PROJECT_NAME})

# add main executable
add_executable(${PROJECT_NAME} ${MAIN_CPP})

# include path
include_directories(${INC_DIRS})

#installation 
install(FILES ${INSTALL_FILE} DESTINATION include)
install(DIRECTORY ${INSTALL_DIR} DESTINATION include)

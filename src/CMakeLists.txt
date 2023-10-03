cmake_minimum_required(VERSION 3.21)

add_executable(module31 main.cpp task1.cpp task2.cpp)
target_include_directories(module31 PUBLIC ${MY_INCLUDE_DIR})
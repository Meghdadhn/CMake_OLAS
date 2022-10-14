cmake_minimum_required(VERSION 3.24.2)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Math_Lib)


target_include_directories(${PROJECT_NAME} PUBLIC Math_Lib)

target_link_directories(${PROJECT_NAME} PRIVATE Math_Lib)

target_link_libraries(${PROJECT_NAME} BasicMath)
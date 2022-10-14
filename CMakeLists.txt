cmake_minimum_required(VERSION 3.24.2)

project(OLAS VERSION 1.0)

configure_file(OLASConfig.h.in OLASConfig.h )

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories()

add_subdirectory(Math_Lib)
add_subdirectory(external/gflw)


target_include_directories(${PROJECT_NAME} 
    PUBLIC Math_Lib
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Math_Lib
    PRIVATE external/gflw/src
)

target_link_libraries(${PROJECT_NAME} BasicMath glfw)
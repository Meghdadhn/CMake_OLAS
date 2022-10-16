cmake_minimum_required(VERSION 3.24.2)

project(OLAS VERSION 1.0)

configure_file(OLASConfig.h.in OLASConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(Math_Lib)



# DOWNLOAD ALL THE SUBMODULE
find_package(git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.GIT")
    if (GIT_SUBMODULE)
        message(STATUS "Submodule Update")

        execute_process(COMMAND ${GIT_EXECUTE} submodule update --init --recursive
                    WORKING DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL ERROR "git submodule update --init failed")
        endif()
    endif()
endif()


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



#install software
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h" DESTINATION include)


#CPACK
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
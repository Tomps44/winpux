cmake_minimum_required(VERSION 3.23)
project(Winpux VERSION 1.0 LANGUAGES CXX)



# add_subdirectory(external/gammalgebra)
# target_link_libraries(glui_tests PRIVATE gammalgebra)

set(
    CROSS_PLATFORM_SOURCE_FILES 
    src/Window.cpp
    src/Handler.cpp
)

set(
    CROSS_PLATFORM_HEADER_FILES 
    include/Winpux/Window.hpp
    include/Winpux/Handler.hpp
)

add_library(${PROJECT_NAME} STATIC ${CROSS_PLATFORM_SOURCE_FILES} ${CROSS_PLATFORM_HEADER_FILES})
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(EXECUTABLE_NAME winpux_tests)


add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${PROJECT_NAME})



if(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE /std:c++20 /O2 /Wall)
else(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -std=c++20 -O2 -Wall -Wextra)
endif(MSVC)



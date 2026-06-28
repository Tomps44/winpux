cmake_minimum_required(VERSION 3.23)
project(Winpux VERSION 1.0 LANGUAGES CXX)

set(LIBRARY_NAME Winpux)



# add_subdirectory(external/gammalgebra)
# target_link_libraries(glui_tests PRIVATE gammalgebra)

set(WIN32_CPP   
    src/platform/win32-init.cpp
    src/platform/win32-window.cpp
)
set(WIN32_H
    include/Winpux/internal/platform/win32-platform.h
)


set(CROSS_PLATFORM_CPP_FILES
    src/library.cpp
    src/window.cpp
    src/init.cpp
)
set(CROSS_PLATFORM_H_FILES 
    include/Winpux/internal/setup.h
    include/Winpux/internal/platform.h
    include/Winpux/internal/global-lib.h
    include/Winpux/internal/window-impl.h
    
    include/Winpux/window-specs.h
    include/Winpux/library.h
    include/Winpux/window.h
)

add_library(
    ${LIBRARY_NAME}
    STATIC
    ${CROSS_PLATFORM_CPP_FILES} 
    ${WIN32_CPP}
)
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(EXECUTABLE_NAME winpux_tests)


add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})



if(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE /std:c++20 /O2 /Wall)
else(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -std=c++20 -O2 -Wall -Wextra)
endif(MSVC)



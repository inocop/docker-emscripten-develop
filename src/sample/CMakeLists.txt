cmake_minimum_required(VERSION 2.8)

project(Main)

#include_directories(/usr/include)
#link_directories(/usr/include)
#find_package(GLUT)
#find_package(OpenGL)

set(CMAKE_C_FLAGS  "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")

if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html") # デフォルトでは.js
endif()


add_executable(Main main.c)

target_link_libraries(Main glut GLU GL m)
#target_link_libraries(Main ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)

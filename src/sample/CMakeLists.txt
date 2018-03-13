cmake_minimum_required(VERSION 2.8)

project(Main)

#include_directories(/usr/include)
#link_directories(/usr/lib)
#find_package(GLUT)
#find_package(OpenGL)

set(CMAKE_C_FLAGS  "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")

if (EMSCRIPTEN)
  set(CMAKE_EXECUTABLE_SUFFIX ".html") # デフォルトでは.js
  set(EMCC_LINKER_FLAGS "-s LEGACY_GL_EMULATION=1 -s LEGACY_VM_SUPPORT=1")
endif()

add_executable(Main main.c)
set_target_properties(Main PROPERTIES LINK_FLAGS "${EMCC_LINKER_FLAGS}")
target_link_libraries(Main glut GLU GL m)
#target_link_libraries(Main ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)
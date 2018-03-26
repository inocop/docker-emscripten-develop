cmake_minimum_required(VERSION 3.0)
project(sample)

set(CMAKE_C_FLAGS   "-g -Wall")
set(CMAKE_CXX_FLAGS "-g -Wall")


#include_directories(/usr/include)
#link_directories(/usr/lib)
#find_package(GLUT)
#find_package(OpenGL)


add_executable(sample main.c)
target_link_libraries(sample glut GLU GL m)
#target_link_libraries(sample ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)


if (EMSCRIPTEN)
  # set(CMAKE_EXECUTABLE_SUFFIX ".html") # デフォルトでは.js
  set(LINK_FLAGS "-s LEGACY_GL_EMULATION=1 -s LEGACY_VM_SUPPORT=1 -o ${CMAKE_SOURCE_DIR}/../output_asm/sample.html")
  set_target_properties(sample PROPERTIES LINK_FLAGS "${LINK_FLAGS}")
endif()

cmake_minimum_required (VERSION 3.0)
project(sample02)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

if (EMSCRIPTEN)
  set(CMAKE_EXECUTABLE_SUFFIX ".html") # default is .js
  #set(LINKER_FLAGS "-s LEGACY_GL_EMULATION=1 -s LEGACY_VM_SUPPORT=1")
  set(LINKER_FLAGS "-s USE_GLFW=3 -s FULL_ES2=1 -s LEGACY_VM_SUPPORT=1 --preload-file shader.vert --preload-file shader.frag")
endif()

add_executable(sample02 main.cpp 
                        shader.hpp
                        shader.cpp
              )
target_link_libraries(sample02 glfw GLEW GL)
set_target_properties(sample02 PROPERTIES LINK_FLAGS "${LINKER_FLAGS}")
file(COPY "${CMAKE_SOURCE_DIR}/shader.vert" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "${CMAKE_SOURCE_DIR}/shader.frag" DESTINATION "${CMAKE_BINARY_DIR}")
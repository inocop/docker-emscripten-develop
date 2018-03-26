cmake_minimum_required(VERSION 2.8)

project(glfw_sample)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")


if (EMSCRIPTEN)
  set(CMAKE_EXECUTABLE_SUFFIX ".html") # default is .js
  set(LINKER_FLAGS "-s LEGACY_GL_EMULATION=1 -s LEGACY_VM_SUPPORT=1")
endif(EMSCRIPTEN)

set(RESOURCE_FILES
  "${CMAKE_SOURCE_DIR}/point.frag"
  "${CMAKE_SOURCE_DIR}/point.vert"
)

add_executable(glfw_sample main.cpp)
set_target_properties(glfw_sample PROPERTIES LINK_FLAGS "${LINKER_FLAGS}")
target_link_libraries(glfw_sample glfw GLEW GLU GL m)
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})
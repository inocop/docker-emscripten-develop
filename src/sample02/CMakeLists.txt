cmake_minimum_required (VERSION 3.0)
project(sample02)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++14")


add_executable(sample02 main.cpp
                        "${CMAKE_SOURCE_DIR}/../common/LoadShader.hpp"
                        "${CMAKE_SOURCE_DIR}/../common/LoadShader.cpp"
)
target_link_libraries(sample02 glfw GLEW GL)


set(RESOURCE_FILES "${CMAKE_SOURCE_DIR}/shader.vert"
                   "${CMAKE_SOURCE_DIR}/shader.frag"
)
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})


if (EMSCRIPTEN)
  set(LINK_FLAGS "-s USE_GLFW=3")
  set(LINK_FLAGS "${LINK_FLAGS} -s LEGACY_VM_SUPPORT=1")
  set(LINK_FLAGS "${LINK_FLAGS} -o ${CMAKE_SOURCE_DIR}/../output_asm/sample02.html")
  set(LINK_FLAGS "${LINK_FLAGS} --preload-file ${CMAKE_BINARY_DIR}/shader.vert@shader.vert")
  set(LINK_FLAGS "${LINK_FLAGS} --preload-file ${CMAKE_BINARY_DIR}/shader.frag@shader.frag")

  message(STATUS "LINK_FLAGS: ${LINK_FLAGS}")

  set_target_properties(sample02 PROPERTIES LINK_FLAGS ${LINK_FLAGS})
endif()

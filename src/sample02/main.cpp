// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow *window;

// Include GLM
#include "/usr/include/glm/glm.hpp"
#include "/usr/include/glm/gtc/matrix_transform.hpp"
using namespace glm;

#include "shader.hpp"

#ifdef __EMSCRIPTEN__
  #include <emscripten.h>
#endif

GLuint programID;
GLuint MatrixID;
GLuint vertexPosition_modelspaceID;
GLuint vertexbuffer;
glm::mat4 MVP;

void render_func()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        vertexPosition_modelspaceID, // The attribute we want to configure
        3,                           // size
        GL_FLOAT,                    // type
        GL_FALSE,                    // normalized?
        0,                           // stride
        (void *)0                    // array buffer offset
    );

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

#ifdef EMSCRIPTEN
    emscripten_cancel_main_loop();
#endif

}

int main()
{
   // GLFW初期化
  if (glfwInit() == GL_FALSE)
  {
    fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
    return -1;
  }

  // opengl es 2.0指定
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  // ウィンドウ生成
  window = glfwCreateWindow(500, 500, "Tutorial 02 - Red triangle", NULL, NULL);
  if (!window)
  {
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
    return -1;
  }

  // コンテキストの作成
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // GLEW初期化
  if (glewInit() != GLEW_OK)
  {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
    return -1;
  }

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  // Create and compile our GLSL program from the shaders
  programID = LoadShaders("shader.vert", "shader.frag");

  // Get a handle for our "MVP" uniform
  MatrixID = glGetUniformLocation(programID, "MVP");

  // Get a handle for our buffers
  vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  // Or, for an ortho camera :
  //glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

  // Camera matrix
  glm::mat4 View = glm::lookAt(
      glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
      glm::vec3(0, 0, 0), // and looks at the origin
      glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
  );
  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 Model = glm::mat4(1.0f);
  // Our ModelViewProjection : multiplication of our 3 matrices
  MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around

  static const GLfloat g_vertex_buffer_data[] = {
      -1.0f,
      -1.0f,
      0.0f,
      1.0f,
      -1.0f,
      0.0f,
      0.0f,
      1.0f,
      0.0f,
  };
  static const GLushort g_element_buffer_data[] = {0, 1, 2};

  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(render_func, 0, 1);
#else
  do
  {
    render_func();
  } // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
#endif

  // Cleanup VBO
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteProgram(programID);

  // Close OpenGL window and terminate GLFW
  glfwTerminate();
  return 0;
}
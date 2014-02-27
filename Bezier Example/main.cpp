//http://www.glfw.org/docs/latest/quick.html	GLFW3 - Start
//http://www.glfw.org/docs/3.0/moving.html		GLFW - GLFW3 Code
//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

//#include <GL/freeglut.h>
#include "common/shader.hpp"

#include "GameManager.h"

// Include GLFW
#include<GL/GLFW3.h>
#include "Window.h"

//#include "Text.h"
#include "Rob.h"

GameManager game;		// Game object
//Text text;


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void initalize();

// Externals
GLuint		programID;
GLuint		textID;
//GLuint		MINXFontID;
GLFWwindow* window;
//GLuint tex;
int picHeight, picWidth;
unsigned char* image;

//gli::texture2D Texture(gli::
//gli::texture2D element = gli::load("Hydrogen.jpg");
//gli::texture2D blah;

//--------------------------------------------------------------------------

int main( void )
{
	//RobWindow();

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL/*glfwGetPrimaryMonitor()*/, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	initalize();
	//text.TextInit();
	//RobWindow();

	// Loop
	while (!glfwWindowShouldClose(window))
	{
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram ( programID );

		// Game
		game.CheckKeyboard();
		game.update();
		game.display();

		glfwSwapBuffers( window );
		glfwPollEvents();
	}
	
	glDeleteProgram(programID);

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void initalize()
{
	// Ensure we can capture the escape key being pressed below
	//glfwSetInputMode( window, GLFW_STICKY_KEYS, GL_TRUE );
	glfwSetCursorPos( window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 );

	// Dark blue background
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Enable depth test
	glEnable( GL_DEPTH_TEST );
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

	// Cull triangles which normal is not towards the camera
	glEnable( GL_CULL_FACE );

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);		// Enable gl_PointSize to be edited

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "vshader.glsl", "fshader.glsl" );

	game.initalize();
}


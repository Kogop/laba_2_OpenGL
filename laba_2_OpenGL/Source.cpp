#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

//
//GLfloat vertices[] = {
//	  0.0f,  0.7f, 0.0f,   //roof
//	 -0.5f,  0.3f, 0.0f,
//	  0.5f,  0.3f, 0.0f,
//
//	 -0.5f,  0.3f, 0.0f,   // 1 part of house
//	 -0.5f, -0.5f, 0.0f,
//	  0.5f,  0.3f, 0.0f,
//
//	   0.5f,  0.3f, 0.0f,  // 2 pard of house
//	  -0.5f, -0.5f, 0.0f,
//	   0.5f, -0.5f, 0.0f,
//
//		- 0.4f,  0.0f, 0.0f,  // 1 window of house
//	  -0.2f, 0.0f, 0.0f,
//	   -0.4f, -0.2f, 0.0f,
//
//	 -0.2f,  0.0f, 0.0f,  // 2 window of house
//	  -0.4f, -0.2f, 0.0f,
//	  -0.2f, -0.2f, 0.0f
//
//};
GLfloat colors[] = {
	0.7, 0.7, 0.2,   //roof color
	0.7, 0.7, 0.2,
	0.7, 0.7, 0.2,

	 0.2, 0.2, 0.2,   //house color
	0.2, 0.2, 0.2,
	0.2, 0.2, 0.2,

	 0.2, 0.2, 0.2,   //house color
	0.2, 0.2, 0.2,
	0.2, 0.2, 0.2,

	0.4, 0.4, 0.4,   //window color
	0.4, 0.4, 0.4,
	0.4, 0.4, 0.4,

		0.4, 0.4, 0.4,   //window color
	0.4, 0.4, 0.4,
	0.4, 0.4, 0.4

};


GLfloat vertices[]
{
	 0.0f,  0.7f, 0.0f,   //0
	 -0.5f,  0.3f, 0.0f,  // 1
	  0.5f,  0.3f, 0.0f, //2

	   -0.5f, -0.5f, 0.0f, //3

		0.5f, -0.5f, 0.0f, //4

			-0.4f,  0.0f, 0.0f,  // 5

	  -0.2f, 0.0f, 0.0f,  //6

	   -0.4f, -0.2f, 0.0f,  //7

	   -0.2f, -0.2f, 0.0f  //8
};

GLubyte indices[] = { 0,1,2,1,2,4,1,3,4,5,6,8,5,7,8 };


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	//glViewport(0, 0, 600, 600);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if ((key == GLFW_KEY_A) && (action == GLFW_REPEAT)) {
		for (int i = 0; i < 44; i++)
		{
			colors[i] = colors[i] + 0.1;

		}
	}
	if ((key == GLFW_KEY_A) && (action == GLFW_RELEASE))
	{
		for (int i = 0; i < 44; i++)
		{
			colors[i] = colors[i] - 0.1;

		}
	}

};


void mouse_place(GLFWwindow* window, double xPos, double yPos) {

	/*cout << xPos << "  " << yPos << endl;*/

	for (int i = 16; i < 27; i++)
	{


		colors[i] = xPos / 1000.0;
		//cout << colors[i] << "  " << i << endl;
	}

};





int main() {

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "GOVNO", NULL, NULL);
	glfwMakeContextCurrent(window);






	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_place);

	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//glEnableClientState(GL_VERTEX_ARRAY);     eto odnim sposobom
		//glVertexPointer(3, GL_FLOAT, 0, vertices);
		//glEnableClientState(GL_COLOR_ARRAY); 
	
		//glColorPointer(3, GL_FLOAT, 0, colors);

		//glDrawArrays(GL_TRIANGLES, 0, 15);

		


		glEnableClientState(GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertices);
		cout << colors[28]  << endl;
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, colors);

		glDrawElements(GL_TRIANGLES , 15, GL_UNSIGNED_BYTE, indices);











		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();





	return 1;
}
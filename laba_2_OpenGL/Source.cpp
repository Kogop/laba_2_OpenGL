#include <GLFW/glfw3.h>
#include <iostream>



GLfloat vertices[] = {
	-0.5f, -0.5f, 0.0f,   //roof
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,

	 -0.4




};
GLfloat colors[] = {
	-0.2, -0.2, 0.2,   //roof color
	-0.2, -0.2, 0.2,
	-0.2, -0.2, 0.2

};

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


int main() {

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow* window = glfwCreateWindow(600, 600, "GOVNO", NULL, NULL);
	glfwMakeContextCurrent(window);






	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glEnableClientState(GL_COLOR_ARRAY); 
	
		glColorPointer(3, GL_FLOAT, 0, colors);

		glDrawArrays(GL_TRIANGLES, 0, 3);












		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();





	return 1;
}
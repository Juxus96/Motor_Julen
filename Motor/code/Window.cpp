#include "Window.hpp"
#include <iostream>



namespace Zynkro 
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	Window::Window(const char* _gameName, const int _windowWidth,const int _windowHeight)
	{
		#pragma region Sdl and opengl Init

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(_windowWidth, _windowHeight, _gameName, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

		glViewport(0, 0, _windowWidth, _windowWidth);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		#pragma endregion
		
		scenes["main"] = std::make_shared<Scene>(window);
		scenes["main"]->execute();

	}
	Window::~Window()
	{
		glfwTerminate();
		//delete window;
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	}
	void Window::display()
	{

	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

}



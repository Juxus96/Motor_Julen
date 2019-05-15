
#ifndef WINDOWHEADER
#define WINDOWHEADER
#define SDL_MAIN_HANDLED
#include <map>
#include <string>
#include "Scene.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Zynkro
{
	class Window
	{
	private:
		GLFWwindow* window;
		std::map<std::string, std::shared_ptr<Scene>> scenes;

	public:

		Window(const char* _gameName, const int _windowWidth, const int _windowHeight);
		~Window();

		void clear();
		void display();



	private:

	};
}
#endif
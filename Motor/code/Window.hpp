
#ifndef WINDOWHEADER
#define WINDOWHEADER
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <string>
#include "Scene.hpp"
#include <map>

namespace Zynkro
{
	class Window
	{
	private:
		SDL_Window * window;
		SDL_GLContext context;
		std::map<std::string, Scene> scenes;

	public:

		Window(const char* game_name,const int window_width,const int window_height);
		~Window();

		void clear();
		void display();


	private:

	};
}
#endif
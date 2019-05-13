#include "Window.hpp"
#include "glad/glad.h"
#include "OpenGL.hpp"



namespace Zynkro 
{
	Window::Window(const char* game_name, const int window_width,const int window_height)
	{
		#pragma region Sdl and opengl Init

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("No se ha podido inicializar SDL2.");
		}
		else
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(
				game_name,
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				window_width,
				window_height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			if (window)
			{
				context = SDL_GL_CreateContext(window);
				if (context)
					glt::initialize_opengl_extensions();
			}
			clear();
			display();
		}
		#pragma endregion

		scenes["main"].execute();

	}
	Window::~Window()
	{
		SDL_DestroyWindow(window);
		SDL_GL_DeleteContext(context);
		SDL_Quit();
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	}
	void Window::display()
	{
		SDL_GL_SwapWindow(window);
	}
}



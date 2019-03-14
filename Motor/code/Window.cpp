#include "Window.hpp"
#include "glad/glad.h"
#include "OpenGL.hpp"



namespace julen_engine 
{
	Window::Window(const char* game_name, const int window_width,const int window_height)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

		SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
											   // Create an application window with the following settings:
		window = SDL_CreateWindow(
			game_name,						   // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			window_width,                      // width, in pixels
			window_height,                     // height, in pixels
			SDL_WINDOW_OPENGL                  // flags - see below
		);

		if (window)
		{
			context = SDL_GL_CreateContext(window);
			if (context)
				glt::initialize_opengl_extensions();
			glClearColor(0.5, 0.5, 0.5, 1);
		}
		clear();
		display();
		// The window is open: could enter program loop here (see SDL_PollEvent())

	}
	Window::~Window()
	{
		// Close and destroy the window
		SDL_DestroyWindow(window);

		// Clean up
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



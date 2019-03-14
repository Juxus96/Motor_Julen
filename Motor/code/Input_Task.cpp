#include "Input_Task.hpp"
#include "SDL.h"
#include "Kernel.hpp"

namespace julen_engine
{
	Input_Task::Input_Task()
	{
	}
	Input_Task::~Input_Task()
	{
	}
	void Input_Task::initialize()
	{
	}
	void Input_Task::do_task()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
			{
				// Si se pulsan ciertas teclas se borra el contenido de la ventana:

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
				{
					Kernel::instance().stop();
				}
				}
			}

			break;
			}
		}
	}


}


#include "Input_Task.hpp"
#include "SDL.h"
#include "Kernel.hpp"

namespace Zynkro
{
	Input_Task::~Input_Task()
	{
		//delete kernel;                   ----------------------------------------------------- BUG / DUDA
	}
	void Input_Task::doTask()
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
					kernel->stop();
				}
				}
			}

			break;
			}
		}
	}


}


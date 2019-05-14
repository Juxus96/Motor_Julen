#include "InputTask.hpp"
#include "SDL.h"
#include "Kernel.hpp"

namespace Zynkro
{
	InputTask::~InputTask()
	{
		//delete kernel;                   ----------------------------------------------------- BUG / DUDA
	}
	void InputTask::DoTask()
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


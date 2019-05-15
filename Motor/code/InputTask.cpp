#include "InputTask.hpp"
#include "Kernel.hpp"

namespace Zynkro
{
	InputTask::~InputTask()
	{
		//delete kernel;                   ----------------------------------------------------- BUG / DUDA
	}
	void InputTask::DoTask()
	{
		if (glfwGetKey(kernel->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(kernel->window, true);
		glfwPollEvents();
	}


}


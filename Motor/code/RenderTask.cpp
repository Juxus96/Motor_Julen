#include "RenderTask.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Zynkro 
{
	RenderTask::~RenderTask()
	{
	}

	void RenderTask::DoTask()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto& comp : module->components)
		{
			comp->Update();
		}

		// clear buffers
		// render skybox
		// render meshes
		glfwSwapBuffers(module->window);
	}

}



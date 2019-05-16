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

		glClearColor(0.3f, 0.1f, 0.1f, 1);
		for (auto& comp : module->components)
		{
			comp->Update();
		}
		for (auto& comp : module->components)
		{
			comp->shader.Use();
			comp->shader.SetMat4("projection", glm::perspective(70.f, (float)1080 / (float)720, 0.1f, 100.f));
			comp->shader.SetMat4("view", module->camera->transform->GetTransform());
			comp->shader.SetMat4("model", comp->entity->transform->GetTransform());
			comp->Draw();
		}

		// clear buffers
		// render skybox
		// render meshes
		glfwSwapBuffers(module->window);
	}

}



#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TransformTask.hpp"

namespace Zynkro 
{

	TransformTask::~TransformTask()
	{
	}

	void TransformTask::DoTask()
	{
		for (auto& comp : module->components)
		{
			comp->Update();
		}
	}

}



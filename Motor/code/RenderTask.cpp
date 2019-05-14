#include "RenderTask.hpp"

namespace Zynkro 
{
	RenderTask::~RenderTask()
	{
	}

	void RenderTask::DoTask()
	{
		for (auto& comp : module->components) 
		{
			comp.Update();
		}

		// clear buffers
		// render skybox
		// render meshes
	}

}



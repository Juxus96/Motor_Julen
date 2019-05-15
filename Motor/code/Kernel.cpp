#include "Kernel.hpp"

namespace Zynkro 
{
	Kernel::~Kernel()
	{
		//delete window;
	}

	void Kernel::add_task(std::shared_ptr<Task> task)
	{
		tasks.push_back(task);
	}

	void Kernel::execute()
	{
		while (!glfwWindowShouldClose(window))
		{
			for(std::shared_ptr<Task> task : tasks)
			{
				task->DoTask();
			}			
		}
	}
	
}



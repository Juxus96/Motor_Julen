#include "Kernel.hpp"

namespace Zynkro 
{
	Kernel::Kernel()
	{
		running = true;
	}

	Kernel::~Kernel()
	{
	}

	void Kernel::add_task(Task & task)
	{
		tasks.push_back(&task);
	}

	void Kernel::execute()
	{
		while (running)
		{
			for(Task* task : tasks)
			{
				task->doTask();
			}			
		}
	}
	void Kernel::stop()
	{
		running = false;
	}
}



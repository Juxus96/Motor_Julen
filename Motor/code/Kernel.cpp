#include "Kernel.hpp"

namespace julen_engine 
{
	Kernel::Kernel()
	{
		running = true;
	}

	Kernel::~Kernel()
	{
	}
	Kernel & Kernel::instance()
	{
		static int i = 0;
		i++;
		static Kernel instance;
		return instance;
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
				task->do_task();
			}			
		}
	}
	void Kernel::stop()
	{
		running = false;
	}
}



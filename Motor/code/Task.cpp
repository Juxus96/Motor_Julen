#include "Task.hpp"
#include "Kernel.hpp"


namespace Zynkro 
{
	Task::Task(std::shared_ptr<Module> _module)
	{
		module = _module;
	}
}



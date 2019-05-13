
#ifndef TASKHEADER
#define TASKHEADER

#include "Module.hpp"

namespace Zynkro
{
	class Task
	{
	private:
		std::shared_ptr<Module> module;
	public:

		Task(std::shared_ptr<Module> module);

		virtual void doTask() = 0;


	private:

	};
}
#endif
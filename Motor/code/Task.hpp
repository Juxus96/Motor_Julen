
#ifndef TASKHEADER
#define TASKHEADER

#include "Module.hpp"

namespace Zynkro
{
	class Task
	{
	protected:
		std::shared_ptr<Module> module;
	public:

		Task(std::shared_ptr<Module> module);

		virtual void DoTask() = 0;


	private:

	};
}
#endif
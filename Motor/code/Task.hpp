
#ifndef TASKHEADER
#define TASKHEADER

#include "Module.hpp"

namespace Zynkro
{
	class Task
	{
	protected:
		Module * module;
	public:

		Task();

		virtual void DoTask() = 0;


	private:

	};
}
#endif
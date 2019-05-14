
#ifndef INPUTTASKHEADER
#define INPUTTASKHEADER

#include "Task.hpp"

namespace Zynkro
{
	class Kernel;
	class InputTask : public Task
	{
	private:
		Kernel * kernel;
	public:
		InputTask(Kernel * _kernel) : Task(nullptr)
		{
			kernel = _kernel;
		};
		~InputTask();

		void DoTask() override;


	};
}
#endif // !INPUTTASKHEADER

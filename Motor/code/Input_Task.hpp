
#ifndef INPUTTASKHEADER
#define INPUTTASKHEADER

#include "Task.hpp"

namespace Zynkro
{
	class Kernel;
	class Input_Task : public Task
	{
	private:
		Kernel * kernel;
	public:
		Input_Task(Kernel * _kernel) : Task(nullptr) 
		{
			kernel = _kernel;
		};
		~Input_Task();

		void doTask() override;


	};
}
#endif // !INPUTTASKHEADER


#ifndef INPUTTASKHEADER
#define INPUTTASKHEADER

#include "Task.hpp"

namespace Zynkro
{
	class Kernel;
	class InputTask : public Task
	{
	private:
		std::shared_ptr<Kernel> kernel;
	public:
		InputTask(std::shared_ptr<Kernel> _kernel)
		{
			kernel = _kernel;
		};
		~InputTask();

		void DoTask() override;


	};
}
#endif // !INPUTTASKHEADER


#ifndef INPUTTASKHEADER
#define INPUTTASKHEADER

#include "Task.hpp"
namespace julen_engine
{
	class Input_Task : public Task
	{
	public:
		Input_Task();
		~Input_Task();

		void initialize();
		void do_task();

	private:

	};
}
#endif // !INPUTTASKHEADER

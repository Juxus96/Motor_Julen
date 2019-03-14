
#ifndef KERNELHEADER
#define KERNELHEADER

#include <vector>
#include "Task.hpp"
//class Kernel
//	set< Task > tasks                                       // El set las ordena por prioridad
//	add_task()
//	execute()
//	stop()


namespace julen_engine
{
	class Kernel
	{
	private:
		std::vector<Task*> tasks;
		bool running;
	public:
		Kernel();
		~Kernel();
		static Kernel & instance();

		void add_task(Task & task);
		void execute();
		void stop();

	private:

	};
}
#endif
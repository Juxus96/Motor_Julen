
#ifndef TASKHEADER
#define TASKHEADER
//class Task
//	priority
//	Kernel *                                                // Kernel al que se añadió la Task
//	set_kernel()                                            // Lo llama Kernel::add_task()
//	virtual initialize()
//	virtual do_step()
//	virtual finalize()
//	operator < (const Task & other)


namespace julen_engine
{

	class Kernel;

	class Task
	{
	public:
		Task();
		~Task();

		virtual void initialize() = 0;
		virtual void do_task() = 0;


	private:

	};
}
#endif
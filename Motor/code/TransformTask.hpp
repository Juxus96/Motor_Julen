
#ifndef TRANSFORMTASKHEADER
#define TRANSFORMTASKHEADER

#include "TransformModule.hpp"
#include "Task.hpp"

namespace Zynkro
{
	class TransformTask : public Task
	{
	private:
		std::shared_ptr<TransformModule> module;
 
	public:
		TransformTask(std::shared_ptr<TransformModule> parent) : module(parent) {};
		~TransformTask();

		void DoTask() override;
	private:

	};

}
#endif
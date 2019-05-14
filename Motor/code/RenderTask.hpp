
#ifndef RENDERTASKHEADER
#define RENDERTASKHEADER

#include "Task.hpp"
#include "RenderModule.hpp"
#include <string>

namespace Zynkro
{
	

	class RenderTask : public Task
	{

	public:
		RenderTask(std::shared_ptr<RenderModule> parent) : Task(parent) {};
		~RenderTask();

		void DoTask();
	};

	

	

	

}
#endif

#ifndef RENDERTASKHEADER
#define RENDERTASKHEADER

#include "Task.hpp"
#include "RenderModule.hpp"
#include <string>

namespace Zynkro
{
	

	class RenderTask : public Task
	{
	private:
		float counter = 0.0f;
		std::shared_ptr<RenderModule> module;
	public:
		RenderTask(std::shared_ptr<RenderModule> parent) : module(parent) {};
		~RenderTask();

		void DoTask() override;
	};


}
#endif
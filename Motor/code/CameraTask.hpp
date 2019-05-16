
#ifndef CAMERATASKHEADER
#define CAMERATASKHEADER

#include "Task.hpp"
#include "CameraModule.hpp"
#include <string>

namespace Zynkro
{
	

	class CameraTask : public Task
	{
	private:
		std::shared_ptr<CameraModule> module;
	public:
		CameraTask(std::shared_ptr<CameraModule> parent) : module(parent) {};
		~CameraTask();

		void DoTask() override;
	};


}
#endif
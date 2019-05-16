
#ifndef CAMERAMODULEHEADER
#define CAMERAMODULEHEADER

#include "Module.hpp"
namespace Zynkro
{
	class CameraModule : public Module
	{
	public:
	private:
		
	public:
		CameraModule();
		~CameraModule();

		std::shared_ptr<Task> GetTask() override { return task; }
		void AddComponent(std::shared_ptr<Entity> entity) override;


	};

}
#endif
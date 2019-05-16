#include "CameraModule.hpp"
#include "CAmeraTask.hpp"

namespace Zynkro 
{
	CameraModule::CameraModule()
	{
		task = std::make_shared<CameraTask>(std::shared_ptr<CameraModule>(this));
	}
	CameraModule::~CameraModule()
	{
	}
	void CameraModule::AddComponent(std::shared_ptr<Entity> entity)
	{
	}
}



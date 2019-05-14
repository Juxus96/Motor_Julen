#include "RenderModule.hpp"
#include "RenderTask.hpp"
namespace Zynkro 
{
	RenderModule::RenderModule()
	{
		task = std::make_shared<RenderTask>(this);
	}
	RenderModule::~RenderModule()
	{
	}
	void RenderModule::AddComponent(std::shared_ptr<Entity> entity) //pasar parametros del model component
	{
		std::shared_ptr<ModelComponent> temp = std::make_shared<ModelComponent>();
		components.push_back(temp);
		entity->AddComponent("Render", temp);
	}
}



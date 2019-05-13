#include "RenderModule.hpp"

namespace Zynkro 
{
	RenderModule::RenderModule()
	{
	}
	RenderModule::~RenderModule()
	{
	}
	void RenderModule::AddComponent(std::shared_ptr<Entity> entity)
	{
		ModelComponent temp;
		components.push_back(temp);
		entity->AddComponent("Render", std::make_shared<ModelComponent>(temp));
	}
}



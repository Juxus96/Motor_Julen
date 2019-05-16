#include "TransformModule.hpp"
#include "TransformTask.hpp"

namespace Zynkro
{
	TransformModule::TransformModule()
	{
		task = std::make_shared<TransformTask>(std::shared_ptr<TransformModule>(this));
	}
	TransformModule::~TransformModule()
	{
	}
	void TransformModule::AddComponent(std::shared_ptr<Entity> entity)
	{
		std::shared_ptr<TransformComponent> temp = std::make_shared<TransformComponent>();
		components.push_back(temp);
		entity->transform = temp;
		entity->AddComponent("Transform", temp);
	}
}



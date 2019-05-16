#include "Entity.hpp"


namespace Zynkro 
{
	Entity::Entity()
	{

	}

	Entity::~Entity()
	{

	}

	void Entity::AddComponent(std::string name, std::shared_ptr<Component> _component)
	{
		components[name] = _component;
		components[name]->entity = this;
	}
	

}



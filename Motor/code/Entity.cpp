#include "Entity.hpp"
#include "Component.hpp"

namespace julen_engine 
{
	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}
	Component * Entity::get_component(std::string id)
	{
		return components[id];
	}
	Entity * Entity::get_child(std::string id)
	{
		return children[id];
	}

}



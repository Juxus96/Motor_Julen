
#ifndef ENTITYHEADER
#define ENTITYHEADER
#include "TransformComponent.hpp"
#include <map>
#include <string>
namespace Zynkro
{
	
	class Entity
	{
	public:
		std::map<std::string, std::shared_ptr<Component>> components;
		std::map<std::string, std::shared_ptr<Entity>>    children;

		std::shared_ptr<TransformComponent> transform;

	public:
		Entity();
		~Entity();

		void AddComponent(std::string name, std::shared_ptr<Component> _component);
	};

	

	

	

}
#endif
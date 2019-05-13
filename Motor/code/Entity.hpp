
#ifndef ENTITYHEADER
#define ENTITYHEADER

#include <map>
#include <string>

namespace Zynkro
{
	

	class Component;
	class Entity
	{

	private:
		std::map<std::string, std::shared_ptr<Component>> components;
		std::map<std::string, std::shared_ptr<Entity>>    children;

	public:
		Entity();
		~Entity();

		void AddComponent(std::string name, std::shared_ptr<Component> _component);
	};

	

	

	

}
#endif
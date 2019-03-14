
#ifndef ENTITYHEADER
#define ENTITYHEADER

#include <map>
#include <string>
#include "Node.hpp"
namespace julen_engine
{
	//map< id, Component > components
	//	map< id, Entity    > children
	//	Transform_Component  transform                          // Este componente existe siempre
	//	get_component(id)                                       // Busca un componente por id
	//	get_child(id)
	//	get_transform()                                         // Retorna el componente transform directamente

	class Component;
	class Entity
	{
	public:
		Entity();
		~Entity();

		Component* get_component(std::string);
		Entity*    get_child(std::string);

	private:
		std::map<std::string, Component*> components;
		std::map<std::string, Entity*   > children;
	};

	

	

	

}
#endif
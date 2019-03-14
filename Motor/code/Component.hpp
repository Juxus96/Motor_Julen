
#ifndef COMPONENTHEADER
#define COMPONENTHEADER

#include <map>
#include <string>
#include "Entity.hpp"

namespace julen_engine
{
	//Entity *                                                  // Entity a la que se añadió el componente
	//	initialize()                                            // Se invoca una vez se ha terminado de crear la Entity
	//	parse_property(id, value)

	class Component
	{
		Entity * entity;
	public:
		Component();
		~Component();

		virtual void initialize();
		virtual void parse_property(); //no se que hace esto

	private:

	};

	

	

}
#endif
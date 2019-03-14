
#ifndef SCENEHEADER
#define SCENEHEADER

#include <map>
#include <string>
#include "Entity.hpp"
//class Kernel
//	set< Task > tasks                                       // El set las ordena por prioridad
//	add_task()
//	execute()
//	stop()


namespace julen_engine
{
	class Module;
	class Scene
	{
	public:
		Scene();
		~Scene();

		void execute();

	private:
		std::map<std::string, Module*> modules;
		Entity root;
	};

}
#endif

#ifndef SCENEHEADER
#define SCENEHEADER

#include <map>
#include <string>
#include "Entity.hpp"
#include "Kernel.hpp"
#include "InputTask.hpp"



namespace Zynkro
{
	class Module;
	class Scene
	{
	private:
		Kernel kernel;
		InputTask inputTask;

		std::map<std::string, std::shared_ptr<Entity>> entities;
		std::map<std::string, std::shared_ptr<Module>> modules;

	public:
		Scene();

		void execute();

	};

}
#endif 

#ifndef MODULEHEADER
#define MODULEHEADER

#include <vector>
#include "Entity.hpp"

namespace Zynkro
{

	class Task;
	class Scene;
	class Module
	{
	private:
		
		std::vector<Entity> entities;
		std::shared_ptr<Task> task;

	public:
		Module();
		~Module();

		virtual void AddComponent(std::shared_ptr<Entity> entity);
	};

	

}
#endif
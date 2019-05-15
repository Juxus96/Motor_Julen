
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
	public:
		std::vector<std::shared_ptr<Component>> components;  
	protected:
		
		std::shared_ptr<Task> task;

	public:
		Module();
		~Module();

		virtual std::shared_ptr<Task> GetTask() = 0;
		virtual void AddComponent(std::shared_ptr<Entity> entity);
	};

	

}
#endif
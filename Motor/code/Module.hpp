
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
		
	protected:
		
		std::shared_ptr<Task> task;

	public:
		Module();
		~Module();

		virtual std::shared_ptr<Task> GetTask() = 0;
		virtual void AddComponent(std::shared_ptr<Entity> entity) = 0;
	};

	

}
#endif
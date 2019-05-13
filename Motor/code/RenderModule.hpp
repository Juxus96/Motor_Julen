
#ifndef RENDERMODULEHEADER
#define RENDERMODULEHEADER

#include <vector>
#include "Entity.hpp"
#include "ModelComponent.hpp"
#include "Task.hpp"
#include "Module.hpp"

namespace Zynkro
{
	class RenderModule : public Module
	{
	private:
		std::vector<ModelComponent> components; // despues pasar a render components para añadir camera y lights 

		//Camera
		//Skybox
		Task * task;
 
	public:
		RenderModule();
		~RenderModule();

		Task * GetTask() { return task; }
		void   AddComponent(std::shared_ptr<Entity> entity) override;

	private:

	};

}
#endif
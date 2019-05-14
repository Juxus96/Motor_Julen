
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

		//Camera
		//Skybox
 
	public:
		RenderModule();
		~RenderModule();

		Task * GetTask() { return task; }
		void   AddComponent(std::shared_ptr<Entity> entity) override;

	private:

	};

}
#endif
#include "RenderModule.hpp"
#include "RenderTask.hpp"
namespace Zynkro 
{
	RenderModule::RenderModule()
	{
		task = std::make_shared<RenderTask>(std::make_shared<RenderModule>(this));
	}
	RenderModule::~RenderModule()
	{
	}
	void RenderModule::AddComponent(std::shared_ptr<Entity> entity) //pasar parametros del model component
	{
		// DUDA: en add component se guarda un shared a temp o a la copia de temp q hay en components
		ModelComponent temp;
		components.push_back(temp);
		entity->AddComponent("Render", std::make_shared<ModelComponent>(temp));// tengo que hacer shared de temp o de components
	}
}



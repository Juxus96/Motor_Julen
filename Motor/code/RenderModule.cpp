#include "RenderModule.hpp"
#include "RenderTask.hpp"
namespace Zynkro 
{
	RenderModule::RenderModule(GLFWwindow* _window) : window(_window)
	{
		task = std::make_shared<RenderTask>(std::shared_ptr<RenderModule>(this));
	}
	RenderModule::~RenderModule()
	{
	}
	void RenderModule::AddComponent(std::shared_ptr<Entity> entity) //pasar xml con parametros del model component
	{
		textPath = "../assets/textures/container.jpg"; //parsear el x,l para pillar los datos del model
		std::shared_ptr<ModelComponent> temp = std::make_shared<ModelComponent>(textPath);
		components.push_back(temp);
		entity->AddComponent("Render", temp);
	}
}



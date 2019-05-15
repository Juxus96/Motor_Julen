#include "Scene.hpp"
#include "RenderModule.hpp"

namespace Zynkro 
{

	Scene::Scene(GLFWwindow* _window) : kernel(std::make_shared<Kernel>(_window)), inputTask (std::make_shared<InputTask>(kernel))
	{		
		kernel->add_task(inputTask);
		entities["root"] = std::make_shared<Entity>();
		modules["render"] = std::make_shared<RenderModule>(_window);
		modules["render"]->AddComponent(entities["root"]);
		std::shared_ptr<Task>  newTask = modules["render"]->GetTask();

		kernel->add_task(newTask);
	}

	void Scene::execute()
	{
		kernel->execute();
	}
}



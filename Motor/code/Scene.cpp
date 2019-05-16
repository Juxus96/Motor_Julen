#include "Scene.hpp"
#include "RenderModule.hpp"
#include "TransformModule.hpp"
#include "CameraModule.hpp"

namespace Zynkro 
{

	Scene::Scene(GLFWwindow* _window) : kernel(std::make_shared<Kernel>(_window)), inputTask (std::make_shared<InputTask>(kernel))
	{		
		kernel->add_task(inputTask);
		std::shared_ptr<Task>  newTask;
		entities["root"] = std::make_shared<Entity>();
		entities["root2"] = std::make_shared<Entity>();
		entities["camera"] = std::make_shared<Entity>();

		modules["render"] = std::make_shared<RenderModule>(_window);
		modules["camera"] = std::make_shared< CameraModule>();
		modules["transform"] = std::make_shared<TransformModule>();

		newTask = modules["render"]->GetTask();
		kernel->add_task(newTask); 
		newTask = modules["camera"]->GetTask();
		kernel->add_task(newTask);
		newTask = modules["transform"]->GetTask();
		kernel->add_task(newTask);

		modules["render"]->AddComponent(entities["root"]);
		modules["render"]->AddComponent(entities["root2"]);
		modules["transform"]->AddComponent(entities["root"]);
		modules["transform"]->AddComponent(entities["root2"]);
		modules["camera"]->AddComponent(entities["camera"]);
		modules["transform"]->AddComponent(entities["camera"]);
		
		std::static_pointer_cast<RenderModule>(modules["render"])->SetCamera(entities["camera"]);

		entities["root"]->transform->Scale({ 0.1f,0.1f,0.1f });
		entities["root2"]->transform->Scale({ 0.1f,0.1f,0.1f });
		entities["root"]->transform->Translate({ 0.f,-1.25f,0.f });
		entities["root2"]->transform->Translate({ -1.0f,-1.25f,0.f });
		entities["root2"]->transform->SetRotation({ 0.0f,1.0f,0.0f },0.01f);
		
		entities["camera"]->transform->Translate({ 0.0f,0.0f,-3.0f });

	}

	void Scene::execute()
	{
		kernel->execute();
	}
}



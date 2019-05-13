#include "Scene.hpp"
#include "RenderModule.hpp"

namespace Zynkro 
{

	Scene::Scene() : inputTask(&kernel)
	{
		kernel.add_task(inputTask);
		modules["render"] = std::make_shared<RenderModule>();
		modules["render"]->AddComponent(entities["root"]);
	}

	void Scene::execute()
	{
		kernel.execute();
	}
}



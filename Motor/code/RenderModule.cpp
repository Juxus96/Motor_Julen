#include "RenderModule.hpp"
#include "RenderTask.hpp"
namespace Zynkro 
{
	RenderModule::RenderModule(GLFWwindow* _window) : window(_window)
	{
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		task = std::make_shared<RenderTask>(std::shared_ptr<RenderModule>(this));

	}
	RenderModule::~RenderModule()
	{
	}
	void RenderModule::AddComponent(std::shared_ptr<Entity> entity) //pasar xml con parametros del model component
	{
		std::string modelPath = "../assets/nanosuit/nanosuit.obj"; 
		const char* vShaderPath = "../code/vShader.txt";
		const char* fShaderPath = "../code/fShader.txt";
		std::shared_ptr<ModelComponent> temp = std::make_shared<ModelComponent>(modelPath,vShaderPath,fShaderPath);
		components.push_back(temp);
		entity->AddComponent("Render", temp);
	}
}



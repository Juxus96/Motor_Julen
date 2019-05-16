
#ifndef RENDERMODULEHEADER
#define RENDERMODULEHEADER

#include <vector>
#include "Entity.hpp"
#include "ModelComponent.hpp"
#include "Entity.hpp"
#include "Task.hpp"
#include "Module.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Zynkro
{
	class RenderModule : public Module
	{
	public:
		GLFWwindow* window;
		std::shared_ptr<Entity> camera;
		std::vector<std::shared_ptr<ModelComponent>> components;
	private:
		
		//Skybox
 
	public:
		RenderModule(GLFWwindow* _window);
		RenderModule() = delete;
		~RenderModule();

		std::shared_ptr<Task> GetTask() override { return task; }
		void AddComponent(std::shared_ptr<Entity> entity) override;
		void SetCamera(std::shared_ptr<Entity> _camera) { camera = _camera; };


	};

}
#endif
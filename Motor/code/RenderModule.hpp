
#ifndef RENDERMODULEHEADER
#define RENDERMODULEHEADER

#include <vector>
#include "Entity.hpp"
#include "ModelComponent.hpp"
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
	private:
		const char* textPath;
		//Camera
		//Skybox
 
	public:
		RenderModule(GLFWwindow* _window);
		RenderModule() = delete;
		~RenderModule();

		std::shared_ptr<Task> GetTask() override { return task; }
		void AddComponent(std::shared_ptr<Entity> entity) override;

	private:

	};

}
#endif
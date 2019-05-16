
#ifndef TRANSFORMMODULEHEADER
#define TRANSFORMMODULEHEADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TransformComponent.hpp"
#include "Module.hpp"

namespace Zynkro
{
	class TransformModule : public Module
	{
	
	public:
		std::vector<std::shared_ptr<TransformComponent>> components;

	public:
		TransformModule();
		~TransformModule();

		std::shared_ptr<Task> GetTask() override { return task; }
		virtual void AddComponent(std::shared_ptr<Entity> entity);


	};

}
#endif
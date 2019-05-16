
#ifndef KERNELHEADER
#define KERNELHEADER

#include <vector>
#include "Task.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Zynkro
{
	class Kernel
	{
	public:
		GLFWwindow* window;
	private:
		std::vector<std::shared_ptr<Task>> tasks;
	public:
		Kernel(GLFWwindow* _window) : window(_window) {};
		Kernel() = delete;
		~Kernel();

		void add_task(std::shared_ptr<Task> task);
		void execute();

	private:

	};
}
#endif

#ifndef KERNELHEADER
#define KERNELHEADER

#include <vector>
#include "Task.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
//class Kernel
//	set< Task > tasks                                       // El set las ordena por prioridad
//	add_task()
//	execute()
//	stop()


namespace Zynkro
{
	class Kernel
	{
	public:
		GLFWwindow* window;
	private:
		std::vector<std::shared_ptr<Task>> tasks;
		bool running;
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
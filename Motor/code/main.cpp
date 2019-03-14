#include "Kernel.hpp"
#include "Window.hpp"
#include "Input_Task.hpp"

using namespace julen_engine;
int main() 
{
	const char* name{"game"};
	Window window(name, 1080,270);

	Input_Task it;

	Kernel::instance().add_task(it);
	Kernel::instance().execute();



	return 0;
}
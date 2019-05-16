
#ifndef COMPONENTHEADER
#define COMPONENTHEADER
#include <memory>

namespace Zynkro
{
	class Entity;
	class Component
	{

	public:
		Entity * entity;
	public:
		Component();
		~Component();

		virtual void Update();

	};

	

}
#endif
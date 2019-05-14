
#ifndef COMPONENTHEADER
#define COMPONENTHEADER


namespace Zynkro
{
	class Component
	{


	public:
		Component();
		~Component();

		virtual void Update() = 0;

	};

	

	

}
#endif
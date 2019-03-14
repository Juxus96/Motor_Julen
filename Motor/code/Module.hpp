
#ifndef MODULEHEADER
#define MODULEHEADER

#include <map>
#include <string>
#include "Scene.hpp"

namespace julen_engine
{

	class Module
	{
	private:
		class Module_Factory
		{
		public:
			Module_Factory();
			~Module_Factory();

			virtual void create_module();
		private:

		};

		static std::map<std::string, Module_Factory * > moduleFactory;
		Scene * scene;

	public:
		Module();
		~Module();

		static void register_module();
		virtual void get_task();
		virtual void create_component();

	private:
	};

	

}
#endif
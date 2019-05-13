
#ifndef MODELCOMPONENTHEADER
#define MODELCOMPONENTHEADER

#include "Component.hpp"
#include "Mesh.hpp"
#include "Material.hpp"
#include <map>
#include <string>

namespace Zynkro
{
	class ModelComponent : public Component
	{
		bool prueba;
		std::map<std::string, std::shared_ptr<Mesh>>     meshes;
		std::map<std::string, std::shared_ptr<Material>> matrials;

	public:
		ModelComponent() : prueba(true) {};
		~ModelComponent();



	};

	

	

}
#endif

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
		std::map<std::string, std::shared_ptr<Mesh>>     meshes;
		std::map<std::string, std::shared_ptr<Material>> matrials;

	public:
		ModelComponent();
		~ModelComponent();

		void Update() override;


	};

	

	

}
#endif

#ifndef MODELCOMPONENTHEADER
#define MODELCOMPONENTHEADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
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
		std::map<std::string, std::shared_ptr<Material>> materials;

	public:
		ModelComponent(const char* textPath);
		~ModelComponent();

		void Update() override;


	};

	

	

}
#endif
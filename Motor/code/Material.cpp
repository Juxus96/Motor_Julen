#include "ModelComponent.hpp"
#include "Material.hpp"

namespace Zynkro 
{
	Material::Material()
	{
		shaders["first"] = std::make_shared<ShaderProgram>();
	}
	Material::Material()
	{
	}
	Material::~Material()
	{
	}
}



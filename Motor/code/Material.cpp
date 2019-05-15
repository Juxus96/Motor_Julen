#include "ModelComponent.hpp"
#include "Material.hpp"

namespace Zynkro 
{
	Material::Material(const char* textPath)
	{
		shaders["first"] = std::make_shared<ShaderProgram>();
		textures["first"] = std::make_shared<Texture>(textPath);
	}
	Material::~Material()
	{
	}
}



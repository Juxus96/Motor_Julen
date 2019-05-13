
#ifndef MATERIALHEADER
#define MATERIALHEADER

#include <vector>
#include <Shared_Ptr.hpp>
#include "Texture.hpp"
#include "ShaderProgram.hpp"

namespace Zynkro
{
	class Material
	{
		std::vector<std::shared_ptr<Texture>>		textures;
		std::vector<std::shared_ptr<ShaderProgram>> shaders;
	public:
		Material();
		~Material();

	};

	

	

}
#endif
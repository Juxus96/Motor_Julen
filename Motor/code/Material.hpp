
#ifndef MATERIALHEADER
#define MATERIALHEADER

#include <map>
#include <Shared_Ptr.hpp>
#include "ShaderProgram.hpp"

namespace Zynkro
{
	class Material
	{
	public:
		std::map<std::string, std::shared_ptr<ShaderProgram>> shaders;
	public:
		Material();
		~Material();

	};

	

	

}
#endif

#ifndef MESHHEADER
#define MESHHEADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "ShaderProgram.hpp"

namespace Zynkro
{
	class Mesh
	{
	public:
		struct Vertex {
			float position[3];
			float normal[3];
			float textCoords[3];
		};
		struct Texture {
			unsigned int texture;
			std::string type;
			std::string path;
		};
		unsigned int VAO; 
	private:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;
		unsigned int VBO;
		unsigned int EBO;

	public:
		Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, std::vector<Texture> _textures);
		~Mesh();

		void SetUpMesh();
		void Draw(ShaderProgram shader);
	};

	

	

}
#endif
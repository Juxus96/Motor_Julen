
#ifndef MODELCOMPONENTHEADER
#define MODELCOMPONENTHEADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Component.hpp"
#include "Mesh.hpp"
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

namespace Zynkro
{
	class Mesh;
	class ModelComponent : public Component
	{
	public:
		ShaderProgram shader;
		
	private:
		

		std::vector<std::shared_ptr<Mesh>> meshes;
		std::vector<Mesh::Texture> textures_loaded;

		std::string modelPath;
	public:
		ModelComponent(std::string modelPath, const char* vertexPath, const char* fragmentPath);
		~ModelComponent();

		void Update() override;
		void Draw();
		void LoadModel(std::string path);
		void ProcessNode(aiNode *node, const aiScene *scene);
		std::shared_ptr<Mesh>  ProcessMesh(aiMesh *mesh, const aiScene *scene);
		std::vector<Mesh::Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
			std::string typeName);
		unsigned int TextureFromFile(const char *path, const std::string &directory);

	};

	

	

}
#endif
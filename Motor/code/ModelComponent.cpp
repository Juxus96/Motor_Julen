#include "ModelComponent.hpp"

namespace Zynkro 
{
	ModelComponent::ModelComponent(std::string modelPath , const char* vertexPath, const char* fragmentPath) : shader(vertexPath, fragmentPath)
	{
		LoadModel(modelPath);
	}
	ModelComponent::~ModelComponent()
	{
	}
	void ModelComponent::Update()
	{
		/*glUseProgram(materials["first"]->shaders["first"]->shaderProgram);
		glBindTexture(GL_TEXTURE_2D, materials["first"]->textures["first"]->texture);
		glBindVertexArray(meshes["first"]->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);*/
	}
	void ModelComponent::Draw()
	{
		for (unsigned int i = 0; i < meshes.size(); i++) {
			shader.Use();
			meshes[i]->Draw(shader);
		}
	}
	void ModelComponent::LoadModel(std::string path)
	{
		Assimp::Importer importer;
		const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
			return;
		}
		modelPath = path.substr(0, path.find_last_of('/'));

		ProcessNode(scene->mRootNode, scene);

	}
	void ModelComponent::ProcessNode(aiNode * node, const aiScene * scene)
	{
		aiMesh *mesh = scene->mMeshes[0];
		meshes.push_back(ProcessMesh(mesh, scene));
		// process all the node's meshes (if any)
		for (unsigned int i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(ProcessMesh(mesh, scene));
		}
		// then do the same for each of its children
		for (unsigned int i = 0; i < node->mNumChildren; i++)
		{
			ProcessNode(node->mChildren[i], scene);
		}
	}
	std::shared_ptr<Mesh> ModelComponent::ProcessMesh(aiMesh * mesh, const aiScene * scene)
	{
		std::vector<Mesh::Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Mesh::Texture> textures;

		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			Mesh::Vertex vertex;
			// process vertex positions, normals and texture coordinates
			
			vertex.position[0] = mesh->mVertices[i].x;
			vertex.position[1] = mesh->mVertices[i].y;
			vertex.position[2] = mesh->mVertices[i].z;

			vertex.normal[0] = mesh->mNormals[i].x;
			vertex.normal[1] = mesh->mNormals[i].y;
			vertex.normal[2] = mesh->mNormals[i].z;

			if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
			{
				vertex.textCoords[0] = mesh->mTextureCoords[0][i].x;
				vertex.textCoords[1] = mesh->mTextureCoords[0][i].y;
			}
			else
				vertex.textCoords[0] = vertex.textCoords[1] = 0.0f;

			vertices.push_back(vertex);
		}
		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace face = mesh->mFaces[i];
			for (unsigned int j = 0; j < face.mNumIndices; j++)
				indices.push_back(face.mIndices[j]);
		}
		if (mesh->mMaterialIndex >= 0)
		{
			aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
			std::vector<Mesh::Texture> diffuseMaps = loadMaterialTextures(material,
				aiTextureType_DIFFUSE, "texture_diffuse");
			textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
			std::vector<Mesh::Texture> specularMaps = loadMaterialTextures(material,
				aiTextureType_SPECULAR, "texture_specular");
			textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		}

		return std::make_shared<Mesh>(vertices, indices, textures);
	}
	
	std::vector<Mesh::Texture> ModelComponent::loadMaterialTextures(aiMaterial * mat, aiTextureType type, std::string typeName)
	{
		std::vector<Mesh::Texture> textures;
		for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
		{
			aiString str;
			mat->GetTexture(type, i, &str);
			bool skip = false;
			for (unsigned int j = 0; j < textures_loaded.size(); j++)
			{
				if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
				{
					textures.push_back(textures_loaded[j]);
					skip = true;
					break;
				}
			}
			if (!skip)
			{   // if texture hasn't been loaded already, load it
				Mesh::Texture texture;
				texture.texture = TextureFromFile(str.C_Str(), modelPath);
				texture.type = typeName;
				texture.path = str.C_Str();
				textures.push_back(texture);
				textures_loaded.push_back(texture); // add to loaded textures
			}
		}
		return textures;
	}

	unsigned int ModelComponent::TextureFromFile(const char *path, const std::string &directory)
	{
		std::string filename = std::string(path);
		filename = directory + '/' + filename;

		unsigned int textureID;
		glGenTextures(1, &textureID);

		int width, height, nrComponents;
		unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
		if (data)
		{
			GLenum format;
			if (nrComponents == 1)
				format = GL_RED;
			else if (nrComponents == 3)
				format = GL_RGB;
			else if (nrComponents == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else
		{
			std::cout << "Texture failed to load at path: " << path << std::endl;
			stbi_image_free(data);
		}

		return textureID;
	}
}



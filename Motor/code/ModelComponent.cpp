#include "ModelComponent.hpp"

namespace Zynkro 
{
	ModelComponent::ModelComponent(const char* textPath)
	{
		materials["first"] = std::make_shared<Material>(textPath);
		meshes["first"] = std::make_shared<Mesh>();
	}
	ModelComponent::~ModelComponent()
	{
	}
	void ModelComponent::Update()
	{
		glUseProgram(materials["first"]->shaders["first"]->shaderProgram);
		glBindTexture(GL_TEXTURE_2D, materials["first"]->textures["first"]->texture);
		glBindVertexArray(meshes["first"]->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);
	}
}



#include "TransformComponent.hpp"

namespace Zynkro 
{
	TransformComponent::TransformComponent()
	{
		translation = glm::mat4(1.0f);
		translation = glm::translate(translation, glm::vec3(.0f,.0f,.0f));
		scale = glm::mat4(1.0f);
		scale = glm::scale(scale, glm::vec3(1.0f, 1.0f, 1.0f));
		rotation = glm::mat4(1.0f);
		transform = glm::mat4(1.0f);
		angle = 0;
		axis = glm::vec3(0, 1, 0);
	}
	TransformComponent::~TransformComponent()
	{
	}
	void TransformComponent::Update()
	{
		Rotate();
	}
}



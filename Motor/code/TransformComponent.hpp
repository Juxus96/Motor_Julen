
#ifndef TRANSFORMCOMPONENTHEADER
#define TRANSFORMCOMPONENTHEADER

#include "Component.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Zynkro
{
	class TransformComponent : public Component
	{
	public:
		glm::mat4 transform;
	private:
		glm::mat4 translation;
		glm::mat4 rotation;
		glm::mat4 scale;
		glm::vec3 axis;
		float angle;

	public:
		TransformComponent();
		~TransformComponent();

		void Update() override;

		glm::mat4 GetTransform() {
			return transform = translation * rotation * scale;
		}

		void Translate(glm::vec3 _translation) { translation = glm::translate(translation, _translation); };
		void Rotate() { rotation = glm::rotate(rotation,angle, axis); };
		void Scale(glm::vec3 _scale) { scale = glm::scale(scale, _scale); };
		void SetRotation(glm::vec3 _axis, float _angle) { axis = _axis; angle = _angle; };
	};


}
#endif
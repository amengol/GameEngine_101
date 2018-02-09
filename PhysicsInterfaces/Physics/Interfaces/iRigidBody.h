#pragma once
#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>
#include "iShape.h"

namespace nPhysics
{
	class iRigidBody
	{
	public:
		virtual ~iRigidBody() {}

		virtual iShape* GetShape() = 0;

		virtual void GetTransform(glm::mat4& transformOut) = 0;
		virtual void GetPostion(glm::vec3& positionOut) = 0;
		virtual void GetRotation(glm::vec3& rotationOut) = 0;
		
	};
}
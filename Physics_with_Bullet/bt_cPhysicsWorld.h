#pragma once
#include <iPhysicsWorld.h>
#include <vector>
#include "bt_cRigidBody.h"

namespace nPhysics
{

	class bt_cPhysicsWorld : public iPhysicsWorld
	{
	public:
		virtual ~bt_cPhysicsWorld();

        struct RK4_State
        {
            glm::vec3 x;      // position
            glm::vec3 v;      // velocity
        };

        struct RK4_Derivative
        {
            RK4_Derivative() :
                dx(0.0f), dv(0.0f)
            {
            }
            glm::vec3 dx;      // dx/dt = velocity
            glm::vec3 dv;      // dv/dt = acceleration
        };

        RK4_Derivative evaluate(const RK4_State& initial,
                                float dt,
                                const RK4_Derivative& d);

        void integrate(glm::vec3& pos, glm::vec3& vel, glm::vec3 accel, float dt);

		virtual void TimeStep(float deltaTime);

		virtual void AddRigidBody(iRigidBody* rigidBody);
		virtual void RemoveRigidBody(iRigidBody* rigidBody);

	private:
		
		std::vector<bt_cRigidBody*> mRigidBody;
	};
}
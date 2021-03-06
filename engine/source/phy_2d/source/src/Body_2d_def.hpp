#ifndef _BODY_2D_DEF_HPP
#define _BODY_2D_DEF_HPP

#include "Body_2d.hpp"
#include "AABB_2d.hpp"
#include "vec2.hpp"

namespace physics_2d {
	struct Body_2d_def {
		Body_2d_def() 
		{
			m_type = Body_2d::Entity_types::STATIC;
			m_position.zero();
			m_linear_velocity.zero();
			m_vel_threshold.zero();
			m_acceleration.zero();
			m_mass = 1;
			m_gravity_scale = 1.0f;
			m_map_collision = true;
		}

		Body_2d::Entity_types	m_type;
		float					m_mass;
		float					m_gravity_scale;
		math::vec2				m_position;
		math::vec2				m_linear_velocity;
		math::vec2              m_vel_threshold;
		math::vec2				m_acceleration;
		AABB_2d					m_aabb;
		bool					m_map_collision;
	};
}
#endif // !_BODY_2D_DEF_HPP

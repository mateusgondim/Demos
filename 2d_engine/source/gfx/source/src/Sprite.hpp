#ifndef _SPRITE_HPP
#define _SPRITE_HPP

#include "vec2.hpp"
#include "vec3.hpp"
#include "Sprite_atlas.hpp"

#include <vector>
#include <memory>
#include <string>
#include <utility>

/*
 *
 */
//TODO: Maybe add a change direction function
namespace gfx { class Animator_controller; }

namespace gfx {
	class Sprite {
	public:
		Sprite(const std::string & file_name, const float pixels_per_unit = 16.0f);
		const	std::vector<math::vec3> & get_vertex_position_vec() const { return m_vertices_pos; }
				std::vector<math::vec3> & get_vertex_position_vec()       { return m_vertices_pos;}
		const	std::vector<math::vec2> & get_vertex_uv_vec()	   const { return m_vertices_uv; };
				unsigned                 get_pixels_per_unit()	   const {return m_pixels_per_unit;}
		std::shared_ptr<const Sprite_atlas> get_atlas()		       const {return m_atlas;}

		void   update_pos(const math::vec3 & position, const bool facing_left = true);
		void   update_uv(const int sprite_no);
		//bool   is_animated() const;
		void   update_animation(const float dt, Animator_controller *pcontroller);
	private:
		std::vector<math::vec3>				m_vertices_pos;
		std::vector<math::vec2>				m_vertices_uv;
		float								m_pixels_per_unit; // number of pixels per game world's unit
		math::vec2                           m_scale;           // scale taking into account the pixels per world unit
		std::shared_ptr<const Sprite_atlas>	m_atlas;
	
		std::pair<unsigned, unsigned>		m_curr_anim_n_frame;
		
		//unsigned                           m_controller_curr_anim;
		//TODO: SCALE THE VERTICES IN THE POSITION VECTOR WHEN CHANGING THE CURRENT VERTEX UV COORDINATES
		//std::vector<unsigned> m_elements
	};
}

#endif // !_SPRITE_HPP

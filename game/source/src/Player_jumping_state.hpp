#ifndef _PLAYER_JUMPING_STATE_HPP
#define _PLAYER_JUMPING_STATE_HPP

#include "Gameplay_state.hpp"
#include "AABB_2d.hpp"

namespace gom { class Actor; }
namespace physics_2d { struct AABB_2d; }

class Player_jumping_state : public gom::Gameplay_state {
public:
        Player_jumping_state(gom::Actor & actor, float jump_vel = 15.0f, float x_vel = 5.0f);

        gom::Gameplay_state *           handle_input(gom::Actor & actor) override;
        size_t                          get_size() const  override;
        //void update(Actor & actor) override;

        void                            begin_tile_collision(gom::Actor & actor, const physics_2d::AABB_2d & tile_aabb) override;
        void                            end_tile_collision(gom::Actor & actor, const physics_2d::AABB_2d & tile_aabb) override;
private:
        float                           m_jump_vel;
        float                           m_x_vel;
        //	bool m_moving_left;
        //	bool m_moving_right;
};

#endif // !_PLAYER_JUMPING_STATE_HPP

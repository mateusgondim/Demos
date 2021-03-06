#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include "Transform.hpp"
#include <stdint.h>

/* Game_object: The base class for all the entities in the game world.
 * This engine uses a component approach to its object model,
 * so the game object class works as a hub of components, each providing a specific functionallity
 * to the object, classes that inherent from this class, should initialize the needed components and
 * add new ones if necessary.
 */
 //TODO: CHANGE THE ORIENTATION TO BE A 3X3 MATRIX!

namespace gfx { class Sprite; class Animator_controller; }
namespace physics_2d { class Body_2d; }
namespace gom { class Game_object_manager; }
class Event;

namespace gom {
        class Game_object {
                friend Game_object_manager;
        public:
                typedef uint32_t game_object_id;

                Game_object(std::size_t alloc_sz);
                Game_object(std::size_t alloc_sz, const math::Transform & transform);
                Game_object(std::size_t alloc_sz, const math::vec3 & position);

                Game_object(const Game_object & game_object) = delete;
                Game_object(Game_object && game_object) = delete;
                Game_object & operator=(const Game_object & rhs) = delete;

                void                  destroy();

                game_object_id        get_unique_id() const;
                uint16_t			  get_handle_index() const;
                bool				  is_active() const { return m_is_active; }
                void				  set_active(const bool flag);

                void				 set_type(const uint32_t object_type) { m_type = object_type; }
                uint32_t			 get_type() const { return m_type; }

                void                set_tag(const uint32_t object_tag) { m_tag = object_tag; }
                uint32_t            get_tag() const { return m_tag; }

                math::Transform     & get_transform_component();
                gfx::Sprite          *get_sprite_component();
                gfx::Animator_controller  *get_anim_controller_component();
                physics_2d::Body_2d  *get_body_2d_component();

                virtual void update(const float dt) = 0;
                virtual void on_event(Event & event);
        protected:
                virtual ~Game_object();
                math::Transform				 m_transform;//
                gfx::Sprite					*m_psprite;// 4 bytes
                gfx::Animator_controller	*m_panimator_controller; // 4 bytes
                physics_2d::Body_2d			*m_pbody_2d; // 4 bytes
        private:
                game_object_id	m_unique_id;
                uint16_t		m_handle_index;

                uint32_t        m_type; // type used to identify the specific game object's type, as "player" or "hover_robot" 
                uint32_t        m_tag;  // value used to identify a broader group of game objects, as 'Enemies', 'Items' etc

                bool			m_is_active;
        };
}
#endif // !_GAME_OBJECT_HPP

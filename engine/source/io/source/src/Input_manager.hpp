#ifndef _INPUT_MANAGER_HPP
#define _INPUT_MANAGER_HPP

#include "Keyboard_state.hpp"
#include "Keyboard_button_mapper.hpp"

namespace io
{
        /**
         * Interface to access the keyboard's buttons state by user defined indexes and,
         * configurate the current keyboard's control scheme.
         */
        class Input_manager {
        public:
                void poll_events(); 
                // void init();
                // void shut_down();

                // Returns true if the button was pressed this frame
                bool    get_button_down(uint32_t action_index) const;
                // Returns true if button was released this frame
                bool    get_button_up(uint32_t action_index) const;
                // Returns true if button is pressed
                bool    get_button(uint32_t action_index) const;
                Keyboard_button_mapper  & get_keyboard_control_scheme() { return m_keyboard_control_scheme; }
        private:
                Keyboard_state          m_keyboard_state;
                Keyboard_button_mapper  m_keyboard_control_scheme;
        };

        extern Input_manager    g_input_mgr;
}

#endif // !_INPUT_MANAGER_HPP

#ifndef _ENGINE_HPP
#define _ENGINE_HPP

#include <stdint.h>

//utility
#include "Timer.hpp"
//physics
#include "Physics_manager.hpp"
//input
#include "Input_manager.hpp"
// graphics
#include "Graphics_manager.hpp"

class Tile_map;

class Engine final {
public:
	Engine() = default;
	void init(const uint32_t context_version_major, const uint32_t context_version_minor, Tile_map *ptile_map);
	void shut_down();
	~Engine() {}
public:
	Timer						 m_timer;
	physics_2d::Physics_manager  m_physics_manager;
	gfx::Graphics_manager        m_graphics_manager;
	Input_manager				 m_input_manager;
};

extern Engine g_engine;
#endif // !_ENGINE_HPP

#include "kys/Engine.hpp"
#include <fmt/core.h>

namespace kys {

Engine::Engine()
{
}

Engine::~Engine()
{
    destroy();
}

void Engine::destroy()
{
    fmt::print("TODO: put SDL related release here\n");
}

int Engine::init()
{
    fmt::print("TODO: call SDL related init here\n");
    return 0;
}

void Engine::setStartWindowSize(int a_width, int a_height)
{
    m_start_window_width = a_width;
    m_start_window_height = a_height;
}

} // namespace kys
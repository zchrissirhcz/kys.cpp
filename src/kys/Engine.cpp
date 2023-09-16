#include "kys/Engine.hpp"
#include <fmt/core.h>

namespace kys {

Engine::Engine()
{
    fmt::print("Engine created\n");
}

Engine::~Engine()
{
    fmt::print("Good bye\n");
}

int Engine::init()
{
    fmt::print("TODO: install and use SDL here\n");
    return 0;
}

void Engine::setStartWindowSize(int a_width, int a_height)
{
    m_start_window_width = a_width;
    m_start_window_height = a_height;
}

} // namespace kys
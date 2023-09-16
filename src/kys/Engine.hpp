#pragma once

namespace kys {

class Engine
{
public:
    Engine();
    ~Engine();
    void setStartWindowSize(int a_width, int a_height);
    int init();

private:
    int m_start_window_height;
    int m_start_window_width;
};

} // namespace kys
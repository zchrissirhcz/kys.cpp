#pragma once

namespace kys {

class Engine
{
private:
    Engine();
    ~Engine();

public:
    static Engine* getInstance()
    {
        static Engine e;
        return &e;
    }
    void setStartWindowSize(int a_width, int a_height);
    int init();

private:
    void destroy();

private:
    int m_start_window_height;
    int m_start_window_width;
};

} // namespace kys
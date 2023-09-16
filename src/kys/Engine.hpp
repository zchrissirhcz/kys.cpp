#pragma once

#include <memory>

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
    class Impl;
    std::unique_ptr<Impl> d_ptr;
};

} // namespace kys
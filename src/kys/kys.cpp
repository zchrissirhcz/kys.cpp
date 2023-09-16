#include <memory>
#include <fmt/core.h>
#include "kys/GameUtil.hpp"
#include "kys/Application.hpp"

int main(int argc, char** argv)
{
    using namespace kys;
    GameUtil* gu = GameUtil::getInstance();
    if (argc >= 2)
    {
        gu->path() = argv[1];
    }
    fmt::print("Game path is {}\n", gu->path());
    kys::Application app;
    return app.run();
}

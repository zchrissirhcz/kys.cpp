#include "Application.hpp"

#include <memory>
#include <fmt/core.h>

#include "kys/Engine.hpp"
#include "kys/TitleScene.hpp"

namespace kys {

int Application::run()
{
    fmt::print("Hello, KYS\n");

    Engine* engine = Engine::getInstance();
    engine->setStartWindowSize(1280, 720);
    engine->init();

    std::unique_ptr<TitleScene> scene(new TitleScene);
    scene->run();

    return 0;
};

} // namespace kys
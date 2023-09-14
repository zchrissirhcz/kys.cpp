#include <memory>
#include <fmt/core.h>

namespace kys {

class Engine
{
public:
    Engine()
    {
        fmt::print("Engine created\n");
    }
    ~Engine()
    {
        fmt::print("Good bye\n");
    }

    void setStartWindowSize(int a_width, int a_height)
    {
        m_start_window_width = a_width;
        m_start_window_height = a_height;
    }

    int init()
    {
        fmt::print("TODO: install and use SDL here\n");
        return 0;
    }

private:
    int m_start_window_height;
    int m_start_window_width;
};

class TitleScene
{
public:
    int run()
    {
        fmt::print("Welcome to TitleScene\n");
        return 0;
    }
};

class Application
{
public:
    int run()
    {
        fmt::print("Hello, KYS\n");

        std::unique_ptr<Engine> engine(new Engine);
        engine->setStartWindowSize(1280, 720);
        engine->init();

        std::unique_ptr<TitleScene> scene(new TitleScene);
        scene->run();

        return 0;
    }
};

} // namespace kys

int main(int argc, char** argv)
{
    kys::Application app;
    return app.run();
}

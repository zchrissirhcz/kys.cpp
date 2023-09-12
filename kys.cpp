#include <iostream>
#include <memory>

namespace kys {

class Engine
{
public:
    Engine()
    {
        std::cout << "Engine created\n";
    }
    ~Engine()
    {
        std::cout << "Good bye" << std::endl;
    }

    void setStartWindowSize(int a_width, int a_height)
    {
        m_start_window_width = a_width;
        m_start_window_height = a_height;
    }

    int init()
    {
        std::cout << "TODO: install and use SDL here" << std::endl;
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
        std::cout << "Welcome to TitleScene" << std::endl;
        return 0;
    }
};

class Application
{
public:
    int run()
    {
        std::cout << "Hello, KYS" << std::endl;

        std::unique_ptr<Engine> engine(new Engine);
        engine->setStartWindowSize(1280, 720);
        engine->init();

        std::unique_ptr<TitleScene> scene(new TitleScene);
        scene->run();

        return 0;
    }
}; // namespace kys

} // namespace

int main(int argc, char** argv)
{
    kys::Application app;
    return app.run();
}

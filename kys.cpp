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

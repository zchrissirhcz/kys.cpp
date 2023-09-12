#include <iostream>

class Application
{
public:
    int run()
    {
        std::cout << "Hello, KYS" << std::endl;
        return 0;
    }
};

int main(int argc, char** argv)
{
    Application app;
    return app.run();
}

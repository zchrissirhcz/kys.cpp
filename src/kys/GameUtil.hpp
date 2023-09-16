#pragma once

#include <string>

namespace kys {

class GameUtil
{
private:
    GameUtil() { }
    ~GameUtil() { }
public:
    static GameUtil* getInstance()
    {
        static GameUtil gu;
        return &gu;
    }

    static std::string& path()
    {
        static std::string s = "../game/";
        return s;
    }
};

} // namespace kys
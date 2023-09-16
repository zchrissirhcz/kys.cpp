#include "kys/Engine.hpp"
#include <fmt/core.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace kys {

using BP_Renderer = SDL_Renderer;
using BP_Window = SDL_Window;
using BP_Texture = SDL_Texture;
using BP_Rect = SDL_Rect;
using BP_Color = SDL_Color;
using BP_Keycode = SDL_Keycode;
using BP_Surface = SDL_Surface;
using BP_GameController = SDL_GameController;
using BP_Haptic = SDL_Haptic;

class Engine::Impl
{
public:
    Impl() { }
    ~Impl() { }
    void setStartWindowSize(int a_width, int a_height);
    int init();
    void destroy();

private:
    BP_Texture* loadImage(const std::string& filename, int as_white = 0);
    void toWhite(BP_Surface* sur);
    void renderCopy(BP_Texture* t, BP_Rect* rect0, BP_Rect* rect1, double angle = 0, int inPresent = 0);
    void renderPresent();

    void showLogo() { renderCopy(logo_, nullptr, nullptr); }
    void destroyAssistTexture();
    static void destroyTexture(BP_Texture* t) { SDL_DestroyTexture(t); }


    std::string title_ = "All Heroes in Kam Yung Stories";
    
    int start_w_ = 1024;
    int start_h_ = 640;

    BP_Window* window_ = nullptr;
    BP_Renderer* renderer_ = nullptr;
    BP_Texture* tex2_ = nullptr;
    BP_Texture* logo_ = nullptr;
    BP_Rect rect_;
    BP_GameController* game_controller_ = nullptr;
    BP_Haptic* haptic_ = nullptr;
    int switch_ = 0;

    int render_times_ = 0;
};

void Engine::Impl::destroyAssistTexture()
{
    if (tex2_)
    {
        destroyTexture(tex2_);
    }
}

void Engine::Impl::destroy()
{
    //SDL_DestroyTexture(tex_);
    destroyAssistTexture();
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
#if defined(_WIN32) && defined(WITH_SMALLPOT) && !defined(_DEBUG)
    PotDestory(tinypot_);
#endif
    SDL_Quit();
}

void Engine::Impl::renderCopy(BP_Texture* t, BP_Rect* rect0, BP_Rect* rect1, double angle, int inPresent /*= 0*/)
{
    SDL_RenderCopyEx(renderer_, t, rect0, rect1, angle, nullptr, SDL_FLIP_NONE);
    render_times_++;
}

void Engine::Impl::setStartWindowSize(int a_width, int a_height)
{
    start_w_ = a_width;
    start_h_ = a_height;
}

BP_Texture* Engine::Impl::loadImage(const std::string& filename, int as_white)
{
    //fmt1::print("%s", filename.c_str());
    auto sur = IMG_Load(filename.c_str());
    if (as_white) { toWhite(sur); }
    auto tex = SDL_CreateTextureFromSurface(renderer_, sur);
    SDL_FreeSurface(sur);
    return tex;
}

void Engine::Impl::toWhite(BP_Surface* sur)
{
    for (int i = 0; i < sur->w * sur->h; i++)
    {
        auto p = (uint32_t*)sur->pixels + i;
        uint8_t r, g, b, a;
        SDL_GetRGBA(*p, sur->format, &r, &g, &b, &a);
        if (a == 0)
        {
            *p = SDL_MapRGBA(sur->format, 255, 255, 255, 0);
        }
        else
        {
            *p = SDL_MapRGBA(sur->format, 255, 255, 255, 255);
        }
    }
}

void Engine::Impl::renderPresent()
{
    SDL_RenderPresent(renderer_);
}


int Engine::Impl::init()
{
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC))
    {
        return -1;
    }

    window_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        start_w_, start_h_, SDL_WINDOW_RESIZABLE);

    SDL_ShowWindow(window_);
    SDL_RaiseWindow(window_);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE /*| SDL_RENDERER_PRESENTVSYNC*/);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_EventState(SDL_DROPFILE, SDL_ENABLE);

    //屏蔽触摸板
    SDL_EventState(SDL_FINGERUP, SDL_DISABLE);
    SDL_EventState(SDL_FINGERDOWN, SDL_DISABLE);
    SDL_EventState(SDL_FINGERMOTION, SDL_DISABLE);

    //手柄
    if (SDL_NumJoysticks() < 1)
    {
        fmt::print("Warning: No joysticks connected!\n");
    }
    else
    {
        //按照游戏控制器打开
        game_controller_ = SDL_GameControllerOpen(0);
        if (game_controller_)
        {
            fmt::print("Found {} game controller(s)\n", SDL_NumJoysticks());
            std::string name = SDL_GameControllerName(game_controller_);
            fmt::print("{}\n", name);
            if (name.find("Switch") != std::string::npos) { switch_ = 1; }
        }
        else
        {
            fmt::print("Warning: Unable to open game controller! SDL Error: {}\n", SDL_GetError());
        }
    }

    rect_ = { 0, 0, start_w_, start_h_ };
    logo_ = loadImage("logo.png");
    showLogo();
    renderPresent();
    TTF_Init();

    return 0;
}

Engine::Engine() :
    d_ptr(new Engine::Impl)
{
}

Engine::~Engine()
{
    d_ptr->destroy();
}

int Engine::init()
{
    return d_ptr->init();
}

void Engine::setStartWindowSize(int a_width, int a_height)
{
    d_ptr->setStartWindowSize(a_width, a_height);
}

} // namespace kys
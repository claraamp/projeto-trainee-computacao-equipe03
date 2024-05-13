#include "simulator.h"
#include "circle.h"
#include "utils.h"

using namespace std;

Simulator::Simulator(RenderData &renderData, Circle ball, Circle robot) : quit(false), renderData(renderData), ball(ball), robot(robot)
{
}

Simulator::~Simulator()
{
    SDL_DestroyRenderer(renderData.renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Simulator::init()
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow(
        "Simulador",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        renderData.SCREEN_WIDTH,
        renderData.SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN //
    );
    if (window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }
    renderData.renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderData.renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        printf("Renderer could not be created! Error: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    return true;
}

void Simulator::handleEvent()
{
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        {
            quit = true;
        }
        else
        {
            robot.SDLEventToVelocity(e);
        }
    }
}

void Simulator::update(float deltaTime)
{
    SDL_SetRenderDrawColor(renderData.renderer, 79, 121, 66, 255);
    SDL_RenderClear(renderData.renderer);

    SDL_Rect goalRectL;
    goalRectL.x = 5;
    goalRectL.y = 240;
    goalRectL.w = 25;
    goalRectL.h = 100;

    SDL_Rect goalRectR;
    goalRectR.x = renderData.SCREEN_WIDTH - (5 + 25);
    goalRectR.y = 240;
    goalRectR.w = 25;
    goalRectR.h = 100;

    SDL_SetRenderDrawColor(renderData.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderData.renderer, &goalRectL);
    SDL_RenderFillRect(renderData.renderer, &goalRectR);

    ball.render(0xFF, 0xFF, 0xFF, 0xFF);
    robot.render(0x00, 0x00, 0x8A, 0xFF);

    SDL_RenderPresent(renderData.renderer);
}

void Simulator::run()
{
    update(0.0f);

    Uint32 lastTicks = 0;
    while (!quit)
    {
        handleEvent();

        Uint32 currentTicks = SDL_GetTicks();
        float dt = 1 - (static_cast<float>(currentTicks - lastTicks) / 1000.0f);

        ball.move(1.0f);
        robot.move(1.0f);
        update(1.0f);

        lastTicks = currentTicks;

        if (checkCircleCollisionOptimized(ball.toCheck(), robot.toCheck()))
        {
            Vec2 result;
            result.x = (ball.position.x - robot.position.x) * 0.2;
            result.y = (ball.position.y - robot.position.y) * 0.2;

            ball.setVelocity(result);
        }
    }
}

#include "simulator.h"
#include "circle.h"
#include <iostream>

using namespace std;

Simulator::Simulator(RenderData *renderData, Circle ball) : quit(false), renderData(renderData), ball(ball)
{
}

Simulator::~Simulator()
{
    SDL_DestroyRenderer(renderData->renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Simulator::init()
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    window = SDL_CreateWindow(
        "Simulador",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        renderData->SCREEN_WIDTH,
        renderData->SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN //
    );
    if (window == nullptr)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return false;
    }
    renderData->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderData->renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        cout << "Renderer could not be created! Error: " << SDL_GetError() << endl;
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
        else if (e.type == SDL_KEYDOWN)
        {
            ball.handleEvent(e);
            handleKeyEvents(e);
        }
    }
}

void Simulator::handleKeyEvents(const SDL_Event &e)
{
    switch (e.key.keysym.sym)
    {
    // DUPLICATE, just as example on how to do this
    case SDLK_ESCAPE:
        quit = true;
        break;
    default:
        break;
    }
}

void Simulator::update(float deltaTime)
{
    SDL_SetRenderDrawColor(renderData->renderer, 79, 121, 66, 255);
    SDL_RenderClear(renderData->renderer);

    SDL_Rect goalRectL;
    goalRectL.x = 5;
    goalRectL.y = 240;
    goalRectL.w = 25;
    goalRectL.h = 100;

    SDL_Rect goalRectR;
    goalRectR.x = renderData->SCREEN_WIDTH - (5 + 25);
    goalRectR.y = 240;
    goalRectR.w = 25;
    goalRectR.h = 100;

    SDL_SetRenderDrawColor(renderData->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderData->renderer, &goalRectL);
    SDL_RenderFillRect(renderData->renderer, &goalRectR);

    ball.render();

    SDL_RenderPresent(renderData->renderer);
}

void Simulator::run()
{
    update(0.0f);

    Uint32 lastTicks = 0;
    while (!quit)
    {
        handleEvent();

        Uint32 currentTicks = SDL_GetTicks();
        float dt = static_cast<float>(currentTicks - lastTicks) / 1000.0f;

        ball.move(1.0f);
        update(dt);

        lastTicks = currentTicks;
    }
}

#include "simulator.h"
#include "circle.h"

Circle::Circle(RenderData &renderData, Vec2 pos, int radius) : renderData(renderData), position(pos), velocity({0, 0}), radius(radius)
{
}

void Circle::setPosition(Vec2 pos)
{
  position = pos;
}

void Circle::setVelocity(Vec2 vel)
{
  velocity = vel;
}

void Circle::SDLEventToVelocity(SDL_Event &e)
{
  if (e.type == SDL_KEYDOWN)
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_w:
      velocity.y = -CIRCLE_VEL;
      break;
    case SDLK_s:
      velocity.y = +CIRCLE_VEL;
      break;
    case SDLK_a:
      velocity.x = -CIRCLE_VEL;
      break;
    case SDLK_d:
      velocity.x = +CIRCLE_VEL;
      break;
    }
  }
  if (e.type == SDL_KEYUP)
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_w:
      velocity.y = 0;
      break;
    case SDLK_s:
      velocity.y = 0;
      break;
    case SDLK_a:
      velocity.x = 0;
      break;
    case SDLK_d:
      velocity.x = 0;
      break;
    }
  }
}

void Circle::move(float deltaTime)
{
  position.x += (velocity.x * deltaTime);
  position.y += (velocity.y * deltaTime);

  if ((position.x - radius < 0) || (position.x + radius > renderData.SCREEN_WIDTH))
  {
    position.x += (velocity.x * deltaTime);
  }

  if ((position.y - radius < 0) || (position.y + radius > renderData.SCREEN_HEIGHT))
  {
    position.y += (velocity.y * deltaTime);
  }
}

void Circle::render(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_SetRenderDrawColor(renderData.renderer, r, g, b, a);
  SDL_RenderFillCircle(renderData.renderer, position.x, position.y, radius);
}

CircleCheck Circle::toCheck()
{
  float x = static_cast<float>(position.x);
  float y = static_cast<float>(position.y);
  float r = radius / 2;
  return CircleCheck{x, y, r};
}

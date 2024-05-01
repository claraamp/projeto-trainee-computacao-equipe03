#include "simulator.h"
#include "circle.h"

Circle::Circle(RenderData &renderData, int x, int y, int radius) : renderData(renderData), mPosX(x), mPosY(y), mVelX(0), mVelY(0), radius(radius)
{
}

void Circle::handleEvent(SDL_Event &e)
{
  // If a key was pressed
  if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
  {
    // Adjust the velocity
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:
      mVelY -= CIRCLE_VEL;
      break;
    case SDLK_DOWN:
      mVelY += CIRCLE_VEL;
      break;
    case SDLK_LEFT:
      mVelX -= CIRCLE_VEL;
      break;
    case SDLK_RIGHT:
      mVelX += CIRCLE_VEL;
      break;
    }
  }
  else if (e.type == SDL_KEYUP && e.key.repeat == 0)
  {
    // Adjust the velocity
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:
      mVelY += CIRCLE_VEL;
      break;
    case SDLK_DOWN:
      mVelY -= CIRCLE_VEL;
      break;
    case SDLK_LEFT:
      mVelX += CIRCLE_VEL;
      break;
    case SDLK_RIGHT:
      mVelX -= CIRCLE_VEL;
      break;
    }
  }
}

void Circle::move(float deltaTime)
{
  mPosX += (mVelX * deltaTime);
  mPosY += (mVelY * deltaTime);

  if ((mPosX - radius < 0) || (mPosX + radius > renderData.SCREEN_WIDTH))
  {
    mPosX -= (mVelX * deltaTime);
  }

  if ((mPosY - radius < 0) || (mPosY + radius > renderData.SCREEN_HEIGHT))
  {
    mPosY -= (mVelY * deltaTime);
  }
}

void Circle::render(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_SetRenderDrawColor(renderData.renderer, r, g, b, a);
  SDL_RenderFillCircle(renderData.renderer, mPosX, mPosY, radius);
}

CircleCheck Circle::toCheck()
{
  float x = static_cast<float>(mPosX);
  float y = static_cast<float>(mPosY);
  float r = radius / 2;
  return CircleCheck{x, y, r};
}

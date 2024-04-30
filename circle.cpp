#include "simulator.h"
#include "circle.h"

Circle::Circle(RenderData *renderData, int x, int y) : renderData(renderData), mPosX(x), mPosY(y), mVelX(0), mVelY(0)
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

  if ((mPosX < 0) || (mPosX + CIRCLE_RADIUS > renderData->SCREEN_WIDTH))
  {
    mPosX -= (mVelX * deltaTime);
  }

  if ((mPosY < 0) || (mPosY + CIRCLE_RADIUS > renderData->SCREEN_HEIGHT))
  {
    mPosY -= (mVelY * deltaTime);
  }
}

void Circle::render(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_SetRenderDrawColor(renderData->renderer, r, g, b, a);
  SDL_RenderFillCircle(renderData->renderer, mPosX, mPosY, CIRCLE_RADIUS);
}

/**
 * Implementation from here https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
 */
int SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius)
{
  int offsetx, offsety, d;
  int status;

  // CHECK_RENDERER_MAGIC(renderer, -1);

  offsetx = 0;
  offsety = radius;
  d = radius - 1;
  status = 0;

  while (offsety >= offsetx)
  {

    status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                 x + offsety, y + offsetx);
    status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                 x + offsetx, y + offsety);
    status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                 x + offsetx, y - offsety);
    status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                 x + offsety, y - offsetx);

    if (status < 0)
    {
      status = -1;
      break;
    }

    if (d >= 2 * offsetx)
    {
      d -= 2 * offsetx + 1;
      offsetx += 1;
    }
    else if (d < 2 * (radius - offsety))
    {
      d += 2 * offsety - 1;
      offsety -= 1;
    }
    else
    {
      d += 2 * (offsety - offsetx - 1);
      offsety -= 1;
      offsetx += 1;
    }
  }

  return status;
}

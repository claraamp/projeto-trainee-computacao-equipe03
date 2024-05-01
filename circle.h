#ifndef ball_h
#define ball_h

#include "SDLConfig.h"
#include "renderData.h"
#include "utils.h"

class Circle
{
public:
  // Maximum axis velocity of the ball
  static const int CIRCLE_VEL = 1;

  // Initializes the variables
  Circle(RenderData &renderData, int x, int y, int radius);

  // The dimensions of the ball
  int radius = 20;

  // Takes key presses and adjusts the ball's velocity
  void handleEvent(SDL_Event &e);

  // Moves the ball
  void move(float deltaTime);

  // Shows the ball on the screen
  void render(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  CircleCheck toCheck();

  RenderData &renderData;
  // The X and Y offsets of the ball
  int mPosX, mPosY;

  // The velocity of the ball
  int mVelX, mVelY;

private:
};

int SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius);

#endif // ball_h

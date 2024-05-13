#ifndef ball_h
#define ball_h

#include "SDLConfig.h"
#include "renderData.h"
#include "utils.h"

struct Vec2
{
  float x = 0;
  float y = 0;
};

class Circle
{
public:
  // Maximum axis velocity of the ball
  static const int CIRCLE_VEL = 1;

  // Initializes the variables
  Circle(RenderData &renderData, Vec2 pos, int radius);

  // The dimensions of the ball
  int radius = 20;

  // Takes key presses and adjusts the ball's velocity
  void SDLEventToVelocity(SDL_Event &e);

  // Moves the ball
  void move(float deltaTime);
  void setPosition(Vec2 pos);
  void setVelocity(Vec2 vel);

  // Shows the ball on the screen
  void render(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  CircleCheck toCheck();

  RenderData &renderData;
  // The X and Y offsets of the ball

  Vec2 position;
  Vec2 velocity;

private:
};

int SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius);

#endif // ball_h

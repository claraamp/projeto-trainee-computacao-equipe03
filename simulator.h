
#ifndef simulator_h
#define simulator_h

#include "SDLConfig.h"
#include "circle.h"
#include "renderData.h"

class Simulator
{
public:
  Simulator(RenderData *renderData, Circle circle, Circle robot);
  ~Simulator();

  bool init();
  void run();
  void update(float deltaTime);
  void handleEvent();
  void handleKeyEvents(const SDL_Event &e);

  RenderData *renderData;

private:
  SDL_Window *window;
  bool quit;
  SDL_Event e;

  Circle ball;
  Circle robot;
};

#endif // simulator_h

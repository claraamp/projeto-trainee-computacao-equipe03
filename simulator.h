#ifndef simulator_h
#define simulator_h

#include "SDLConfig.h"

class Simulator
{
public:
  Simulator();
  ~Simulator();

  bool init();
  void run();
  void update(float deltaTime);
  void handleEvent();
  void handleKeyEvents(const SDL_Event &e);

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool quit;
  SDL_Event e;

  static const int width = 900;
  static const int height = 600;
};

#endif

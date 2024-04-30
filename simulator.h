#ifndef simulator_h
#define simulator_h

#include <SDL.h>
#include <SDL_image.h>
#include "robo.h"

class Simulator {
    public:
      Simulator();
      ~Simulator();

      bool init();
      void render();
      void handleEvent();
      void clean();


    private:
      SDL_Window *window;
      SDL_Renderer *renderer;
      Robo robo;
};

#endif
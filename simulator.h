#ifndef simulator_h
#define simulator_h

#include <SDL.h>

class Simulator {
    public:
      Simulator();
      ~Simulator();

      bool init();
      void handleEvent();
      void update();
      void render();
      void clean();


    private:
      SDL_Window *window;
      SDL_Renderer *renderer;
};

#endif
#ifndef robo_h
#define robo_h

#include <SDL.h>

class Robo {
    public:
      Robo(int x, int y, int width, int height);
      void draw(SDL_Renderer *renderer);

    private:
      SDL_Rect rect;
};

#endif
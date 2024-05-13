
#ifndef render_utils_h
#define render_utils_h

#include "SDLConfig.h"

class RenderData
{
public:
  SDL_Renderer *renderer;
  static const int SCREEN_WIDTH = 900;
  static const int SCREEN_HEIGHT = 600;
};

#endif // render_utils_h

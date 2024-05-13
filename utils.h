#ifndef utils_h
#define utils_h

#include "SDLConfig.h"

struct CircleCheck
{
  float centerX, centerY;
  float radius;
};

float distanceBetweenPoints(float x1, float y1, float x2, float y2);

bool checkCircleCollisionOptimized(const CircleCheck &circle1, const CircleCheck &circle2);

int SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius);

#endif // utils_h


#include <iostream>
#include <cmath>
#include <climits>

#include "utils.h"

float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool checkCircleCollisionOptimized(const CircleCheck &circle1, const CircleCheck &circle2)
{
  // Calculate the difference between the centers of the circles and their sum.
  float dx = (circle2.centerX - circle1.centerX);
  float dy = (circle2.centerY - circle1.centerY);
  float h = (circle1.radius + circle2.radius);

  // Calculate the potential collision point on one of the circles' perimeter as described above.
  float i = h / distanceBetweenPoints(circle1.centerX, circle1.centerY, circle2.centerX, circle2.centerY);
  float t = 0.5f * (fabs(dx) + fabs(dy)); // Avoid negative square root by taking the absolute value of both dx and dy

  float q = t - i;
  float g1 = (t + q) / (2.0f * h); // Fraction of A's circle radius
  float g2 = (t - q) / (2.0f * h); // Fraction of B's circle radius

  // Check if both fractions are in the range [0, 1] and return true for collision
  return (g1 >= 0) && (g1 <= 1) && (g2 >= 0) && (g2 <= 1);
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

#include "simulator.cpp"
#include "circle.h"

int main(int argc, char *argv[])
{
  RenderData renderData;
  Circle ball(&renderData, renderData.SCREEN_WIDTH / 2, renderData.SCREEN_HEIGHT / 2);
  Simulator simulator(&renderData, ball);

  if (!simulator.init())
  {
    return 1;
  }

  simulator.run();

  return 0;
}

#include "simulator.cpp"
#include "circle.h"

int main(int argc, char *argv[])
{
  RenderData renderData;
  Circle ball(renderData, {renderData.SCREEN_WIDTH / 2, renderData.SCREEN_HEIGHT / 2}, 20);
  Circle robot(renderData, {(renderData.SCREEN_WIDTH / 2) + 80, renderData.SCREEN_HEIGHT / 2}, 30);
  Simulator simulator(renderData, ball, robot);

  if (!simulator.init())
  {
    return 1;
  }

  simulator.run();

  return 0;
}

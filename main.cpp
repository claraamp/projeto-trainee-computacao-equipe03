#include "simulator.cpp"

int main(int argc, char *argv[])
{
  Simulator simulator;

  if (!simulator.init())
  {
    return 1;
  }

  simulator.run();

  return 0;
}

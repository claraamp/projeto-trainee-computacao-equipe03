#include "simulator.cpp"

Simulator simulator;

int main(int argc, char *argv[]) {

  if (!simulator.init()) {
        return 1;
    }
  
    simulator.render();
    simulator.handleEvent();
    simulator.clean();

    return 0;
}

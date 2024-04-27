#include <SDL.h>
#include "simulator.h"
#include <iostream>

using namespace std;

Simulator::Simulator()
{}
Simulator::~Simulator()
{}

bool Simulator::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
	  cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	  return false; 
  }
    window = SDL_CreateWindow("Simulador", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr){
	  cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
	  SDL_Quit();
	  return false;
  }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
	  SDL_DestroyWindow(window);
	  cout << "Renderer could not be created! Error: " << SDL_GetError() << endl;
	  SDL_Quit();
	  return false;
  }
  return true;
  
}

void Simulator::render()
{
    SDL_SetRenderDrawColor(renderer, 79, 121, 66, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Simulator::handleEvent()
{
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
}

void Simulator::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




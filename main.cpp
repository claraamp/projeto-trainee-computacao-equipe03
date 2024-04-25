#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  SDL_Window *window = nullptr;
  SDL_Surface *screenSurface = nullptr;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
  else 
  {
      window = SDL_CreateWindow("Simulador", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
      if(window == nullptr)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
      else
        {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 79, 121, 66));
            SDL_Rect goalRect;
            goalRect.x = 5;
            goalRect.y = 240;
            goalRect.w = 25;  
            goalRect.h = 100;
            SDL_FillRect(screenSurface, &goalRect, SDL_MapRGB(screenSurface->format, 255, 255, 255));

            SDL_UpdateWindowSurface(window);
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
  }


  SDL_FreeSurface(screenSurface);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
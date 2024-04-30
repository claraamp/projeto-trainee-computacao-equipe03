#include <SDL.h>
#include "robo.h"

Robo::Robo(int x, int y, int width, int height) {
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

void Robo::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 27, 27, 27, 255); 

    SDL_RenderFillRect(renderer, &rect);
}
#include "interface.hpp"

SDL_Renderer *screen;

void showCard(Card cardToShow){
    SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
    SDL_RenderClear(screen);
    SDL_RenderCopy(screen, cardToShow.getCenter(), NULL, NULL);
    SDL_RenderCopy(screen, cardToShow.getBorder(), NULL, NULL);
    SDL_RenderPresent(screen);
}
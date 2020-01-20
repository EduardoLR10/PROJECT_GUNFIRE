#include "interface.hpp"

SDL_Renderer *screen;

void showCard(Card cardToShow){

    SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);

    SDL_RenderClear(screen);

    SDL_RenderCopy(screen, cardToShow.getArt(), NULL, NULL);

    SDL_RenderPresent(screen);
}
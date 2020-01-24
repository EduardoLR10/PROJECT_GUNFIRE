#include "interface.hpp"

SDL_Renderer *screen;

void peprareWindow(int width, int heigth){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Project Gunfire",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          width, heigth,
                          0);

    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);

    SDL_RenderClear(screen);
}

void displayScreen(int delay){

    SDL_RenderPresent(screen);

    SDL_Delay(delay);
}

int calculateCardHeight(int width){

    double aspectRatio = (250/389.0);
    int newHeight = int(round(width/aspectRatio));
    return newHeight;
}

void drawCard(Card cardToShow, int position_x, int position_y, int card_w, int card_h){

    SDL_Rect rect = {position_x, position_y, card_w, card_h};

    SDL_RenderCopy(screen, cardToShow.getArt(), NULL, &rect);
}

void showCard(Card cardToShow){

    SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);

    SDL_RenderClear(screen);

    SDL_RenderCopy(screen, cardToShow.getArt(), NULL, NULL);

    SDL_RenderPresent(screen);
}
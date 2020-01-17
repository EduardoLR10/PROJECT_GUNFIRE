#include "CardBuilder.hpp"
#include "Card.hpp"
#include "interface.hpp"

extern SDL_Renderer *screen;

int main(){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Project Gunfire",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
                          0);

    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CardBuilder cardBuilder;
    Card testCard = cardBuilder.buildEquipCard("EquipBarile", "BorderMoss");

    showCard(testCard);

    SDL_Delay(5000); // Wait 5 seconds
    SDL_Quit();
}
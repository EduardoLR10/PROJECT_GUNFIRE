#ifndef CARD_HPP
#define CARD_HPP

#include <SDL2/SDL.h>
#include <fstream>

class Card{
private:
    SDL_Texture* center;
    SDL_Texture* border;
    SDL_Texture* suit;
    SDL_Texture* type;

public:   
    Card(SDL_Texture* center, SDL_Texture* border, SDL_Texture* suit, SDL_Texture* type);
    SDL_Texture* getCenter();
    SDL_Texture* getBorder();
    SDL_Texture* getSuit();
    SDL_Texture* getType();

};


#endif // CARD_HPP
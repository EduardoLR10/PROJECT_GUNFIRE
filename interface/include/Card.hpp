#ifndef CARD_HPP
#define CARD_HPP

#include <SDL2/SDL.h>
#include <fstream>

class Card{
private:
    SDL_Texture* art;

public:   
    Card(SDL_Texture* art);
    SDL_Texture* getArt();

};


#endif // CARD_HPP
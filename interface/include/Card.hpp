#ifndef CARD_HPP
#define CARD_HPP

#include <SDL2/SDL.h>
#include <fstream>

class Card{
private:
    SDL_Texture* center;
    SDL_Texture* border;

public:   
    Card(SDL_Texture* center, SDL_Texture* border);
    //setCenter(std::fstream* image);
    SDL_Texture* getCenter();
    SDL_Texture* getBorder();

};


#endif // CARD_HPP
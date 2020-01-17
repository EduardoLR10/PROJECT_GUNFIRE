#include "Card.hpp"

Card::Card(SDL_Texture* center, SDL_Texture* border){
    this->center = center;
    this->border = border;
}

SDL_Texture* Card::getCenter(){
    return this->center;
}

SDL_Texture* Card::getBorder(){
    return this->border;
}
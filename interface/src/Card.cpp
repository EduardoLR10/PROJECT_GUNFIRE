#include "Card.hpp"

Card::Card(SDL_Texture* center, SDL_Texture* border, SDL_Texture* suit, SDL_Texture* type){
    this->center = center;
    this->border = border;
    this->suit = suit;
    this->type = type;
}

SDL_Texture* Card::getCenter(){
    return this->center;
}

SDL_Texture* Card::getBorder(){
    return this->border;
}

SDL_Texture* Card::getSuit(){
    return this->suit;
}

SDL_Texture* Card::getType(){
    return this->type;
}
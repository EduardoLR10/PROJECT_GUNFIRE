#include "Card.hpp"

Card::Card(SDL_Texture* art){
    this->art = art;
}

SDL_Texture* Card::getArt(){
    return this->art;
}
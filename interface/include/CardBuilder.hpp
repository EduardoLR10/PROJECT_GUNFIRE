#ifndef CARDBUILDER_HPP
#define CARDBUILDER_HPP

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Card.hpp"

extern SDL_Renderer *screen;

class CardBuilder{
public:
    CardBuilder();
    Card buildEquipCard(std::string centerName, std::string borderName, std::string suitName, std::string typeName);

};








#endif // CARDBUILDER_HPP
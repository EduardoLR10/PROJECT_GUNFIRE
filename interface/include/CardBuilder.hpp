#ifndef CARDBUILDER_HPP
#define CARDBUILDER_HPP

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Card.hpp"

typedef enum CARD_PARTS{
    CENTER, SUIT, TYPE,
}CARD_PARTS;

typedef enum CARD_TYPES{
    EFFECT_CARD, EQUIPMENT_CARD, CHARACTER_CARD, ROLE_CARD,
}CARD_TYPES;

extern SDL_Renderer *screen;

class CardBuilder{
public:
    CardBuilder();
    Card buildEquipCard(CARD_TYPES type, std::vector<std::string> card_parts);

};








#endif // CARDBUILDER_HPP
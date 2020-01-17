#include "CardBuilder.hpp"

std::string cardsDirectory("../cardParts/");

std::map<std::string, char*> equipment_parts = {
    { "EquipRemington", "remington.png" },
    { "EquipSchofield", "schofield.png" },
    { "EquipWinchester", "winchester.png" },
    { "EquipCarabine", "carabine.png" },
    { "EquipBarile", "barile.png" },
    { "EquipVolcanic", "volcanic.png" },
    { "EquipPrigione", "prigione.png" },
    { "EquipMustang", "mustang.png" },
    { "EquipMirino", "mirino.png" },
    { "EquipDinamite", "dinamite.png" }
};

std::map<std::string, std::string> suit_parts = {
    { "SuitHearts", "suit_hearts.png" },
    { "SuitDiamonds", "suit_diamonds.png" },
    { "SuitClubs", "suit_clubs.png" },
    { "SuitSpades", "suit_spades.png" }
};

std::map<std::string, char*> type_parts = {
    { "TypeA", "type_A.png" },
    { "Type2", "type_2.png" },
    { "Type3", "type_3.png" },
    { "Type4", "type_4.png" },
    { "Type5", "type_5.png" },
    { "Type6", "type_6.png" },
    { "Type7", "type_7.png" },
    { "Type8", "type_8.png" },
    { "Type9", "type_9.png" },
    { "Type10", "type_10.png" },
    { "TypeJ", "type_J.png" },
    { "TypeQ", "type_Q.png" },
    { "TypeK", "type_K.png" },
};

std::map<std::string, char*> border_parts = {
    { "BorderBlue", "border_blue.png" },
    { "BorderBeige", "border_beige.png" },
    { "BorderMoss", "border_moss.png" }
};

CardBuilder::CardBuilder(){}

Card CardBuilder::buildEquipCard(std::string centerName, std::string borderName, std::string suitName, std::string typeName){

    // Building Center Part
    SDL_Surface* loadedSurface = IMG_Load((cardsDirectory + equipment_parts.at(centerName)).c_str());

    Uint32 colorkey = SDL_MapRGB(loadedSurface->format, 0, 255, 0);
    SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);

    SDL_Texture* centerTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
    

    // Building Border Part
    loadedSurface = IMG_Load((cardsDirectory + border_parts.at(borderName)).c_str());

    colorkey = SDL_MapRGB(loadedSurface->format, 0,255, 0);
    SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);

    SDL_Texture* borderTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);

    // Building Suit Part
    loadedSurface = IMG_Load((cardsDirectory + suit_parts.at(suitName)).c_str());

    colorkey = SDL_MapRGB(loadedSurface->format, 0, 255, 0);
    SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);

    SDL_Texture* suitTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);

    // Building Type Part
    loadedSurface = IMG_Load((cardsDirectory + type_parts.at(typeName)).c_str());

    colorkey = SDL_MapRGB(loadedSurface->format, 0, 255, 0);
    SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);

    SDL_Texture* typeTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);

    Card buildedCard(centerTexture, borderTexture, suitTexture, typeTexture); 

    SDL_FreeSurface(loadedSurface);
    return buildedCard;
    
}
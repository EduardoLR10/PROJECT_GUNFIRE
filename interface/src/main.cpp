#include "CardBuilder.hpp"
#include "Card.hpp"
#include "interface.hpp"

extern SDL_Renderer *screen;

int main(){

    peprareWindow(1280, 720);

    CardBuilder cardBuilder;
    Card effectCard = cardBuilder.buildEquipCard(EFFECT_CARD, {"EffectBang", "SuitSpades", "TypeK"});
    Card roleCard = cardBuilder.buildEquipCard(ROLE_CARD, {"RoleSceriffo"});
    Card characterCard = cardBuilder.buildEquipCard(CHARACTER_CARD, {"CharacterElGringo"});
    Card equipmentCard = cardBuilder.buildEquipCard(EQUIPMENT_CARD, {"EquipMustang", "SuitSpades", "TypeK"});

    drawCard(effectCard, 0, 0, 250, 389);

    drawCard(roleCard, 1100, 100, 150, calculateCardHeight(150));

    drawCard(characterCard, 200, 550, 150, 150);

    drawCard(equipmentCard, 600, 250, 300, calculateCardHeight(300));
    
    displayScreen(5000);

    SDL_Quit();

    return 0;
}
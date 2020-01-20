#include "CardBuilder.hpp"
#include "Card.hpp"
#include "interface.hpp"

extern SDL_Renderer *screen;

int main(){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Project Gunfire",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          250, 389,
                          0);

    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CardBuilder cardBuilder;
    Card effectCard = cardBuilder.buildEquipCard(EFFECT_CARD, {"EffectBang", "SuitSpades", "TypeK"});
    Card roleCard = cardBuilder.buildEquipCard(ROLE_CARD, {"RoleSceriffo"});
    Card characterCard = cardBuilder.buildEquipCard(CHARACTER_CARD, {"CharacterElGringo"});
    Card equipmentCard = cardBuilder.buildEquipCard(EQUIPMENT_CARD, {"EquipMustang", "SuitSpades", "TypeK"});

    showCard(effectCard);
    SDL_Delay(2000);

    showCard(roleCard);
    SDL_Delay(2000);

    showCard(characterCard);
    SDL_Delay(2000);

    showCard(equipmentCard);
    SDL_Delay(2000);
    
    SDL_Quit();
}
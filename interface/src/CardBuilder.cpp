#include "CardBuilder.hpp"

std::string cardsDirectory("../cardParts/");

std::map<std::string, std::string> role_parts = {
    { "RoleFuorilegge", "01_fuorilegge.png" },
    { "RoleRinnegato", "01_rinnegato.png" },
    { "RoleSceriffo", "01_sceriffo.png" },
    { "RoleVice", "01_vice.png" }
};

std::map<std::string, std::string> effect_parts = {
    { "EffectBang", "bang.png" },
    { "EffectBarile", "barile.png" },
    { "EffectBirra", "birra.png" },
    { "EffectCatBalou", "catbalou.png" },
    { "EffectDiligenza", "diligenza.png" },
    { "EffectDinamite", "dinamite.png" },
    { "EffectDuello", "duello.png" },
    { "EffectEmporio", "emporio.png" },
    { "EffectGatling", "gatling.png" },
    { "EffectIndiani", "indiani.png" },
    { "EffectMancato", "mancato.png" },
    { "EffectMirino", "mirino.png" },
    { "EffectPanico", "panico.png" },
    { "EffectPrigione", "prigione.png" },
    { "EffectSaloon", "saloon.png" },
    { "EffectWellsFargo", "wellsfargo.png" }
};

std::map<std::string, std::string> character_cards = {
    { "CharacterBartCassidy", "01_bartcassidy.png" },
    { "CharacterBlackJack", "01_blackjack.png" },
    { "CharacterCalamityJanet", "01_calamityjanet.png" },
    { "CharacterElGringo", "01_elgringo.png" },
    { "CharacterJesseJones", "01_jessejones.png" },
    { "CharacterJourdonnais", "01_jourdonnais.png" },
    { "CharacterKitCarlson", "01_kitcarlson.png" },
    { "CharacterLuckyDuke", "01_luckyduke.png" },
    { "CharacterPaulRegret", "01_paulregret.png" },
    { "CharacterPedroRamirez", "01_pedroramirez.png" },
    { "CharacterRoseDoolan", "01_rosedoolan.png" },
    { "CharacterSidKetchum", "01_sidketchum.png" },
    { "CharacterSlab", "01_slab.png" },
    { "CharacterSuzyLafayette", "01_suzylafayette.png" },
    { "CharacterVulturesam", "01_vulturesam.png" },
    { "CharacterWillyTheKid", "01_willythekid.png" }
};

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

Card CardBuilder::buildEquipCard(CARD_TYPES card_type, std::vector<std::string> card_parts){

    SDL_Texture* center;
    SDL_Texture* border;
    SDL_Texture* suit;
    SDL_Texture* type;

    SDL_Texture* cardArt = SDL_CreateTexture(screen, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 250, 389);
    SDL_SetRenderTarget(screen, cardArt);

    switch(card_type){
        case EFFECT_CARD:
            
            center = IMG_LoadTexture(screen, (cardsDirectory + effect_parts.at(card_parts.at(CENTER))).c_str());
            border = IMG_LoadTexture(screen, (cardsDirectory + border_parts.at("BorderBeige")).c_str());
            suit = IMG_LoadTexture(screen, (cardsDirectory + suit_parts.at(card_parts.at(SUIT))).c_str());
            type = IMG_LoadTexture(screen, (cardsDirectory + type_parts.at(card_parts.at(TYPE))).c_str());

            SDL_RenderCopy(screen, center, NULL, NULL);
            SDL_RenderCopy(screen, border, NULL, NULL);
            SDL_RenderCopy(screen, suit, NULL, NULL);
            SDL_RenderCopy(screen, type, NULL, NULL);

            break;
        case EQUIPMENT_CARD:

            center = IMG_LoadTexture(screen, (cardsDirectory + equipment_parts.at(card_parts.at(CENTER))).c_str());
            border = IMG_LoadTexture(screen, (cardsDirectory + border_parts.at("BorderBlue")).c_str());
            suit = IMG_LoadTexture(screen, (cardsDirectory + suit_parts.at(card_parts.at(SUIT))).c_str());
            type = IMG_LoadTexture(screen, (cardsDirectory + type_parts.at(card_parts.at(TYPE))).c_str());

            SDL_RenderCopy(screen, center, NULL, NULL);
            SDL_RenderCopy(screen, border, NULL, NULL);
            SDL_RenderCopy(screen, suit, NULL, NULL);
            SDL_RenderCopy(screen, type, NULL, NULL);

            break;
        case CHARACTER_CARD:
            
            center = IMG_LoadTexture(screen, (cardsDirectory + character_cards.at(card_parts.at(CENTER))).c_str());

            SDL_RenderCopy(screen, center, NULL, NULL);

            break;
        case ROLE_CARD:

            center = IMG_LoadTexture(screen, (cardsDirectory + role_parts.at(card_parts.at(CENTER))).c_str());
            border = IMG_LoadTexture(screen, (cardsDirectory + border_parts.at("BorderMoss")).c_str());

            SDL_RenderCopy(screen, center, NULL, NULL);
            SDL_RenderCopy(screen, border, NULL, NULL);

            break;
        default:
            break;
    }

    SDL_SetRenderTarget(screen, NULL);  
    
    Card buildedCard(cardArt);

    return buildedCard;
    
}
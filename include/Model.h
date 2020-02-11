#include "aux.h"

class Card{
public:
	enumCards cardType;
	std::string cardName;
	std::string cardDescription;
};

class RoleCard : public Card{
public:
	RoleCard(enumCards card){ 
		cardType = card;
		cardName = Info.Names[card];
		cardDescription = Info.Descriptions[card];
	}
};

class CharacterCard : public Card{
public:
	int lifePoints = 0;
	CharacterCard(enumCards card, int life){ 
		cardType = card;
		cardName = Info.Names[card];
		cardDescription = Info.Descriptions[card];
		lifePoints = life;
	}
};

class FlipCard : public Card{
public:
	int Number;
	enumNipe Nipe;

	FlipCard(enumCards card, int number, enumNipe nipe){ 
		cardType = card;
		cardName = Info.Names[card];
		cardDescription = Info.Descriptions[card];
		Number = number;
		Nipe = nipe;
	}
};

class EquipCard : public Card{
	int Number;
	enumNipe Nipe;

	EquipCard(enumCards card, int number, enumNipe nipe){ 
		cardType = card;
		cardName = Info.Names[card];
		cardDescription = Info.Descriptions[card];
		Number = number;
		Nipe = nipe;
	}
};



//================================================================================================
class Deck{
public:
	std::stack<std::shared_ptr<Card>> Stack;
	Deck(int NPlayers, deckType type);
	void deckRole(std::vector<std::shared_ptr<Card>> &v, int NPlayers);
	void deckCharacter(std::vector<std::shared_ptr<Card>> &v);
	void deckFlip(std::vector<std::shared_ptr<Card>> &v);
};





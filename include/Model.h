#include "aux.h"

//!  Card class. 
/*!
  Base class for all types of cards. Contains common card attributes.
*/
class Card{
public:
	enumCards cardType;	 /*!< Id */  
	std::string cardName;
	std::string cardDescription;
};

//!  Role Card class. 
/*!
  For cards with the following functions: Sheriff, Renegade, Deputy and Outlaws.
*/
class RoleCard : public Card{
public:
	RoleCard(enumCards card){ 
		cardType = card;
		cardName = Info.Names[card];
		cardDescription = Info.Descriptions[card];
	}
};

//!  Character Card class. 
/*!
  Designed for the characters' cards. Each with a certain life points.
*/
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

//!  Character Card class. 
/*!
  Designed for playing cards: action, weapons and equipment cards.
*/
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


//================================= DECK =====================================================
//!  Deck class. 
/*!
  Each deck corresponds to a stack of cards: 
  Stack of playing cards, characters, role and empty stack.
*/
class Deck{
public:
	std::vector<std::shared_ptr<Card>> Stack; 
	//std::stack<std::shared_ptr<Card>> Stack; 
	Deck(int NPlayers, deckType type); /*!< Build the stack according to the number of players and type of cards. */
	std::shared_ptr<Card> pop(); /*!< Take away the card from the top of the pile. */
	void push(std::shared_ptr<Card> card); /*!< Place card on top of the pile. */
	void shuffle(); /*!< Shuffles the pile of cards. */
private:
	void deckRole(int NPlayers); /*!< Auxiliary function to build stack of function cards*/
	void deckCharacter();	/*!< Auxiliary function to build stack of character cards*/
	void deckFlip(); /*!< Auxiliary function to build stack of flip cards*/
};





#include "aux.h"

//================================= CARDS =====================================================
//!  \class Card
/*!
  Base class for all types of cards. Contains common card attributes.
*/
class Card{
public:
	enumCards cardType;	 /*!< Id */  
	std::string cardName;
	std::string cardDescription;
};

//!  \class  RoleCard
/*!
  For cards with the following roles: Sheriff, Renegade, Deputy and Outlaws.
*/
class RoleCard : public Card{
public:
	RoleCard() {};
	RoleCard(enumCards card); /*!< Build the role card */
};

//!  \class CharacterCard
/*!
  Designed for the characters' cards. Each with a certain life points.
*/
class CharacterCard : public Card{
public:
	int lifePoints = 0;
	CharacterCard() {};
	CharacterCard(enumCards card, int life); /*!< Build the character card */
};

//!  \class FlipCard
/*!
  Designed for playing cards: action, weapons and equipment cards.
*/
class FlipCard : public Card{
public:
	int Number;
	enumNaipe Naipe;
	FlipCard() {};
	FlipCard(enumCards card, int number, enumNaipe naipe); /*!< Build the paying card */
};

class EquipCard : public Card{
public:
	int Number;
	enumNaipe Naipe;
	EquipCard() {};
	EquipCard(enumCards card, int number, enumNaipe naipe); /*!< Build the equip card */
};


//================================= DECK =====================================================
//!  \class Deck 
/*!
  Each deck corresponds to a stack of cards: 
  Stack of playing cards, characters, role and empty stack.
*/
class Deck{
public:
	std::vector<std::shared_ptr<Card>> Stack; /*!< Vector of smart pointers that reference the cards.*/ 
	//std::stack<std::shared_ptr<Card>> Stack; 
	Deck() {};
	Deck(int nPlayers, deckType type); 		/*!< Build the stack according to the number of players and type of cards. */
	std::shared_ptr<Card> pop();		 	/*!< Take away the card from the top of the pile. */
	void push(std::shared_ptr<Card> card); 	/*!< Place card on top of the pile. */
	void shuffle(); 						/*!< Shuffles the pile of cards. */
private:
	void deckRole(int nPlayers); 			/*!< Auxiliary function to build stack of function cards*/
	void deckCharacter();					/*!< Auxiliary function to build stack of character cards*/
	void deckFlip(); 						/*!< Auxiliary function to build stack of flip cards*/
};


//================================= PLAYER =====================================================

class Player{
public:
	std::string Name;
	int health = 0;
	int maxHealth = 0;
	int state = 0;
	int id;
	Card roleCard;
	Card characterCard;
	EquipCard equipCard;
	std::vector<FlipCard> Cards;
	Player(std::string name, int id);
};


//================================= ROOM =====================================================

class Room{
public:
	Deck 	discardPile;
	Deck 	roleDeck;
	Deck 	characterDeck;
	Deck 	flipDeck;

	// actions

	std::vector<Player> players;
	std::vector<std::vector<int>> grplayers;
	int 	nPlayers;
	int 	currentPlayer;
	int 	nOutlaws;

	bool 	liveRenegade;
	bool 	liveSheriff;
	enumPh 	currentPhase;

	//void gameInit();
	//void runGame();
	//void exit();
	Room(int nPlayers, std::string names[]);
	void dealInitialCards();
	void killPlayer();

private:
	void createGraph(int nPlayers);
	Deck getDeck(int nPlayers, deckType type);
};
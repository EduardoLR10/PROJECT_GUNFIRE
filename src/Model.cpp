#include "Model.h"

_Info Info;  /*!< Struct global for assistance. Declared in aux.h */


//================================= CARDS =====================================================
//! Role card Builder.
/*!
	The enum value also serves as an index for auxiliary Names and Descriptions string vectors.
	\param card a enum value argument. Card id.
	\sa enumCards, Names, Descriptions
*/ 
RoleCard::RoleCard(enumCards card){ 
	cardType = card;
	cardName = Info.Names[card];
	cardDescription = Info.Descriptions[card];
}

//! Character card Builder.
/*!
	The enum value also serves as an index for auxiliary Names and Descriptions string vectors.
	\param card a enum value argument. Card id.
	\param life a integer argument. Initial life points for each character.
	\sa enumCards, Names, Descriptions
*/ 
CharacterCard::CharacterCard(enumCards card, int life){ 
	cardType = card;
	cardName = Info.Names[card];
	cardDescription = Info.Descriptions[card];
	lifePoints = life;
}

//! Playing card Builder.
/*!
	The enum value also serves as an index for auxiliary Names and Descriptions string vectors.
	\param card a enum value argument. Card id.
	\param number a integer argument. Card number.
	\param naipe a enum value argument. Card naipe.
	\sa enumCards, Names, Descriptions
*/ 
FlipCard::FlipCard(enumCards card, int number, enumNaipe naipe){ 
	cardType = card;
	cardName = Info.Names[card];
	cardDescription = Info.Descriptions[card];
	Number = number;
	naipe = naipe;
}

//! Equip card Builder.
/*!
	The enum value also serves as an index for auxiliary Names and Descriptions string vectors.
	\param card a enum value argument. Card id.
	\param number a integer argument. Card number.
	\param naipe a enum value argument. Card naipe.
	\sa enumCards, Names, Descriptions
*/ 
EquipCard::EquipCard(enumCards card, int number, enumNaipe naipe){ 
	cardType = card;
	cardName = Info.Names[card];
	cardDescription = Info.Descriptions[card];
	Number = number;
	naipe = naipe;
}

//================================= DECK =====================================================
//! Deck Builder.
/*!
	Build a pile of shuffled cards.
	\param nPlayers an integer argument. Number of players.
	\param type a Enum value argument of deckType. Type of cards that will contain the stack: role, character, flip (playing), empty
	\return The test results
	\sa deckRole(), deckCharacter(), deckFlip()
*/
Deck::Deck(int nPlayers, deckType type){
	switch(type){
		case character:
			deckCharacter();
			break;
		case role:
			deckRole(nPlayers);
			break;	
		case flip:
			deckFlip();
			break;
		default:
			break;
	}
	this->shuffle();
}

//! Auxiliary method to build stack of role cards.
/*!
	Builds stack of role cards.
	With the assist of the auxRole array, it checks the number of cards to be built for each 
	role according to the number of players.
	\param nPlayers an integer argument. Number of players. Manipulated to serve as an index to the auxRole array.
	\see auxRole, enumCards
*/
void Deck::deckRole(int nPlayers){
	this->Stack.push_back(std::make_shared<RoleCard>(Sheriff));
	this->Stack.push_back(std::make_shared<RoleCard>(Renegade));
	for(int i=Info.auxRole[nPlayers-4]; i!=0; i--)  
		this->Stack.push_back(std::make_shared<RoleCard>(Outlaws));
	for(int i=Info.auxRole[nPlayers]; i!=0; i--)
		this->Stack.push_back(std::make_shared<RoleCard>(Deputy));
}

//! Auxiliary method to build stack of character cards.
/*!
	Scroll through each character contained in the enum enumCards to build the cards a
	nd place them in the pile. 
	\see enumCards
*/
void Deck::deckCharacter(){
	for(int c=WillyKid; c!=End; c++){
		int life = (c == ElGringo || c == PaulRegret) ? life3 : life4;
		this->Stack.push_back(std::make_shared<CharacterCard>((enumCards)c, life));
	}
}


//! Auxiliary method to build stack of playing cards.
/*!
	This function runs through the auxiliary matrix auxPlayingCards extracting information from each 
	card (id, number and naipe). Such information serves as indexes for enums enumCard and enumNaipe.
	\see enumCards, enumNaipe, auxPlayingCards
*/
void Deck::deckFlip(){
	for(int i=0; i<numberOfCards; i++){
		int id = Info.auxPlayingCards[i][0];
		int naipe = Info.auxPlayingCards[i][1];
		int number = Info.auxPlayingCards[i][2];
		this->Stack.push_back(std::make_shared<FlipCard>((enumCards)id, number, (enumNaipe)naipe));
	}
}

//! Take away the card from the top of the pile.
std::shared_ptr<Card> Deck::pop(){
	std::shared_ptr<Card> ptrcard = this->Stack.back();
	this->Stack.pop_back();
	return ptrcard;
}

//! Place card on top of the pile.
/*!
	\param card a smart pointer argument.
*/ 
void Deck::push(std::shared_ptr<Card> card){
	this->Stack.push_back(card);
}

//! Shuffles the pile of cards.
void Deck::shuffle(){
	unsigned s = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->Stack.begin(), this->Stack.end(), std::default_random_engine(s));
}


//================================= PLAYER =====================================================
Player::Player(std::string name, int id){
	this->Name = name;
	this->id = id;
}


//================================= ROOM =====================================================
Room::Room(int nPlayers, std::string names[]){
	this->discardPile = getDeck(nPlayers, empty);
	this->roleDeck = getDeck(nPlayers, role);
	this->characterDeck = getDeck(nPlayers, character);
	this->flipDeck = getDeck(nPlayers, flip);
	this->currentPhase = draw2;
	this->liveRenegade = true;
	this->liveSheriff = true;
	this->nOutlaws = Info.auxRole[nPlayers-4];
	createGraph(nPlayers);
	for(int p=0; p!=nPlayers; p++)
		this->players.push_back(Player(names[p], p));
}

Deck Room::getDeck(int nPlayers, deckType type){
	Deck d(nPlayers, type);
	return d;
}

void Room::createGraph(int nPlayers){
	this->grplayers.resize(nPlayers);
	for(int p=0; p<nPlayers; p++){
		this->grplayers[p].push_back( (p>0) ? p-1 : 0 );
		this->grplayers[p].push_back( (p<nPlayers) ? p+1 : 0 );
	}
}


void Room::dealInitialCards(){
	for(auto player=this->players.begin(); player!=this->players.end(); ++player){
		// Role
	}
}

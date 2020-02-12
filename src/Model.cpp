#include "Model.h"

_Info Info;  /*!< Struct global for assistance. Declared in aux.h */


//! Deck Builder.
/*!

*/
Deck::Deck(int NPlayers, deckType type){
	switch(type){
		case character:
			deckCharacter();
			break;
		case role:
			deckRole(NPlayers);
			break;	
		case flip:
			deckFlip();
			break;
		default:
			break;
	}
	this->shuffle();
}

void Deck::deckRole(int NPlayers){
	this->Stack.push_back(std::make_shared<RoleCard>(Sheriff));
	this->Stack.push_back(std::make_shared<RoleCard>(Renegade));
	for(int i=Info.auxRole[NPlayers-4]; i!=0; i--)  
		this->Stack.push_back(std::make_shared<RoleCard>(Outlaws));
	for(int i=Info.auxRole[NPlayers]; i!=0; i--)
		this->Stack.push_back(std::make_shared<RoleCard>(Deputy));
}

void Deck::deckCharacter(){
	short int life = life4;
	for(int c=WillyKid; c!=End; c++){
		if(c == ElGringo || c == PaulRegret) life = life3;
		this->Stack.push_back(std::make_shared<CharacterCard>((enumCards)c, life));
	}
}

void Deck::deckFlip(){
	for(int i=0; i!=numberOfCards; i++){
		int id = Info.auxPlayingCards[i][0];
		int nipe = Info.auxPlayingCards[i][1];
		int number = Info.auxPlayingCards[i][2];
		this->Stack.push_back(std::make_shared<FlipCard>((enumCards)id, number, (enumNipe)nipe));
	}
}

std::shared_ptr<Card> Deck::pop(){
	std::shared_ptr<Card> ptrcard = this->Stack.back();
	this->Stack.pop_back();
	return ptrcard;
}

void Deck::push(std::shared_ptr<Card> card){
	this->Stack.push_back(card);
}

void Deck::shuffle(){
	unsigned s = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->Stack.begin(), this->Stack.end(), std::default_random_engine(s));
}
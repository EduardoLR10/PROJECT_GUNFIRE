#include "Model.h"

_Info Info;

Deck::Deck(int NPlayers, deckType type){
	// personagens, jogo, vazio
	std::vector<std::shared_ptr<Card>> v;
	srand (time(NULL));
	switch(type){
		case character:
			deckCharacter(v);
			break;
		case role:
			deckRole(v, NPlayers);
			break;	
		case flip:
			deckFlip(v);
			break;
		default:
			break;
	}
	std::random_shuffle(v.begin(), v.end());
	for(auto it=v.begin(); it!=v.end(); it++) this->Stack.push(*it);
	
}

void Deck::deckRole(std::vector<std::shared_ptr<Card>> &v, int NPlayers){
	v.push_back(std::make_shared<RoleCard>(Sheriff));
	v.push_back(std::make_shared<RoleCard>(Renegade));
	for(int i=Info.auxRole[NPlayers-4]; i!=0; i--)  
		v.push_back(std::make_shared<RoleCard>(Outlaws));
	for(int i=Info.auxRole[NPlayers]; i!=0; i--)
		v.push_back(std::make_shared<RoleCard>(Deputy));

}

void Deck::deckCharacter(std::vector<std::shared_ptr<Card>> &v){
	short int life = life4;
	for(int c=WillyKid; c!=End; c++){
		if(c == ElGringo || c == PaulRegret) life = life3;
		v.push_back(std::make_shared<CharacterCard>((enumCards)c, life));
	}
}

void Deck::deckFlip(std::vector<std::shared_ptr<Card>> &v){
	for(int i=0; i!=numberOfCards; i++){
		int id = Info.auxPlayingCards[i][0];
		int nipe = Info.auxPlayingCards[i][1];
		int number = Info.auxPlayingCards[i][2];
		v.push_back(std::make_shared<FlipCard>((enumCards)id, number, (enumNipe)nipe));
	}
}

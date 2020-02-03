#include <iostream>
#include <string>
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
#include <vector>
#include <stack>          // std::stack
#include <algorithm>    // std::random_shuffle


#define	numberOfTypes 41
#define	lifePoints3
#define	lifePoints4


enum PokerSymbol{ none, clubs, hearts, spades, diamonds};

// NÃO MUDAR A ORDEM
enum enumCards {
	//Objective cards
	Sheriff, Deputy, Outlaws, 							  
	//Weapons cards
	Schofield, Remington, RevCarabine, Winchester, Volcanic, 
	//Equip cards
	Barrel, Jail, Dynamite, Scope, Mustang,
	//Action Cards
	Bang, Beer, Missed, Saloon, GeneralStore, Panic, 
	CatBalou, Gatling, Indians, Duel, Stagecoach, WellsFargo,
	//Character Cards
	WillyKid, JesseJones, Joudonnais, KitCarlson, LuckyDuke, PaulRegret, PedroRamirez, RoseDoolan, 
	BartCassidy, SidKetchum, BlackJack, SlabKiller, CalamityJanet, SuzyLafayette, 
	ElGringo, VultureSam
};	

std::string Names[41] = {
	//Objective cards
	"Sheriff", "Deputy", "Outlaws", 							  
	//Weapons cards
	"Schofield", "Remington", "Rev. Carabine", "Winchester", "Volcanic", 
	//Equip cards
	"Barrel", "Jail", "Dynamite", "Scope", "Mustang",
	//Action Cards
	"Bang", "Beer", "Missed", "Saloon", "General Store", "Panic!", 
	"Cat Balou", "Gatling", "Indians!", "Duel", "Stagecoach", "Wells Fargo",
	//Character Cards
	"Willy the kid", "Jesse Jones", "Joudonnais", "Kit Carlson", "Lucky Duke",
	"Paul Regret", "Pedro Ramirez", "Rose Doolan", "Bart Cassidy", "Sid Ketchum", 
	"Black Jack", "Slab the Killer", "Calamity Janet", "Suzy Lafayette", "El Gringo", "Vulture Sam"
};			

std::string Descriptions[41] = {
	//Objective cards
	"Sheriff", "Deputy", "Outlaws", 							  
	//Weapons cards
	"Schofield", "Remington", "Rev. Carabine", "Winchester", "Volcanic", 
	//Equip cards
	"Barrel", "Jail", "Dynamite", "Scope", "Mustang",
	//Action Cards
	"Bang", "Beer", "Missed", "Saloon", "General Store", "Panic!", 
	"Cat Balou", "Gatling", "Indians!", "Duel", "Stagecoach", "Wells Fargo",
	//Character Cards
	"Willy the kid", "Jesse Jones", "Joudonnais", "Kit Carlson", "Lucky Duke",
	"Paul Regret", "Pedro Ramirez", "Rose Doolan", "Bart Cassidy", "Sid Ketchum", 
	"Black Jack", "Slab the Killer", "Calamity Janet", "Suzy Lafayette", "El Gringo", "Vulture Sam"
};


class GeneralCard{
public:
	std::string cardName;
	std::string cardDescription;
	enumCards Card;
};

class RoleCard : public GeneralCard{
public:
	RoleCard(enumCards card){ Card = card; cardName = Names[card]; cardDescription = Descriptions[card];}
};

class CharacterCard : public GeneralCard{
public:
	int lifePoints = 0;
	CharacterCard(enumCards card, int n){ Card = card; cardName = Names[card]; cardDescription = Descriptions[card]; lifePoints = n;}
};


class WeaponCard : public GeneralCard{
public:
	WeaponCard(enumCards card){ Card = card; cardName = Names[card]; cardDescription = Descriptions[card];}
	int distance = 1;
};

class EquipCard : public GeneralCard{
	PokerSymbol pokerSymbol = none;
	int PokerValue = 0;
	EquipCard(enumCards card){ Card = card; cardName = Names[card]; cardDescription = Descriptions[card];}
};




class ActionsCard : public GeneralCard{
public:

	//Functions for each card
};




//================================================================================================

class Deck{
public:
	std::vector<CharacterCard> deckCharacter;
	std::vector<RoleCard> deckRole;
	std::vector<EquipCard> deckEquip;
	std::vector<ActionsCard> deckActions;
	Deck(); // ja construir embaralhado e guarda-los numa pilha
	void deal();

};


Deck::Deck(){
	srand (time(NULL));

	for(int c=WillyKid; c!=VultureSam; c++){
		if(c == ElGringo || c == PaulRegret)
			CharacterCard cardO((enumCards)c, lifePoints3);	
		else
			CharacterCard cardO((enumCards)c, lifePoints4);
		this->deckCharacter.push_back(cardO);
	}

	std::random_shuffle(this->deckCharacter.begin(), this->deckCharacter.end());
}



int main(int argc, char const *argv[]){

	Deck deckObj;
	std::vector<CharacterCard> vec;
	vec = deckObj.deckCharacter;
	for(auto i=deckObj.deckCharacter.begin(); i!=deckObj.deckCharacter.end(); i++){
		std::cout << (*i).cardName;
	}
	std::cout << std::endl;

	return 0;
}
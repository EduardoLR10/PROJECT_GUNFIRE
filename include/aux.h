/*! \file aux.h
    \brief Composes all variables, definitions, enum, etc. auxiliary to the Model.
*/


#ifndef AUX_H
#define AUX_H

#include <iostream>
#include <string>
#include <vector>
//#include <stack>      // std::stack
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <memory> 		// shared_ptr, make_shared

/*! \def life3, life4, numberOfCards, J, Q, K, A
    \brief Definitions of important constant integers.
*/
#define	life3	3
#define	life4	4
#define numberOfCards 80
#define J 11
#define Q 12
#define K 13
#define A 14

// ***** NÃO MUDAR A ORDEM *****

enum enumPh{draw2, play, discard};

enum deckType{role, character, flip, empty}; /*!< \enum deckType. Type of cards for the stack. */

enum enumNaipe{clubs, hearts, spades, diamonds}; /*!< \enum enumNaipe. */

enum enumCards {
	//Weapons cards
	Schofield, Remington, RevCarabine, Winchester, Volcanic, 
	//Equip cards
	Barrel, Jail, Dynamite, Scope, Mustang,
	//Action Cards
	Bang, Beer, Missed, Saloon, GeneralStore, Panic, 
	CatBalou, Gatling, Indians, Duel, Stagecoach, WellsFargo,
	//Objective cards
	Sheriff, Renegade, Deputy, Outlaws, 							  
	//Character Cards
	WillyKid, JesseJones, Joudonnais, KitCarlson, LuckyDuke, PaulRegret, PedroRamirez, RoseDoolan, 
	BartCassidy, SidKetchum, BlackJack, SlabKiller, CalamityJanet, SuzyLafayette, 
	ElGringo, VultureSam, End
};	/*!< \enum enumCard. Id for all cards.*/

/*! \struct _Info
    \brief Contains auxiliary arrays.
*/
struct _Info{
	/*! \var auxRole
    \brief Auxiliary array with the number of Outlaws (the first 4) and Deputy (the last 4). */
	int auxRole[8] = {2, 2, 3, 3, 0, 1, 1, 2}; 

	std::string Names[43] = {
		//Weapons cards
		"Schofield", "Remington", "Rev. Carabine", "Winchester", "Volcanic", 
		//Equip cards
		"Barrel", "Jail", "Dynamite", "Scope", "Mustang",
		//Action Cards
		"Bang", "Beer", "Missed", "Saloon", "General Store", "Panic!", 
		"Cat Balou", "Gatling", "Indians!", "Duel", "Stagecoach", "Wells Fargo",
		//Objective cards
		"Sheriff", "Renegade", "Deputy", "Outlaws", 							  
		//Character Cards
		"Willy the kid", "Jesse Jones", "Joudonnais", "Kit Carlson", "Lucky Duke",
		"Paul Regret", "Pedro Ramirez", "Rose Doolan", "Bart Cassidy", "Sid Ketchum", 
		"Black Jack", "Slab the Killer", "Calamity Janet", "Suzy Lafayette", "El Gringo", 
		"Vulture Sam", ""
	};	/*!< \var Names. String array containing card names.*/		

	std::string Descriptions[43] = {
		//Weapons cards
		"Schofield", "Remington", "Rev. Carabine", "Winchester", "Volcanic", 
		//Equip cards
		"Barrel", "Jail", "Dynamite", "Scope", "Mustang",
		//Action Cards
		"Bang", "Beer", "Missed", "Saloon", "General Store", "Panic!", 
		"Cat Balou", "Gatling", "Indians!", "Duel", "Stagecoach", "Wells Fargo",
		//Objective cards
		"Sheriff...", "Renegade", "Deputy", "Outlaws", 							  
		//Character Cards
		"Willy the kid", "Jesse Jones", "Joudonnais", "Kit Carlson", "Lucky Duke",
		"Paul Regret", "Pedro Ramirez", "Rose Doolan", "Bart Cassidy", "Sid Ketchum", 
		"Black Jack", "Slab the Killer", "Calamity Janet", "Suzy Lafayette", "El Gringo", 
		"Vulture Sam", ""
	}; /*!< \var Desciptions. String array containing card descriptions.*/		

	/*! \var auxPlayingCards. Auxiliary array of integers that will serve as indexes for
		other arrays and enum to extract information from the 80 playing cards.
	*/	
	int auxPlayingCards[80][3] = {
		0, 	0,	J,
		0, 	0,	Q,
		0, 	2,	K,
		1, 	0,	K,
		2, 	0,	A,
		3, 	2,	8,
		4,	2, 	10,
		4, 	0,	10,
		5, 	2,	Q,
		5, 	2,	K,
		6, 	2,	J,
		6, 	1,	4,
		6, 	2, 	10,
		7, 	1, 	2,
		8, 	2,	A,
		9, 	1, 	8,
		9, 	1, 	9,
		10, 2, 	A,
		10, 3, 	2,
		10, 3, 	3,
		10, 3, 	4,
		10, 3, 	5,
		10, 3, 	6,
		10, 3, 	7,
		10, 3, 	8,
		10, 3, 	9,
		10, 3, 	10,
		10, 3, 	J,
		10, 3, 	Q,
		10, 3, 	K,
		10, 3, 	A,
		10, 0, 	2,
		10, 0, 	3,
		10, 0, 	4,
		10, 0, 	5,
		10, 0, 	6,
		10, 0, 	7,
		10, 0, 	8,
		10, 0, 	9,
		10, 1, 	Q,
		10, 1, 	K,
		10, 1, 	A,
		11, 1, 	6,
		11, 1, 	7,
		11, 1, 	8,
		11, 1, 	9,
		11, 1, 	10,
		11, 1, 	J,
		12, 0, 	10,
		12, 0, 	J,
		12, 0, 	Q,
		12, 0, 	K,
		12, 0, 	A,
		12, 2, 	2,
		12, 2, 	3,
		12, 2, 	4,
		12, 2, 	5,
		12, 2, 	6,
		12, 2, 	7,
		12, 2, 	8,
		13, 1, 	5,
		14,	0, 	9,
		14, 2, 	Q,
		15, 1, 	J,
		15, 1, 	Q,
		15, 1, 	A,
		15, 3, 	8,
		16, 1, 	K,
		16, 3, 	9,
		16, 3, 	10,
		16, 3, 	J,
		17, 1, 	10,
		18, 3, 	K,
		18, 3, 	A,
		19, 3, 	Q,
		19, 2, 	J,
		19, 0, 	8,
		20, 2, 	9,
		20, 2, 	9,
		21, 1, 	3
	}; 
};

extern _Info Info; /*!< A global struct definition.*/	



#endif
#include "Model.h"


int main(){
	Deck deck(6, flip);
	while(!deck.Stack.empty()){
		std::cout << deck.pop()->cardName << std::endl;
	}
	return 0;
}

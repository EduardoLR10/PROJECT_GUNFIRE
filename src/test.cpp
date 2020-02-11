#include "Model.h"


int main(){
	Deck deck(6, flip);
	while(!deck.Stack.empty()){
		std::cout << deck.Stack.top()->cardName << std::endl;
		deck.Stack.pop();
	}
	//std::cout << Schofield << std::endl;
	return 0;
}

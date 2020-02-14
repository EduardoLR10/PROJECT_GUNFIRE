#include "Model.h"


int main(){
	std::string s[4] = {"Daniel", "Lucas", "Leila", "Joaquik"};
	Room room(4, s);
	room.dealInitialCards();
	return 0;
}

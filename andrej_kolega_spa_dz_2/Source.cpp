#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	srand(time(nullptr));
	//zahtijeva sirinu i visinu
	game_of_life the_game(50, 10);
	bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);

	return 0;
}
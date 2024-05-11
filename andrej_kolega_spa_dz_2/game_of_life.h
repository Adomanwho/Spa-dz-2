#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class game_of_life {
private:
	int sirina;
	int visina;
	vector<vector<char>> curr;
	vector<vector<char>> next;
	char slucajna_vrijednost();//ako je 1: *, else -
	int check_neighours(int i, int j);
public:
	game_of_life(int i, int j);//konstruktor
	void sljedeca_generacija();//napravi next
	void iscrtaj();//printaj curr
};

#endif
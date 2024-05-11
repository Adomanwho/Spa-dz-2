#include "game_of_life.h"
#include <ctime>
#include <string>
char game_of_life::slucajna_vrijednost()
{
	int a = rand() % 4;
	if (a == 1) {
		return '*';
	}
	return '-';
}

/*
edge cases koji se ne smiju dogodit:
i-1 < 0,
i+1 > sirina,
j-1 <0,
j+1 > visina
*/

int game_of_life::check_neighours(int i, int j)//visina, sirina
{
	int count = 0;
	string i_rub = "";
	string j_rub = "";
	if (i - 1 < 0) i_rub = ".__";
	else if (i + 1 >= visina) i_rub = "__.";
	else i_rub = "___";

	if (j - 1 < 0) j_rub = ".__";
	else if (j + 1 >= sirina) j_rub = "__.";
	else j_rub = "___";

	if (i_rub == ".__" and j_rub == ".__") {
		/*
		...
		.__
		.__
		*/
		if (curr[i + 1][j] == '*') count++;
		if (curr[i][j + 1] == '*') count++;
		if (curr[i + 1][j + 1] == '*') count++;
	}
	else if (i_rub == ".__" and j_rub == "___") {
		/*
		.__
		.__
		.__
		*/
		if (curr[i][j - 1] == '*') count++;
		if (curr[i + 1][j - 1] == '*') count++;
		if (curr[i + 1][j] == '*') count++;
		if (curr[i][j + 1] == '*') count++;
		if (curr[i + 1][j + 1] == '*') count++;
	}
	else if (i_rub == ".__" and j_rub == "__.") {
		/*
		.__
		.__
		...
		*/
		if (curr[i][j - 1] == '*') count++;
		if (curr[i + 1][j - 1] == '*') count++;
		if (curr[i + 1][j] == '*') count++;
	}
	else if (i_rub == "___" and j_rub == ".__") {
		/*
		...
		___
		___
		*/
		if (curr[i - 1][j] == '*') count++;
		if (curr[i + 1][j] == '*') count++;
		if (curr[i][j + 1] == '*') count++;
		if (curr[i + 1][j + 1] == '*') count++;
		if (curr[i - 1][j + 1] == '*') count++;
	}
	else if (i_rub == "___" and j_rub == "___") {
		/*
		___
		___
		___
		*/
		if (curr[i - 1][j - 1] == '*') count++;
		if (curr[i][j - 1] == '*') count++;
		if (curr[i + 1][j - 1] == '*') count++;
		if (curr[i - 1][j] == '*') count++;
		if (curr[i + 1][j] == '*') count++;
		if (curr[i][j + 1] == '*') count++;
		if (curr[i + 1][j + 1] == '*') count++;
		if (curr[i - 1][j + 1] == '*') count++;
	}
	else if (i_rub == "___" and j_rub == "__.") {
		/*
		___
		___
		...
		*/
		if (curr[i - 1][j - 1] == '*') count++;
		if (curr[i][j - 1] == '*') count++;
		if (curr[i + 1][j - 1] == '*') count++;
		if (curr[i - 1][j] == '*') count++;
		if (curr[i + 1][j] == '*') count++;
	}
	else if (i_rub == "__." and j_rub == ".__") {
		/*
		...
		__.
		__.
		*/
		if (curr[i - 1][j] == '*') count++;
		if (curr[i][j + 1] == '*') count++;
		if (curr[i - 1][j + 1] == '*') count++;
	}
	else if (i_rub == "__." and j_rub == "___") {
		/*
		__.
		__.
		__.
		*/
		if (curr[i - 1][j - 1] == '*') count++;
		if (curr[i][j - 1] == '*') count++;
		if (curr[i - 1][j] == '*') count++;
		if (curr[i][j + 1] == '*') count++;
		if (curr[i - 1][j + 1] == '*') count++;
	}
	else if (i_rub == "__." and j_rub == "__.") {
		/*
		__.
		__.
		...
		*/
		if (curr[i - 1][j - 1] == '*') count++;
		if (curr[i][j - 1] == '*') count++;
		if (curr[i - 1][j] == '*') count++;
	}
	return count;
}

game_of_life::game_of_life(int i, int j)
{
	this->sirina = i;
	this->visina = j;
	for (int a = 0; a < this->visina; a++)
	{
		vector<char> v;
		for (int b = 0; b < this->sirina; b++)
		{
			v.push_back(this->slucajna_vrijednost());
		}
		this->curr.push_back(v);
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < curr.size(); i++)
	{
		vector<char> v;
		for (int j = 0; j < curr[i].size(); j++)
		{
			int lives = this->check_neighours(i, j);
			if (curr[i][j] == '*' and (lives < 2 or lives > 3)) {
				v.push_back('-');
			}
			else if (curr[i][j] == '-' and lives == 3) {
				v.push_back('*');
			}
			else {
				v.push_back(curr[i][j]);
			}
		}
		next.push_back(v);
	}
	curr = next;
	next.clear();
}
void game_of_life::iscrtaj()
{
	for (int a = 0; a < curr.size(); a++)
	{
		for (int b = 0; b < curr[a].size(); b++)
		{
			cout << curr[a][b];
		}
		cout << endl;
	}
}



#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Pokemon.h"
#include "Squirtle.h"
#include "Charmander.h"
#include "pikachu.h"
#include "Bulbasaur.h"
using namespace std;
int main() {
	srand(time(0));
	Pokemon* p = new pikachu;
	Pokemon* s = new Squirtle;
	Pokemon* c = new Charmander;
	Pokemon* b = new Bulbasaur;
	Pokemon* p1 = new Pokemon;
	Pokemon* p2 = new Pokemon;
	int pkmn1 = 0, pkmn2 = 0;
	while (pkmn1 < 1 || pkmn1 > 4) {
		cout << "Select the first pokemon to use...\n";
		cout << "1. Pikachu \n 2. Squirtle \n 3. Charmander \n 4. Bulbasaur \n";
		cin >> pkmn1;
		
		switch (pkmn1)
		{
		case 1: p1 = p;
			break;
		case 2: p1 = s;
			break;
		case 3: p1 = c;
			break;
		case 4: p1 = b;
			break;
		default:
			cout << "non-standard input entered. Congratulations.\n";
			
			break;
		}
	}
	while (pkmn2 < 1 || pkmn2 > 4) {
		cout << "Select the second pokemon to use...\n";
		cout << "1. Pikachu \n 2. Squirtle \n 3. Charmander \n 4. Bulbasaur \n";
		cin >> pkmn2;
		switch (pkmn2)
		{
		case 1: p2 = p;
			break;
		case 2: p2 = s;
			break;
		case 3: p2 = c;
			break;
		case 4: p2 = b;
			break;
		default:
			cout << "non-standard input entered. Congratulations.\n";
			
			break;
		}
	}
	
	if (p1->spd >= p2->spd) {

		while (1) {
			//printf ("Player %d, it is your turn, choose an attack: \n", i);
			cout << p1->getName() << " it is your move, choose an attack: \n";
			int atkChoice1;
			int atkChoice2;
			cout << "1. " << p1->movelist[0].atkName << "\n";
			cout << "2. " << p1->movelist[1].atkName << "\n";
			cout << "3. " << p1->movelist[2].atkName << "\n";
			cout << "4. " << p1->movelist[3].atkName << "\n";
			cin >> atkChoice1;
			string opp_type2 = p2->getType();
			double dmg1 = p1->MakeAttack(p1->movelist[atkChoice1 - 1], opp_type2);
			p2->TakeDamage(dmg1);
			cout << "\nPlayer 1 Health: " << max(p1->hp, 0) << "\n";
			cout << "Player 2 Health: " << max(p2->hp, 0) << "\n\n";
			if (p2->hp <= 0) { break; }

			cout << p2->getName() << " it is your move, choose an attack: \n";
			cout << "1. " << p2->movelist[0].atkName << "\n";
			cout << "2. " << p2->movelist[1].atkName << "\n";
			cout << "3. " << p2->movelist[2].atkName << "\n";
			cout << "4. " << p2->movelist[3].atkName << "\n";
			cin >> atkChoice2;
			string opp_type1 = p1->getType();
			double dmg2 = p2->MakeAttack(p2->movelist[atkChoice2 - 1], opp_type1);
			p1->TakeDamage(dmg2);
			cout << "\nPlayer 1 Health: " << max(p1->hp, 0) << "\n";
			cout << "Player 2 Health: " << max(p2->hp, 0) << "\n\n";
			if (p1->hp <= 0) {
				break;
			}
		}
		if (p2->hp <= 0) { cout << "Player 1 is the winner\n"; }
		if (p1->hp <= 0) { cout << "Player 2 is the winner\n"; }

	}

	else if (p2->spd > p1->spd) {

		while (1) {
			//printf ("Player %d, it is your turn, choose an attack: \n", i);

			cout << p2->getName() << " it is your move, choose an attack: \n";
			int atkChoice1;
			int atkChoice2;
			cout << "1. " << p2->movelist[0].atkName << "\n";
			cout << "2. " << p2->movelist[1].atkName << "\n";
			cout << "3. " << p2->movelist[2].atkName << "\n";
			cout << "4. " << p2->movelist[3].atkName << "\n";
			cin >> atkChoice2;
			string opp_type1 = p1->getType();
			double dmg2 = p2->MakeAttack(p2->movelist[atkChoice2 - 1], opp_type1);
			p1->TakeDamage(dmg2);
			cout << "\n" << p1->getName() << " Health: " << max(p1->hp, 0) << "\n";
			cout << p2->getName() << " Health: " << max(p2->hp, 0) << "\n\n";
			if (p1->hp < 0) { break; }

			cout << p1->getName() << " it is your move, choose an attack: \n";
			cout << "1. " << p1->movelist[0].atkName << "\n";
			cout << "2. " << p1->movelist[1].atkName << "\n";
			cout << "3. " << p1->movelist[2].atkName << "\n";
			cout << "4. " << p1->movelist[3].atkName << "\n";
			cin >> atkChoice1;
			string opp_type2 = p2->getType();
			double dmg1 = p1->MakeAttack(p1->movelist[atkChoice1 - 1], opp_type2);
			p2->TakeDamage(dmg1);
			cout << "\n" << p1->getName() << " Health: " << max(p1->hp, 0) << "\n";
			cout << p2->getName() << "  Health: " << max(p2->hp, 0) << "\n\n";
			if (p2->hp <= 0) { break; }
		}

		if (p2->hp <= 0) { cout << p1->getName() << " is the winner\n"; }
		if (p1->hp <= 0) { cout << p2->getName() << " is the winner\n"; }
	}

}


#include "pikachu.h"



pikachu::pikachu() : Pokemon::Pokemon()
{
	spd = 250;
	pkmnType = "Electric";
	pkmnName = "Pikachu";
	movelist[0] = Move("thunderbolt", 90, 100, "Electric");
	movelist[1] = Move("thunder", 110, 75, "Electric");
	movelist[2] = Move("thunderpunch", 75, 100, "Electric");
	movelist[3] = Move("TryItIDareYou", 9001, 10, "Electric");
}


pikachu::~pikachu()
{
}

void pikachu::TakeDamage(double rawDamage)
{
	hp -= rawDamage / def;
	if (rawDamage != 0 && !(rand() % 10)) { spd += 50; } //10% chance when hit to increase speed
}



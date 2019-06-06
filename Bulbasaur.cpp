#include "Bulbasaur.h"



Bulbasaur::Bulbasaur() : Pokemon::Pokemon()
{
	hp = 250;
	pkmnType = "Grass";
	pkmnName = "Bulbasaur";
	movelist[0] = Move("razor leaf", 55, 95, "Grass");
	movelist[1] = Move("vine whip", 45, 100, "Grass");
	movelist[2] = Move("solar beam", 110, 85, "Grass");
	movelist[3] = Move("hydro pump", 110, 80, "Water");
}


Bulbasaur::~Bulbasaur()
{
}

double Bulbasaur::MakeAttack(Move attack, string opp_type)
{
	double hitRoll = rand() % 100 + 1.0; //1-100, lower is better
	if (hitRoll > attack.acc) return 0.0; //miss
	else {
		double randModifier = ((rand() % 16) + 85.0) / 100.0; // .85 to 1.0
		double typeEff = TypeList[attack.atkType][opp_type]; //look up type effectiveness, not sure how I want to pass the attack's type to the defending pokemon's takeDamage
		double overgrowthModifier = (attack.atkType == "Grass" && hp <= 83.33) ? 1.5 : 1.0; // raises the power of Fire type moves for charmander is hp <= 1/3 of max hp
		double rawDamage = ((42.0 * attack.pwr * atk / 50.0) + 2) * randModifier * typeEff * overgrowthModifier;
		return rawDamage;
	}
}

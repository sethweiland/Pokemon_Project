#include "Charmander.h"



Charmander::Charmander() : Pokemon::Pokemon()
{
	atk = 75; //slightly raised attack
	pkmnType = "Fire";
	pkmnName = "Charmander";
	movelist[0] = Move("flamethrower", 90, 100, "Fire");
	movelist[1] = Move("Fire blast", 110, 85, "Fire");
	movelist[2] = Move("thunder punch", 75, 100, "Electric");
	movelist[3] = Move("ember", 40, 100, "Fire");
}


Charmander::~Charmander()
{
}

double Charmander::MakeAttack(Move attack, string opp_type)
{
	double hitRoll = rand() % 100 + 1.0; //1-100, lower is better
	if (hitRoll > attack.acc) return 0.0; //miss
	else {
		double randModifier = ((rand() % 16) + 85.0) / 100.0; // .85 to 1.0
		double blazeModifier = (attack.atkType == "Fire" && hp <= 66.67) ? 1.5 : 1.0; // raises the power of Fire type moves for charmander is hp <= 1/3 of max hp
		double typeEff = TypeList[attack.atkType][opp_type]; //look up type effectiveness, not sure how I want to pass the attack's type to the defending pokemon's takeDamage
		double rawDamage = ((42.0 * attack.pwr * atk / 50.0) + 2) * randModifier * typeEff * blazeModifier;
		return rawDamage;
	}
}

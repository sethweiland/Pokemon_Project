#include "Pokemon.h"


unordered_map<string, map<string, double> > Pokemon::TypeList = Pokemon::make_map();
Pokemon::Pokemon()
{
	atk = 50;//placeholder values
	def = 50;
	spd = 50;
	hp = 200;
}


Pokemon::~Pokemon()
{
}

double Pokemon::MakeAttack(Move attack, string opp_type)
{
	
	double hitRoll = rand() % 100 + 1.0; //1-100, lower is better
	if (hitRoll > attack.acc) return 0.0; //miss
	else {
		double randModifier = ((rand() % 16) + 85.0) / 100.0; // .85 to 1.0
		double typeEff = TypeList[attack.atkType][opp_type]; //look up type effectiveness, not sure how I want to pass the attack's type to the defending pokemon's takeDamage
		double rawDamage = ((42.0 * attack.pwr * atk / 50.0) + 2) * randModifier * typeEff;
		return rawDamage;
	}
	
	
}

void Pokemon::TakeDamage(double rawDamage)
{
	hp -= rawDamage / def; //will probably pass attack type to here
}

Pokemon::Move::Move(string atkName, double pwr, double acc, string atkType)
{
	this->atkName = atkName;
	this->pwr = pwr;
	this->acc = acc;
	this->atkType = atkType;
}

unordered_map<string, map<string, double> > Pokemon::make_map() {

	unordered_map<string, map<string, double> > m;

	m["Fire"]["Normal"] = 1.0;

	m["Fire"]["Fighting"] = 1.0;

	m["Fire"]["Flying"] = 1.0;

	m["Fire"]["Poison"] = 1.0;

	m["Fire"]["Ground"] = 1.0;

	m["Fire"]["Rock"] = 0.5;

	m["Fire"]["Bug"] = 2.0;

	m["Fire"]["Ghost"] = 1.0;

	m["Fire"]["Steel"] = 2.0;

	m["Fire"]["Fire"] = 0.5;

	m["Fire"]["Water"] = 0.5;

	m["Fire"]["Grass"] = 2.0;

	m["Fire"]["Electric"] = 1.0;

	m["Fire"]["Psychic"] = 1.0;

	m["Fire"]["Ice"] = 2.0;

	m["Fire"]["Dragon"] = 0.5;

	m["Fire"]["Dark"] = 1.0;

	m["Fire"]["Fairy"] = 1.0;



	m["Water"]["Normal"] = 1.0;

	m["Water"]["Fighting"] = 1.0;

	m["Water"]["Flying"] = 1.0;

	m["Water"]["Poison"] = 1.0;

	m["Water"]["Ground"] = 2.0;

	m["Water"]["Rock"] = 2.0;

	m["Water"]["Bug"] = 1.0;

	m["Water"]["Ghost"] = 1.0;

	m["Water"]["Steel"] = 1.0;

	m["Water"]["Fire"] = 2.0;

	m["Water"]["Water"] = 0.5;

	m["Water"]["Grass"] = 0.5;

	m["Water"]["Electric"] = 1.0;

	m["Water"]["Psychic"] = 1.0;

	m["Water"]["Ice"] = 1.0;

	m["Water"]["Dragon"] = 0.5;

	m["Water"]["Dark"] = 1.0;

	m["Water"]["Fairy"] = 1.0;



	m["Grass"]["Normal"] = 1.0;

	m["Grass"]["Fighting"] = 1.0;

	m["Grass"]["Flying"] = 0.5;

	m["Grass"]["Poison"] = 0.5;

	m["Grass"]["Ground"] = 2.0;

	m["Grass"]["Rock"] = 2.0;

	m["Grass"]["Bug"] = 0.5;

	m["Grass"]["Ghost"] = 1.0;

	m["Grass"]["Steel"] = 0.5;

	m["Grass"]["Fire"] = 0.5;

	m["Grass"]["Water"] = 2.0;

	m["Grass"]["Grass"] = 0.5;

	m["Grass"]["Electric"] = 1.0;

	m["Grass"]["Psychic"] = 1.0;

	m["Grass"]["Ice"] = 1.0;

	m["Grass"]["Dragon"] = 0.5;

	m["Grass"]["Dark"] = 1.0;

	m["Grass"]["Fairy"] = 1.0;



	m["Electric"]["Normal"] = 1.0;

	m["Electric"]["Fighting"] = 1.0;

	m["Electric"]["Flying"] = 2.0;

	m["Electric"]["Poison"] = 1.0;

	m["Electric"]["Ground"] = 0.0;

	m["Electric"]["Rock"] = 0.5;

	m["Electric"]["Bug"] = 1.0;

	m["Electric"]["Ghost"] = 1.0;

	m["Electric"]["Steel"] = 1.0;

	m["Electric"]["Fire"] = 1.0;

	m["Electric"]["Water"] = 2.0;

	m["Electric"]["Grass"] = 0.5;

	m["Electric"]["Electric"] = 0.5;

	m["Electric"]["Psychic"] = 1.0;

	m["Electric"]["Ice"] = 1.0;

	m["Electric"]["Dragon"] = 0.5;

	m["Electric"]["Dark"] = 1.0;

	m["Electric"]["Fairy"] = 1.0;

	return m;

}
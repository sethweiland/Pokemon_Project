#pragma once
#include "Pokemon.h"
class Bulbasaur :
	public Pokemon
{
public:
	Bulbasaur();
	~Bulbasaur();

	double MakeAttack(Move attack, string opp_type);
};


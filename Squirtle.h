#pragma once
#include "Pokemon.h"
class Squirtle :
	public Pokemon
{
public:
	Squirtle();
	~Squirtle();
	double MakeAttack(Move attack, string opp_type);
};


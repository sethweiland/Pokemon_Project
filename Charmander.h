#pragma once
#include "Pokemon.h"
class Charmander :
	public Pokemon
{
public:
	Charmander();
	
	~Charmander();
	double MakeAttack(Move attack, string opp_type);
};


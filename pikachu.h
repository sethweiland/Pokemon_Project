#pragma once
#include "Pokemon.h"
class pikachu :
	public Pokemon
{
public:
	pikachu();
	~pikachu();
	void TakeDamage(double rawDamage);
};


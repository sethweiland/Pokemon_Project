#pragma once
#include <string>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <ctime>
using namespace std;



class Pokemon
{
public:
	Pokemon();
	~Pokemon();
	
	static unordered_map<string, map<string, double> > make_map();

	static unordered_map<string, map<string, double> > TypeList;
	//in order :atkType, multiplier 
	//try either this approach, or create a double-nested map for all pokemon to share.
	struct Move {
		string atkName;
		double pwr;
		double acc;
		string atkType;
		Move() { atkName = "atk"; pwr = 0.0; acc = 100.0; atkType = "normal"; }
		Move(string atkName, double pwr, double acc, string atkType);
	};
	string pkmnType;
	string pkmnName;
	int hp;
	int atk;
	int def;
	int spd;
	
	Move movelist[4];
	//virtual void passiveEffect() = 0;
	virtual double MakeAttack(Move attack, string opp_type);
	virtual void TakeDamage(double);
	string getType() {
		return pkmnType;
	}
	string getName() {
		return pkmnName;
	}
};


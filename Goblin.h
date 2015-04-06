/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: Goblin.h

Description: This is the interace file for the Goblin Class.
The implementation file is in Goblin.cpp.


*******************************/

//header guards
#ifndef GOBLIN_H
#define GOBLIN_H

#include "Creature.h"
namespace GNIADEK
{
	class Goblin : public Creature
	{
	public:
		Goblin(int armor = 3, int strength = 8, int attackMin = 1, int attackMax = 6,
			int defendMin = 1, int defendMax = 6, int numAtkDice = 2, int numDefDice = 1,
			std::string name = "Goblin", bool magicShield = false, bool eWeapon = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //GOBLIN_H
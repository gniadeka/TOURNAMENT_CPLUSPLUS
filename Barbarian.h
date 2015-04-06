/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: Barbarian.h

Description: This is the interace file for the Barbarian Class.
The implementation file is in Barbarian.cpp.


*******************************/

//header guards
#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Creature.h"
namespace GNIADEK
{
	class Barbarian : public Creature
	{
	public:
		Barbarian(int armor = 0, int strength = 12, int attackMin = 1, int attackMax = 6,
			int defendMin = 1, int defendMax = 6, int numAtkDice = 2, int numDefDice = 2,
			std::string name = "Barbarian", bool magicShield = false, bool eWeapon = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //BARBARIAN_H
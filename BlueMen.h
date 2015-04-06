/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: BlueMen.h

Description: This is the interace file for the BlueMen Class.
The implementation file is in BlueMen.cpp.


*******************************/

//header guards
#ifndef BLUE_MEN_H
#define BLUE_MEN_H

#include "Creature.h"
namespace GNIADEK
{
	class BlueMen : public Creature
	{
	public:
		BlueMen(int armor = 3, int strength = 12, int attackMin = 1, int attackMax = 10,
			int defendMin = 1, int defendMax = 6, int numAtkDice = 2, int numDefDice = 3,
			std::string name = "Blue Men", bool magicShield = false, bool eWeapon = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //BLUE_MEN_H
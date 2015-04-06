/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: ReptilePeople.h

Description: This is the interace file for the ReptilePeople Class.
The implementation file is in ReptilePeople.cpp.


*******************************/

//header guards
#ifndef REPTILE_PEOPLE_H
#define REPTILE_PEOPLE_H

#include "Creature.h"
namespace GNIADEK
{
	class ReptilePeople : public Creature
	{
	public:
		ReptilePeople(int armor = 7, int strength = 18, int attackMin = 1, int attackMax = 6,
			int defendMin = 1, int defendMax = 6, int numAtkDice = 3, int numDefDice = 1,
			std::string name = "Reptile People", bool magicShield = false, bool eWeapon = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //REPTILE_PEOPLE_H
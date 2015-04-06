/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: Dragon.h

Description: This is the interace file for the Dragon Class.
The implementation file is in Dragon.cpp.


*******************************/

//header guards
#ifndef DRAGON_H
#define DRAGON_H

#include "Creature.h"
namespace GNIADEK
{
	class Dragon : public Creature
	{
	public:
		Dragon(int armor = 10, int strength = 20, int attackMin = 1, int attackMax = 12,
			int defendMin = 1, int defendMax = 8, int numAtkDice = 3, int numDefDice = 3,
			std::string name = "Dragon", bool magicShield = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //DRAGON_H
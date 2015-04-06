/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: Chieftain.h

Description: This is the interace file for the Chieftain Class.
The implementation file is in Chieftain.cpp.


*******************************/

//header guards
#ifndef CHIEFTAIN_H
#define CHIEFTAIN_H

#include "Creature.h"
#include "Barbarian.h"
namespace GNIADEK
{
	class Chieftain : public Barbarian
	{
	public:
		Chieftain(int armor = 1, int strength = 14, int attackMin = 1, int attackMax = 8,
			int defendMin = 1, int defendMax = 6, int numAtkDice = 2, int numDefDice = 2,
			std::string name = "Chieftain", bool magicShield = false, bool eWeapon = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //CHIEFTAIN_H
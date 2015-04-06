/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: EnchantedHobbit.h

Description: This is the interace file for the EnchantedHobbit Class.
The implementation file is in EnchantedHobbit.cpp.


*******************************/

//header guards
#ifndef ENCHANTED_HOBBIT_H
#define ENCHANTED_HOBBIT_H

#include "Creature.h"
namespace GNIADEK
{
	//NOTE: enchanted hobbit always starts with a magic shield
	class EnchantedHobbit : public Creature
	{
	public:
		EnchantedHobbit(int armor = 2, int strength = 10, int attackMin = 1, int attackMax = 6,
			int defendMin = 1, int defendMax = 8, int numAtkDice = 2, int numDefDice = 1,
			std::string name = "Enchanted Hobbit", bool magicShield = true, bool eWeapon = true, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const; //returns the armor
		virtual std::string getName() const;
		virtual int getStrength() const; //returns the strength points 
		virtual void setStrength(int newStrength);
		virtual int attack() const;
		virtual int defend() const;
	};
}






#endif //ENCHANTED_HOBBIT_H
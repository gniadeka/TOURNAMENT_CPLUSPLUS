/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: ReptilePeople.cpp

Description: This is the implementation file for the ReptilePeople class.
The interface file is stored in ReptilePeople.h.

*******************************/


#include "ReptilePeople.h"

namespace GNIADEK
{
	ReptilePeople::ReptilePeople(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield,bool eWeapon, int playerNum, int winCount) :
		Creature(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, eWeapon, playerNum, winCount)
	{}

	int ReptilePeople::getArmor() const
	{
		return (this->int_Armor);
	}
	int ReptilePeople::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string ReptilePeople::getName() const
	{
		return creatureName;
	}
	void ReptilePeople::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int ReptilePeople::attack() const
	{
		
			int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			int diceThree = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			return (diceOne + diceTwo + diceThree);
		
	}

	int ReptilePeople::defend() const
	{
		
			int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			return (diceOne);
		
	}

}
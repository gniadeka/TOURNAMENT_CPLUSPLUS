/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: BlueMen.cpp

Description: This is the implementation file for the BlueMen class.
The interface file is stored in BlueMen.h.

*******************************/


#include "BlueMen.h"

namespace GNIADEK
{
	BlueMen::BlueMen(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, bool eWeapon, int playerNum, int winCount) :
		Creature(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, eWeapon, playerNum, winCount)
	{}



	int BlueMen::getArmor() const
	{
		return (this->int_Armor);
	}
	int BlueMen::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string BlueMen::getName() const
	{
		return creatureName;
	}
	void BlueMen::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int BlueMen::attack() const
	{
		
			int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			return (diceOne + diceTwo);
		
	}

	int BlueMen::defend() const
	{
		
			int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			int diceTwo = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			int diceThree = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			return (diceOne + diceTwo + diceThree);
		
	
	}
}
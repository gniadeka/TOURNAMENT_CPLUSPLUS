/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: Dragon.cpp

Description: This is the implementation file for the Dragon class.
The interface file is stored in Dragon.h.

*******************************/


#include "Dragon.h"

namespace GNIADEK
{
	Dragon::Dragon(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, int playerNum, int winCount) :
		Creature(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, playerNum, winCount)
	{}

	int Dragon::getArmor() const
	{
		return (this->int_Armor);
	}
	int Dragon::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string Dragon::getName() const
	{
		return creatureName;
	}
	void Dragon::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int Dragon::attack() const
	{

		int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		int diceThree = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		return (diceOne + diceTwo + diceThree);

	}

	int Dragon::defend() const
	{

		int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
		int diceTwo = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
		int diceThree = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
		return (diceOne + diceTwo + diceThree);

	}
}
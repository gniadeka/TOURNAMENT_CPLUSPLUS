/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: EnchantedHobbit.cpp

Description: This is the implementation file for the EnchantedHobbit class.
The interface file is stored in EnchantedHobbit.h.

*******************************/


#include "EnchantedHobbit.h"

namespace GNIADEK
{
	EnchantedHobbit::EnchantedHobbit(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, bool eWeapon, int playerNum, int winCount) :
		Creature(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, eWeapon, playerNum, winCount)
	{}

	int EnchantedHobbit::getArmor() const
	{
		return (this->int_Armor);
	}
	int EnchantedHobbit::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string EnchantedHobbit::getName() const
	{
		return creatureName;
	}
	void EnchantedHobbit::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int EnchantedHobbit::attack() const
	{

		int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		return ((diceOne + diceTwo) * 2);

	}

	int EnchantedHobbit::defend() const
	{

		int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
		return (diceOne);

	}
}
/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: Goblin.cpp

Description: This is the implementation file for the Goblin class.
The interface file is stored in Goblin.h.

*******************************/


#include "Goblin.h"

namespace GNIADEK
{
	Goblin::Goblin(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, bool eWeapon, int playerNum, int winCount) :
		Creature(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, eWeapon, playerNum, winCount)
	{}

	int Goblin::getArmor() const
	{
		return (this->int_Armor);
	}
	int Goblin::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string Goblin::getName() const
	{
		return creatureName;
	}
	void Goblin::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int Goblin::attack() const
	{
		int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		return (diceOne + diceTwo);
	
	}

	int Goblin::defend() const
	{
		
			int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			return (diceOne);
		
	}

}
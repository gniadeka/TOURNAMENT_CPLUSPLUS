/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: Barbarian.cpp

Description: This is the implementation file for the Barbarian class.
The interface file is stored in Barbarian.h.

*******************************/


#include "Barbarian.h"

namespace GNIADEK
{
	Barbarian::Barbarian(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, bool eWeapon, int playerNum, int winCount) :
		Creature(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, eWeapon, playerNum, winCount)
	{}

	int Barbarian::getArmor() const
	{
		return (this->int_Armor);
	}
	int Barbarian::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string Barbarian::getName() const
	{
		return creatureName;
	}
	void Barbarian::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int Barbarian::attack() const
	{
		
			int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
			return (diceOne + diceTwo);
		
	}

	int Barbarian::defend() const
	{
		
			int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			int diceTwo = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
			return (diceOne + diceTwo);
		
	}
}
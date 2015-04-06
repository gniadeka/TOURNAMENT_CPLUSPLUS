/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: Chieftain.cpp

Description: This is the implementation file for the Chieftain class.
The interface file is stored in Chieftain.h.

*******************************/


#include "Chieftain.h"

namespace GNIADEK
{
	Chieftain::Chieftain(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, bool eWeapon, int playerNum, int winCount) :
		Barbarian(armor, strength, attackMin, attackMax, defendMin, defendMax, numAtkDice, numDefDice, name, magicShield, eWeapon, playerNum, winCount)
	{}

	int Chieftain::getArmor() const
	{
		return (this->int_Armor);
	}
	int Chieftain::getStrength() const
	{
		return (this->int_Strength_Points);
	}

	std::string Chieftain::getName() const
	{
		return creatureName;
	}
	void Chieftain::setStrength(int newStrength)
	{
		int_Strength_Points = newStrength;
	}

	int Chieftain::attack() const
	{

		int diceOne = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		int diceTwo = (rand()) % ((((this->attackMax) - (this->attackMin)) + 1) + (this->attackMin));
		return (diceOne + diceTwo);

	}

	int Chieftain::defend() const
	{

		int diceOne = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
		int diceTwo = (rand()) % ((((this->defendMax) - (this->defendMin)) + 1) + (this->defendMin));
		return (diceOne + diceTwo);

	}
}
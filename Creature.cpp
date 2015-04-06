/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: Creature.cpp

Description: This is the implementation file for
the Creature class.  The interface file is
called Creature.h.

*******************************/

//include directives
#include "Creature.h"
#include <ctime>
#include <cstdlib>

namespace GNIADEK
{
	Creature::Creature(int armor, int strength, int attackMin, int attackMax,
		int defendMin, int defendMax, int numAtkDice, int numDefDice, std::string name, bool magicShield, bool eWeapon, int playerNum, int winCount) :
		int_Armor(armor),
		int_Strength_Points(strength),
		attackMin(attackMin),
		attackMax(attackMax),
		defendMin(defendMin),
		defendMax(defendMax),
		numAtkDice(numAtkDice),
		numDefDice(numDefDice),
		creatureName(name),
		magicShield(magicShield),
		enchantedWeapon(eWeapon),
		playerNum(playerNum),
		winCount(winCount)
	{}

	int Creature::getWinCount() const
	{
		return winCount;
	}
	
	
	
	void Creature::setWinCount(int win)
	{
		winCount += win;
	}
	
	bool Creature::operator >  (Creature* secondCreature)
	{
		if (this->winCount > secondCreature->getWinCount())
		{
			return true;
		}
		else {
			return false;
		}
	}
	int Creature::getPlayerNum() const
	{
		return playerNum;
	}
	
	void Creature::setPlayerNum(int newNum)
	{
		playerNum = newNum;
	}


	bool Creature::getMagicShield() const
	{
		return magicShield;
	}
	void Creature::setMagicShield(bool newShield)
	{
		magicShield = newShield;
	}

	bool Creature::getEnchantedWeapon() const
	{
		return enchantedWeapon;
	}

	void Creature::setEnchantedWeapon(bool newWeapon)
	{
		enchantedWeapon = newWeapon;
	}


}
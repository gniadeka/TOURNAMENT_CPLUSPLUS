/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: Creature.h

Description: This is the interface file for the Creature class.
This class is an abstract base class.
The implementation file is Creature.cpp

*******************************/

//header guards
#ifndef CREATURE_H
#define CREATURE_H

#include <string>

namespace GNIADEK
{
	//abstract base class for all Creatures
	class Creature {
	public:
		//The constructor for the Creature class
		Creature(int armor = 0, int strength = 0, int attackMin = 0, int attackMax = 0,
			int defendMin = 0, int defendMax = 0, int numAtkDice = 0, int numDefDice = 0,
			std::string name = "default", bool magicShield = false, bool eWeapon = false, int playerNum = 0,
			int winCount = 0);
		virtual int getArmor() const = 0; //returns the armor
		virtual std::string getName() const = 0;
		virtual int getStrength() const = 0; //returns the strength points 
		virtual void setStrength(int newStrength) = 0;
		virtual int attack() const = 0;
		virtual int defend() const = 0;
		virtual bool getMagicShield() const;
		virtual void setMagicShield(bool newShield);
		virtual bool getEnchantedWeapon() const;
		virtual void setEnchantedWeapon(bool newWeapon);
		virtual int getPlayerNum() const;
		virtual void setPlayerNum(int newNum);
		virtual bool operator>(Creature* secondCreature);
		virtual int getWinCount() const;
		
		virtual void setWinCount(int win = 1);

	protected:
		int int_Armor;
		int int_Strength_Points;
		int attackMin;
		int attackMax;
		int defendMin;
		int defendMax;
		int numAtkDice;
		int numDefDice;
		std::string creatureName;
		bool magicShield;
		bool enchantedWeapon;
		int playerNum;
		int winCount;
	};
}

#endif //CREATURE_H
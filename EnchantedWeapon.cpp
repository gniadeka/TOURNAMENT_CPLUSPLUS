/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: EnchantedWeapon.cpp

Description: This is the implementation for the EnchantedWeapon class.
The interface file for this class is EnchantedWeapon.h


*******************************/

#include "EnchantedWeapon.h"

namespace GNIADEK
{
	EnchantedWeapon::EnchantedWeapon(int enchanted) :
		enchantedDmg(enchanted)
	{}


	int EnchantedWeapon::getEnchantedWeapon() const
	{
		return enchantedDmg;

	}

}
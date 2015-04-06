/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: EnchantedWeapon.h

Description: This is the interface file for the EnchantedWeapon class.
The implementation file is the EnchantedWeapon.cpp

*******************************/


//header guards
#ifndef ENCHANTED_WEAPON_H
#define ENCHANTED_WEAPON_H

namespace GNIADEK
{
	class EnchantedWeapon {
	public:
		EnchantedWeapon(int enchanted = 10);
		int getEnchantedWeapon() const;
		

	private:
		int enchantedDmg;
	};
}


#endif //ENCHANTED_WEAPON_H
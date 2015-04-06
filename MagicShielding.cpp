/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: MagicShielding.cpp

Description: This is the implementation for the MagicShielding class.
The interface file for this class is MagicShielding.h


*******************************/

#include "MagicShielding.h"

namespace GNIADEK
{
	MagicShielding::MagicShielding(int shielding) :
		shieldPoints(shielding)
	{}


	int MagicShielding::getMagicShielding() const
	{
		return shieldPoints;

	}
	void MagicShielding::setMagicShielding(int newShield)
	{
		shieldPoints = newShield;
	}
}
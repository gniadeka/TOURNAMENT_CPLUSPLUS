/*******************************
Name: Andrew Gniadek
Date: 8/13/2014
Date Last Modified: 8/13/2014
File Name: MagicShielding.h

Description: This is the interface file for the MagicShielding class.
The implementation file is the MagicShielding.cpp

*******************************/


//header guards
#ifndef MAGIC_SHIELDING_H
#define MAGIC_SHIELDING_H

namespace GNIADEK
{
	class MagicShielding {
	public:
		MagicShielding(int shielding = 100);
		int getMagicShielding() const;
		void setMagicShielding(int newShield);

	private:
		int shieldPoints;





	};
}


#endif //MAGIC_SHIELDING_H
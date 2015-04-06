/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: GameStateManage.cpp

Description: This is the implementation file for the
GameStateManage class.  The interface file
is GameStateManage.h

*******************************/

#include "GameStateManage.h"
#include "Dragon.h"
#include "MagicShielding.h"
#include "Goblin.h"
#include "Barbarian.h"
#include "ReptilePeople.h"
#include "Chieftain.h"
#include "EnchantedHobbit.h"
#include "EnchantedWeapon.h"
#include "BlueMen.h"
#include <iostream>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>


namespace GNIADEK
{

	void GameStateManage::chooseCombatants(std::queue<GNIADEK::Creature*>& lineup)
	{
		while (lineup.size() != 6)
		{
			Creature* nextCreaturePtr = CreatureChoice(validateUserInput());
			std::cout << "You selected " << nextCreaturePtr->getName() << " as a combatant!\n";
			lineup.push(nextCreaturePtr);
		}

	}

	GNIADEK::Creature* GameStateManage::CreatureChoice(int choice)
	{
		int randNum = 0;
		GNIADEK::Creature* creaturePtr = 0;

		if (choice == 1)
		{
			creaturePtr = new Goblin;
			randNum = rand() % 10 + 1;
			if (randNum % 2 == 0)
			{
				creaturePtr->setMagicShield(true);
			}

			if (randNum % 3 == 0)
			{
				creaturePtr->setEnchantedWeapon(true);
			}

			return creaturePtr;

		}

		if (choice == 2)
		{
			creaturePtr = new Barbarian;
			randNum = rand() % 10 + 1;
			if (randNum % 2 == 0)
			{
				creaturePtr->setMagicShield(true);
			}

			if (randNum % 3 == 0)
			{
				creaturePtr->setEnchantedWeapon(true);
			}


			return creaturePtr;
		}

		if (choice == 3)
		{
			creaturePtr = new ReptilePeople;
			randNum = rand() % 10 + 1;
			if (randNum % 2 == 0)
			{
				creaturePtr->setMagicShield(true);
			}

			if (randNum % 3 == 0)
			{
				creaturePtr->setEnchantedWeapon(true);
			}


			return creaturePtr;
		}

		if (choice == 4)
		{
			creaturePtr = new BlueMen;
			randNum = rand() % 10 + 1;
			if (randNum % 2 == 0)
			{
				creaturePtr->setMagicShield(true);
			}

			if (randNum % 3 == 0)
			{
				creaturePtr->setEnchantedWeapon(true);
			}


			return creaturePtr;
		}

		if (choice == 5)
		{
			creaturePtr = new Dragon;
			randNum = rand() % 10 + 1;
			if (randNum % 2 == 0)
			{
				creaturePtr->setMagicShield(true);
			}

			//Dragons can't use an enchanted weapon because of their claws :)

			return creaturePtr;
		}


		if (choice == 6)
		{
			creaturePtr = new Chieftain;
			randNum = rand() % 10 + 1;
			if (randNum % 2 == 0)
			{
				creaturePtr->setMagicShield(true);
			}

			if (randNum % 3 == 0)
			{
				creaturePtr->setEnchantedWeapon(true);
			}

			return creaturePtr;
		}

		if (choice == 7)
		{
			//NOTE: The EnchantedHobbit always starts with
			//magic shield and enchanted weapon
			creaturePtr = new EnchantedHobbit;
			return creaturePtr;
		}


	}

	void GameStateManage::chooseCombatants(Creature* contestant[2], std::queue<Creature*>& firstPlayerLineup, std::queue<Creature*>& secondPlayerLineup)
	{
		if ((firstPlayerLineup.empty()) || (secondPlayerLineup.empty()))
		{
			return;
		}
		else {
			contestant[0] = firstPlayerLineup.front();
			contestant[0]->setPlayerNum(1);
			contestant[1] = secondPlayerLineup.front();
			contestant[1]->setPlayerNum(2);
		}
		
	}

	bool GameStateManage::combat(Creature* contestant[2], std::queue<Creature*>& firstPlayerLineup, std::queue<Creature*>& secondPlayerLineup, std::stack<Creature*>& loserPile) const
	{
		
		MagicShielding twoShields[2];
		bool combatGoing = true;

		std::cout << "\n\nThe next fight is between " << contestant[0]->getName() << " and " << contestant[1]->getName();
		std::cout << "!!\n\n" << std::endl;
		
		//loops through the array to see who has a magic shield
		for (int i = 0; i < 2; ++i)
		{
			if (contestant[i]->getMagicShield() == true)
			{
				std::cout << "\n" << "***************" << std::endl;
				std::cout << contestant[i]->getName() << " is surrounded by a Magic Shield!!\n" << std::endl;
				std::cout << "***************" << std::endl;
			}
		}

		//loops through the array to see who has an enchanted weapon
		for (int i = 0; i < 2; ++i)
		{
			if (contestant[i]->getEnchantedWeapon() == true)
			{
				std::cout << "\n" << "***************" << std::endl;
				std::cout << contestant[i]->getName() << " is armed with an Enchanted Weapon!!\n" << std::endl;
				std::cout << "***************" << std::endl;
			}
		}




		std::cout << "\n\nBEGIN COMBAT!!\n\n" << std::endl;

		while (combatGoing)
		{
			//contestant[0] round
			firstCombatant(contestant, twoShields);
	
			if (contestant[1]->getStrength() <= 0)
			{
				victory(contestant[0]->getName());
				contestant[0]->setWinCount();
				loserPile.push(contestant[1]);
				secondPlayerLineup.pop();
				return true;
			}

			//contestant[1] round

			secondCombatant(contestant, twoShields);

			if (contestant[0]->getStrength() <= 0)
			{
				victory(contestant[1]->getName());
				contestant[1]->setWinCount();
				loserPile.push(contestant[0]);
				firstPlayerLineup.pop();
				return false;
			}
		}
	}
	bool GameStateManage::compareCreatures(Creature*first, Creature* second)
	{
		return((*first) > second);
	}
	int GameStateManage::teamRemainder(std::queue<Creature*>& firstPlayerLineup, std::queue<Creature*>& secondPlayerLineup, std::stack<Creature*>& loserPile)
	{
		std::vector<Creature*> firstPlayerLeft;
		std::vector<Creature*> secondPlayerLeft;

		std::cout << "\n\n*****FINAL STANDINGS*****\n\n" << std::endl;
		while (!(firstPlayerLineup.empty()))
		{
			Creature* nextCPtr = firstPlayerLineup.front();
			nextCPtr->setPlayerNum(1);
			firstPlayerLineup.pop();
			firstPlayerLeft.push_back(nextCPtr);
		}

		if (!(firstPlayerLeft.empty()))
		{
			int count = 0;
			std::sort(firstPlayerLeft.begin(), firstPlayerLeft.end());
			count = determineWinner(firstPlayerLeft);
			/*for (std::vector<Creature*>::iterator i = secondPlayerLeft.begin(); i != secondPlayerLeft.end(); ++i)
			{
			std::cout << count << " - " << (*i)->getName() << " from Team " << (*i)->getPlayerNum() << std::endl;
			++count;
			}*/

			return count;

		}
		while (!(secondPlayerLineup.empty()))
		{
			Creature* nextQPtr = secondPlayerLineup.front();
			nextQPtr->setPlayerNum(2);
			secondPlayerLineup.pop();
			secondPlayerLeft.push_back(nextQPtr);
		}


		if (!(secondPlayerLeft.empty()))
		{
			int count = 0;
			std::sort(secondPlayerLeft.begin(), secondPlayerLeft.end());
			 count = determineWinner(secondPlayerLeft);
			/*for (std::vector<Creature*>::iterator i = secondPlayerLeft.begin(); i != secondPlayerLeft.end(); ++i)
			{
				std::cout << count << " - " << (*i)->getName() << " from Team " << (*i)->getPlayerNum() << std::endl;
				++count;
			}*/

			return count;

		}

		return 0;
	}



	//this function determines the rankings
	//if two of the creatures have the same win count
	// and they are on the winning team
	
	int GameStateManage::determineWinner(std::vector<Creature*> v)
	{
		std::vector<Creature*>::iterator j;
		int randNum = 0;
		int count = 1;
		for (std::vector<Creature*>::iterator i = v.begin(); i != v.end(); ++i)
		{
			
			if (i != v.begin())
			{
				if ((*(j))->getWinCount() == (*i)->getWinCount())
				{
					randNum = rand() % 2 + 1;
					if (randNum % 2)
					{
						
						std::cout << count << " - " << (*i)->getName() << " from Team " << (*i)->getPlayerNum() << std::endl;
					}
					else {
						std::cout << count << " - " << (*(j))->getName() << " from Team " << (*j)->getPlayerNum() << std::endl;
					}

				}
				else {
						std::cout << count << " - " << (*i)->getName() << " from Team " << (*i)->getPlayerNum() << std::endl;
				}

			} else {

						std::cout << count << " - " << (*i)->getName() << " from Team " << (*i)->getPlayerNum() << std::endl;
			}
			j = i;
			++count;
		}
		return count;
	}
	//This function declares the victor
	void GameStateManage::victory(std::string victorName) const
	{
		std::cout << victorName << " wins!!" << std::endl;

	}


	//This recursive function prints the menu choices
	void GameStateManage::prnt_menu(std::string menuChoices[7], int num_fields) const
	{
		if (num_fields == 0)
		{
			std::cout << num_fields + 1 << " - " << menuChoices[num_fields] << std::endl;
		}
		else
		{
			prnt_menu(menuChoices, num_fields - 1);
			std::cout << num_fields + 1 << " - " << menuChoices[num_fields] << std::endl;
		}
	}

	//This function validates the user input for the menu
	int GameStateManage::validateUserInput() const
	{
		int iInput = 0;
		std::string invalidChoice = "\nPlease enter a valid integer.\n";
		std::string menuPrompt = "Please enter a number corresponding to a combatant: ";

		std::cout << menuPrompt;

		while (!(std::cin >> iInput) || iInput < 1|| iInput > 7)
		{
			std::cin.clear();
			std::cin.ignore(CHAR_MAX, '\n');
			std::cout << invalidChoice;
			std::cout << menuPrompt;
		}


		std::cin.ignore(CHAR_MAX, '\n');
		return iInput;
	}



	void GameStateManage::clearArray(Creature* contestant[2]) const
	{
		contestant[0] = 0;
		contestant[1] = 0;
	}
	bool GameStateManage::stillPlaying() const
	{
		std::string menuPrompt = "Do you want to start another tournament?\nEnter y or n: ";
		std::string invalidChoice = "Invalid selection.  Please enter y or n.\n";
		std::string cInput = "";
		bool playAgain = false;

		while (!playAgain)
		{
			std::cout << menuPrompt << std::endl;
			std::cin >> cInput;
			if (cInput.compare("y") == 0)
			{
				return true;
			}
			else if (cInput.compare("n") == 0)
			{
				return false;
			}
			else
			{
				std::cout << invalidChoice;
			}
		}
	}

	void GameStateManage::secondCombatant(Creature* contestant[2], MagicShielding shield[2]) const
	{
		int contestTwoDmg = 0;
		int magicShieldingLeft = 0;
		EnchantedWeapon encSword;

		std::cout << contestant[1]->getName() << " attacks " << contestant[0]->getName() << std::endl;

		if (contestant[0]->getMagicShield() == true)
		{
			if (shield[0].getMagicShielding() > 0)
			{
				if (contestant[1]->getEnchantedWeapon() == true)
				{
					contestTwoDmg = (contestant[1]->attack() + encSword.getEnchantedWeapon());

				}
				else
				{
					contestTwoDmg = (contestant[1]->attack());
				}


				if ((shield[0].getMagicShielding() - contestTwoDmg) > 0)
				{
					shield[0].setMagicShielding(shield[0].getMagicShielding() - contestTwoDmg);
					std::cout << contestant[0]->getName() << "'s Magic Shield absorbs " << contestTwoDmg << std::endl;
				}
				else if ((shield[0].getMagicShielding() - contestTwoDmg) == 0)
				{
					shield[0].setMagicShielding(shield[0].getMagicShielding() - contestTwoDmg);
					std::cout << contestant[0]->getName() << "'s Magic Shield absorbs " << contestTwoDmg << std::endl;
					contestant[0]->setMagicShield(false);
				}
				else {
					magicShieldingLeft = (-1) * (shield[0].getMagicShielding() - contestTwoDmg);
					contestTwoDmg = (magicShieldingLeft - contestant[0]->defend() - contestant[0]->getArmor());
					if (contestTwoDmg < 0)
					{
						contestTwoDmg = 0;
					}
					std::cout << "********" << contestant[0]->getName() << "'s Magic Shielding explodes in a flash of light!  It's gone!!" << "********" << std::endl;
					std::cout << contestant[0]->getName() << " takes " << contestTwoDmg << std::endl;
					contestant[0]->setStrength(contestant[0]->getStrength() - contestTwoDmg);
					contestant[0]->setMagicShield(false);
				}

			}
		}
		else {
			if (contestant[1]->getEnchantedWeapon() == true)
			{
				contestTwoDmg = ((contestant[1]->attack() + encSword.getEnchantedWeapon()) - contestant[0]->defend()) - contestant[0]->getArmor();
			}
			else
			{
				contestTwoDmg = (contestant[1]->attack() - contestant[0]->defend()) - contestant[0]->getArmor();
			}

			//contestTwoDmg = (contestant[1]->attack() - contestant[0]->defend()) - contestant[0]->getArmor();
			if (contestTwoDmg < 0)
			{
				contestTwoDmg = 0;
			}
			std::cout << contestant[0]->getName() << " takes " << contestTwoDmg << std::endl;
			contestant[0]->setStrength(contestant[0]->getStrength() - contestTwoDmg);
		}
	}
	void GameStateManage::firstCombatant(Creature* contestant[2], MagicShielding shield[2]) const
	{

		int contestOneDmg = 0;
		int magicShieldingLeft = 0;
		EnchantedWeapon encSword;


		std::cout << contestant[0]->getName() << " attacks " << contestant[1]->getName() << std::endl;

		//deal with magic shielding
		if (contestant[1]->getMagicShield() == true)
		{
			if (shield[1].getMagicShielding() > 0)
			{
				if (contestant[0]->getEnchantedWeapon() == true)
				{
					contestOneDmg = (contestant[0]->attack() + encSword.getEnchantedWeapon());

				}
				else
				{
					contestOneDmg = (contestant[0]->attack());
				}

				if ((shield[1].getMagicShielding() - contestOneDmg) > 0)
				{
					shield[1].setMagicShielding(shield[1].getMagicShielding() - contestOneDmg);
					std::cout << contestant[1]->getName() << "'s Magic Shield absorbs " << contestOneDmg << std::endl;
				}
				else if ((shield[1].getMagicShielding() - contestOneDmg) == 0)
				{
					shield[1].setMagicShielding(shield[1].getMagicShielding() - contestOneDmg);
					std::cout << contestant[1]->getName() << "'s Magic Shield absorbs " << contestOneDmg << std::endl;
					contestant[1]->setMagicShield(false);
				}
				else {
					magicShieldingLeft = (-1) * (shield[1].getMagicShielding() - contestOneDmg);
					contestOneDmg = (magicShieldingLeft - contestant[1]->defend() - contestant[1]->getArmor());

					if (contestOneDmg < 0)
					{
						contestOneDmg = 0;
					}
					std::cout << "********" << contestant[1]->getName() << "'s Magic Shielding explodes in a flash of light!  It's gone!!" << "********" << std::endl;
					std::cout << contestant[1]->getName() << " takes " << contestOneDmg << std::endl;
					contestant[1]->setStrength(contestant[1]->getStrength() - contestOneDmg);
					contestant[1]->setMagicShield(false);
				}

			}
		}
		else {

			if (contestant[0]->getEnchantedWeapon() == true)
			{
				contestOneDmg = ((contestant[0]->attack() + encSword.getEnchantedWeapon()) - contestant[1]->defend()) - contestant[1]->getArmor();
			}
			else
			{
				contestOneDmg = (contestant[0]->attack() - contestant[1]->defend()) - contestant[1]->getArmor();
			}


			if (contestOneDmg < 0)
			{
				contestOneDmg = 0;
			}
			std::cout << contestant[1]->getName() << " takes " << contestOneDmg << std::endl;
			contestant[1]->setStrength(contestant[0]->getStrength() - contestOneDmg);
		}
	}
}



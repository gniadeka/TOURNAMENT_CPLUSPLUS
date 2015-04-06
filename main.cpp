/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: main.cpp

Description: This is the application file for the Fantasy Combat
program.  

*******************************/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include "Goblin.h"
#include "Barbarian.h"
#include "ReptilePeople.h"
#include "BlueMen.h"
#include "GameStateManage.h"
#include "Dragon.h"
#include "Chieftain.h"
#include "EnchantedHobbit.h"
#include "EnchantedWeapon.h"

int main()
{
	//array of string choices for the combatnts
	std::string menuChoices[7] = { "Goblin", "Barbarian", "Reptile People", "Blue Men", "Dragon", "Chieftain", "Enchanted Hobbit" };
	const int menuConst = 6;
	
	//loser pile
	std::stack<GNIADEK::Creature*> loserPile;

	//first player's lineup
	std::queue<GNIADEK::Creature*> firstPlayerQ;

	//second player's lineup
	std::queue<GNIADEK::Creature*> secondPlayerQ;


	//boolean that manages the main game loop
	bool stillPlaying = true;

	
	//welcome string to the user
	std::string welcomePrompt = "Welcome to the Fantasy Universe Tournament Edition!!!\n\n";

	//instructions to let the user know what to do
	std::string instructionsPrompt = "Each player selects six combatants.  The tournament will proceed and the standings posted at the end.\n";


	//instructions that make clear what inputs are required of the user
	std::string instructionsPrompts = "Select a number corresponding to the combatant in the menu below. You an choose six creatures per team.\n";

	//Instantiates a GameStateManage object
	GNIADEK::GameStateManage gameState;

	//Instantiates an array of Creature pointers
	GNIADEK::Creature* contestants[2];

	//count offset for rankings
	int finalRank = 0;

	//keep track of team wins
	int teamOne = 0;
	int teamTwo = 0;

	srand(static_cast<unsigned int>(time(0))); //seed the random number generator

	std::cout << welcomePrompt << "\n\n";
	std::cout << instructionsPrompt << "\n\n";

	//MAIN GAME LOOP
	while (stillPlaying)
	{
		std::cout << "Player 1: " << instructionsPrompts << "\n\n";
		gameState.prnt_menu(menuChoices, menuConst);
		gameState.chooseCombatants(firstPlayerQ);
		std::cout << "Player 2: " << instructionsPrompts << "\n\n";
		gameState.prnt_menu(menuChoices, menuConst);
		gameState.chooseCombatants(secondPlayerQ);
		gameState.chooseCombatants(contestants, firstPlayerQ, secondPlayerQ);

		//The combat while loop
		while (!(firstPlayerQ.empty()) && !(secondPlayerQ.empty()))
		{
			if (gameState.combat(contestants, firstPlayerQ, secondPlayerQ, loserPile) == true)
			{
				++teamOne;
			}
			else {
				++teamTwo;
			}
				
			gameState.clearArray(contestants);
			gameState.chooseCombatants(contestants, firstPlayerQ, secondPlayerQ);
		}

		//This determines where to start standing number based
		//on whatever remaining members are left on the winning
		//team
		finalRank = gameState.teamRemainder(firstPlayerQ, secondPlayerQ, loserPile);
		int pileSize = loserPile.size();
		for (int i = 0; i < pileSize; ++i)
		{
			int rankNum = i + finalRank;
			GNIADEK::Creature* nextPtr = loserPile.top();
			loserPile.pop();
			std::cout << rankNum << " - " << nextPtr->getName() << " from Team " << nextPtr->getPlayerNum() << std::endl;
		}

		//line break to space out the standing from the winner announcement
		std::cout << std::endl;

		//use the final win count to determine the winner
		if (teamOne > teamTwo)
		{
			std::cout << "Team One wins!!!\n\n" << std::endl;
		}else 
			{

				std::cout << "Team Two wins!!!\n\n" << std::endl;
			}

		//asks the player whether he/she wishes to play again
		stillPlaying = gameState.stillPlaying();

		//resets the final rank number if the player 
		//decides to play again
		finalRank = 0;
	}
	return 0;

}

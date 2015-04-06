/*******************************
Name: Andrew Gniadek
Date: 7/27/2014
Date Last Modified: 7/27/2014
File Name: GameStateManage.h

Description:  This is the interface file for GameStateManage
class.  The implementation file is in GameStateManage.cpp


*******************************/



//header guards
#ifndef GAME_STATE_MANAGE_H
#define GAME_STATE_MANAGE_H

#include "Creature.h"
#include "MagicShielding.h"
#include <string>
#include <queue>
#include <stack>

namespace GNIADEK
{
	class GameStateManage
	{
	public:
		bool combat(Creature* contestant[2], std::queue<Creature*>& firstPlayerLineup, std::queue<Creature*>& secondPlayerLineup, std::stack<Creature*>& loserPile) const;
		int teamRemainder(std::queue<Creature*>& firstPlayerLineup, std::queue<Creature*>& secondPlayerLineup, std::stack<Creature*>& loserPile);
		bool compareCreatures(Creature*first, Creature* second);
		int determineWinner(std::vector<Creature*> v);
		void victory(std::string victorName) const;
		bool stillPlaying() const;
		void clearArray(Creature* contestant[2]) const;
		void chooseCombatants(std::queue<GNIADEK::Creature*>& lineup);
		void prnt_menu(std::string menuChoices[4], int num_fields) const;
		int validateUserInput() const;
		void selectCombatants(int contestantOne, int contestantTwo, Creature* contestant[2]) const;
		GNIADEK::Creature* CreatureChoice(int choice);
		void chooseCombatants(Creature* contestants[2], std::queue<Creature*>& firstPlayerLineup, std::queue<Creature*>& secondPlayerLineup);
	private:
		void firstCombatant(Creature* contestant[2], MagicShielding shield[2]) const;
		void secondCombatant(Creature* contestant[2], MagicShielding shield[2]) const;
	};
}



#endif //GAME_STATE_MANAGE_H
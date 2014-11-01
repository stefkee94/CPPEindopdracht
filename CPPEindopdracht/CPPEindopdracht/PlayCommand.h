#pragma once
#include <iostream>
#include <string>
#include "Main.h"

using namespace std;
class PlayCommand
{
public:
	PlayCommand();
	virtual ~PlayCommand();

	const int QUIT = 0, SHOWCOMMANDS = 1, INVENTORY = 2, ENEMIES = 3;
	const int USE = 0;
	const int EXITS = 0, MAP = 1, ENGAGE = 2, SKILLS = 3, CLIMB = 4;
	const int GO = 0, DROP = 1;
	const int FLEE = 0;
	const int ATTACK = 0;

	const static int MAXSINGLECOMMANDSGENERAL = 4;
	const static int MAXDOUBLECOMMANDSGENERAL = 1;

	const static int MAXSINGLECOMMANDSROOM = 5;
	const static int MAXDOUBLECOMMANDSROOM = 2;

	const static int MAXSINGLECOMMANDSCOMBAT = 1;
	const static int MAXDOUBLECOMMANDSCOMBAT = 1;
};


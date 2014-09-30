#include "Main.h"
#include "Map.h"

#include <iostream>
#include <string>

using namespace std;

Map* map;
bool playing;

const int MAXCOMMANDS = 2;
const string allCommands[MAXCOMMANDS] = { "quit", "?" };

bool checkCommand(string command)
{
	for (int i = 0; i < MAXCOMMANDS; ++i)
	{
		if (command == allCommands[i])
		{
			return true;
		}
	}

	return false;
}

void printCommands()
{
	for (int i = 0; i < MAXCOMMANDS; i++)
	{
		if (i == (MAXCOMMANDS - 1))
		{
			cout << allCommands[i] << std::endl;
		}
		else
		{
			cout << allCommands[i] + ", ";
		}
	}
}

void doCommand(string command)
{
	//if command = quit
	if (command == allCommands[0])
	{
		exit(EXIT_SUCCESS);
	}

	if (command == allCommands[1])
	{
		printCommands();
	}
}

Main::Main()
{
	map = new Map();
	playing = true;

	string command;

	cout << "Welcome to this roquelike game! Please give a command (See all the possible commands by typing '?'): " << std::endl;
	while (playing)
	{
		getline(cin, command);

		if (checkCommand(command))
		{
			doCommand(command);
		}
		else
		{
			cout << "The command you entered: '" << command << "' is invalid! Try another command: " << std::endl;
		}
	}
}

Main::~Main()
{
}

int main()
{
	Main();

	return 0;
}

#include "Main.h"
#include "Map.h"

#include <iostream>

const int MAXCOMMANDS = 2;
const string allCommands[MAXCOMMANDS] = { "quit", "?" };

bool Main::checkCommand(string command)
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

void Main::printCommands()
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

void Main::doCommand(string command)
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
	playing = false;
	string command;

	cout << "Welcome to this roquelike game! Please set the size of the map : " << endl;

	while (!playing)
	{
		cout << "Horizontal : " << endl;
		cin >> horizontal;

		cout << "Vertical : " << endl;
		cin >> vertical;

		if (horizontal >= 5 && vertical >= 5 && horizontal <= 20 && vertical <= 20)
		{
			playing = true;
		}
		else
		{
			cout << "The values are not correct, please enter new values. (minimum value = 5 and maximum value = 20)" << endl;
		}
	}
	//cout << "Horizontal : " << horizontal << endl;
	//cin >> horizontal;

	//cout << "Vertical : " << vertical << endl;
	//cin >> vertical;

	// Create new Map
	map = new Map(horizontal, vertical, floorNumber);

	while (playing)
	{
		getline(cin, command);

		if (checkCommand(command))
		{
			doCommand(command);
		}
		else
		{
			cout << "The command you entered: '" << command << "' is invalid! Try another command: " << endl;
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

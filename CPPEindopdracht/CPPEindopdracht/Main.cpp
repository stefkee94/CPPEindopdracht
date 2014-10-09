#include "Main.h"


const int MAXCOMMANDS = 7;
const string allCommands[MAXCOMMANDS] = { "exits", "go north", "go east", "go south", "go west", "quit", "?" };

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
			cout << allCommands[i] << endl;
		else
			cout << allCommands[i] + ", ";
	}
}

void Main::printExits()
{
	list<string> exits = map->getExits(hero->getXPos(), hero->getYPos());
	list<string>::iterator it;

	cout << "You can go: ";

	int i = 0;
	for (it = exits.begin(); it != exits.end(); ++it, ++i) {
		if (i == (exits.size() - 1))
			cout << *it << endl;
		else
			cout << *it + ", ";
	}
}

void Main::goTo(string exit)
{
	if (map->hasExit(hero->getXPos(), hero->getYPos(), exit))
	{
		if (exit == "north")
			hero->setYPos(hero->getYPos() - 1);
		if (exit == "east")
			hero->setXPos(hero->getXPos() + 1);
		if (exit == "south")
			hero->setYPos(hero->getYPos() + 1);
		if (exit == "west")
			hero->setXPos(hero->getXPos() - 1);

		cout << "Welcome in the room to the " + exit + " of the previous room." << endl;
		printExits();
	}
	else
	{
		cout << "There is no exit that way." << endl;
	}
}

void Main::doCommand(string command)
{
	//if command = exits
	if (command == allCommands[0])
	{
		printExits();
	}
	//if command = go north || go east || go south || go west
	if (command == allCommands[1] || command == allCommands[2] || command == allCommands[3] || command == allCommands[4])
	{
		string exit = command.substr(3);
		goTo(exit);
	}
	//if command = quit
	if (command == allCommands[5])
	{
		exit(EXIT_SUCCESS);
	}
	//if command = ?
	if (command == allCommands[6])
	{
		printCommands();
	}
}

Main::Main()
{
	playing = false;
	string command;

	cout << "Welcome to this roquelike game! Please set the size of the map : " << endl;

	//TODO catch string input
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

	// Create new random Map
	map = new Map(horizontal, vertical, floorNumber);

	std::vector<ItemType> item_types;
	// Create hero in the beginning
	hero = new Hero(std::string("The_hero"),1,100,100,1,1,10,Inventory(20, item_types));

	printExits();

	while (playing)
	{
		getline(cin, command);

		if (checkCommand(command))
		{
			doCommand(command);
		}
		else
		{
			if (command != "")
				cout << "The command you entered: '" << command << "' is invalid! Try another command (see possible commands by typing '?'): " << endl;
		}
	}
}

Main::~Main()
{
	delete map;
}

int main()
{
	Main();

	return 0;
}

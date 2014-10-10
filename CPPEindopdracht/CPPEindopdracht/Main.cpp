#include "Main.h"

const int EXITS = 0, MAP = 1, QUIT = 2, SHOWCOMMANDS = 3, INVENTORY = 4;
const int GO = 0, DROP = 1;

const int MAXSINGLECOMMANDS = 5;
const int MAXDOUBLECOMMANDS = 2;

const string singleCommands[MAXSINGLECOMMANDS] = { "exits", "map", "quit", "?", "inventory" };
const string doubleCommands[MAXDOUBLECOMMANDS] = { "go", "drop" };

bool Main::checkCommand(string command)
{
	for (int i = 0; i < MAXSINGLECOMMANDS; ++i)
	{
		if (command == singleCommands[i])
		{
			return true;
		}
	}

	for (int i = 0; i < MAXDOUBLECOMMANDS; ++i)
	{
		if (command.find(doubleCommands[i]) != string::npos) {
			return true;
		}
	}

	return false;
}

void Main::printCommands()
{
	for (int i = 0; i < MAXSINGLECOMMANDS; i++)
	{
		cout << singleCommands[i] + ", ";
	}

	for (int i = 0; i < MAXDOUBLECOMMANDS; i++)
	{
		if (i == (MAXDOUBLECOMMANDS - 1))
			cout << doubleCommands[i] << endl;
		else
			cout << doubleCommands[i] + ", ";
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

void Main::printMap()
{
	map->printMap(hero->getXPos(), hero->getYPos());
}

void Main::printInventory()
{
	hero->printInventory();
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

		map->setVisited(hero->getXPos(), hero->getYPos());

		cout << "Welcome in the room to the " + exit + " of the previous room." << endl << endl;
		if (map->hasEnemies(hero->getXPos(), hero->getYPos()))
			map->printEnemies(hero->getXPos(), hero->getYPos());

		printExits();
	}
	else
	{
		cout << "There is no exit that way." << endl;
	}
}

void Main::dropItem(string itemName)
{
	cout << hero->dropItem(itemName) << endl;
}

void Main::doCommand(string command)
{
	//if command = exits
	if (command == singleCommands[EXITS])
	{
		printExits();
	}
	//if command = map
	if (command == singleCommands[MAP])
	{
		printMap();
	}
	//if command = quit
	if (command == singleCommands[QUIT])
	{
		exit(EXIT_SUCCESS);
	}
	//if command = ?
	if (command == singleCommands[SHOWCOMMANDS])
	{
		printCommands();
	}
	//if command = inventory
	if (command == singleCommands[INVENTORY])
	{
		printInventory();
	}

	//if command contains 'go' get the exit
	if (command.find(doubleCommands[GO]) != string::npos)
	{
		string exit;

		if (command.size() > 3)
			exit = command.substr(3);
		else
			exit = "";

		goTo(exit);
	}
	//if command contains 'drop' get the item name
	if (command.find(doubleCommands[DROP]) != string::npos)
	{
		string itemName;
		if (command.size() > 5)
			itemName = command.substr(5);
		else
			itemName = "";

		dropItem(itemName);
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
	hero = new Hero();

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
	delete hero;
}

int main()
{
	Main();

	return 0;
}

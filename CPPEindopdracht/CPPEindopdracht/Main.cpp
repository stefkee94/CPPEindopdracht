#include "Main.h"

const int QUIT = 0, SHOWCOMMANDS = 1, INVENTORY = 2, ENEMIES = 3, SAVE = 4;
const int USE = 0;
const int EXITS = 0, MAP = 1, ENGAGE = 2, SKILLS = 3, REST = 4, SEARCH = 5, NOTICE = 6;
const int GO = 0, DROP = 1, CLIMB = 2, PICK = 3;
const int FLEE = 0;
const int ATTACK = 0;

const int MAXSINGLECOMMANDSGENERAL = 5;
const int MAXDOUBLECOMMANDSGENERAL = 1;

const int MAXSINGLECOMMANDSROOM = 7;
const int MAXDOUBLECOMMANDSROOM = 4;

const int MAXSINGLECOMMANDSCOMBAT = 1;
const int MAXDOUBLECOMMANDSCOMBAT = 1;

const string singleCommandsGeneral[MAXSINGLECOMMANDSGENERAL] = { "quit", "?", "inventory", "enemies", "save" };
const string doubleCommandsGeneral[MAXDOUBLECOMMANDSGENERAL] = { "use" };

const string singleCommandsRoom[MAXSINGLECOMMANDSROOM] = { "exits", "map", "engage", "skills", "rest", "search", "notice"  };
const string doubleCommandsRoom[MAXDOUBLECOMMANDSROOM] = { "go", "drop", "climb", "pick" };

const string singleCommandsCombat[MAXSINGLECOMMANDSCOMBAT] = { "flee" };
const string doubleCommandsCombat[MAXDOUBLECOMMANDSCOMBAT] = { "attack" };

bool Main::checkCommand(string command)
{
	for (int i = 0; i < MAXSINGLECOMMANDSGENERAL; ++i)
	{
		if (command == singleCommandsGeneral[i])
		{
			return true;
		}
	}

	for (int i = 0; i < MAXDOUBLECOMMANDSGENERAL; ++i)
	{
		if (command.find(doubleCommandsGeneral[i]) != string::npos) {
			return true;
		}
	}

	if (!inCombat)
	{
		for (int i = 0; i < MAXSINGLECOMMANDSROOM; ++i)
		{
			if (command == singleCommandsRoom[i])
			{
				return true;
			}
		}

		for (int i = 0; i < MAXDOUBLECOMMANDSROOM; ++i)
		{
			if (command.find(doubleCommandsRoom[i]) != string::npos) {
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < MAXSINGLECOMMANDSCOMBAT; ++i)
		{
			if (command == singleCommandsCombat[i])
			{
				return true;
			}
		}

		for (int i = 0; i < MAXDOUBLECOMMANDSCOMBAT; ++i)
		{
			if (command.find(doubleCommandsCombat[i]) != string::npos) {
				return true;
			}
		}
	}

	return false;
}

void Main::printCommands()
{
	cout << endl;

	cout << "Single commands(general):" << endl;
	for (int i = 0; i < MAXSINGLECOMMANDSGENERAL; i++)
	{
		if (i == (MAXSINGLECOMMANDSGENERAL - 1))
			cout << singleCommandsGeneral[i] << endl;
		else
			cout << singleCommandsGeneral[i] + ", ";
	}

	cout << endl << endl;

	cout << "Double commands(general): (Requires an extra command)" << endl;
	for (int i = 0; i < MAXDOUBLECOMMANDSGENERAL; i++)
	{
		if (i == (MAXDOUBLECOMMANDSGENERAL - 1))
			cout << doubleCommandsGeneral[i] << endl;
		else
			cout << doubleCommandsGeneral[i] + ", ";
	}

	if (!inCombat)
	{
		cout << endl;

		cout << "Single commands(room):" << endl;
		for (int i = 0; i < MAXSINGLECOMMANDSROOM; i++)
		{
			cout << singleCommandsRoom[i] + ", ";
		}

		cout << endl << endl;

		cout << "Double commands(room): (Requires an extra command)" << endl;
		for (int i = 0; i < MAXDOUBLECOMMANDSROOM; i++)
		{
			if (i == (MAXDOUBLECOMMANDSROOM - 1))
				cout << doubleCommandsRoom[i] << endl;
			else
				cout << doubleCommandsRoom[i] + ", ";
		}
	}
	else
	{
		cout << endl;

		cout << "Single commands(combat):" << endl;
		for (int i = 0; i < MAXSINGLECOMMANDSCOMBAT; i++)
		{
			cout << singleCommandsCombat[i] + ", ";
		}

		cout << endl << endl;

		cout << "Double commands(combat): (Requires an extra command)" << endl;
		for (int i = 0; i < MAXDOUBLECOMMANDSCOMBAT; i++)
		{
			if (i == (MAXDOUBLECOMMANDSCOMBAT - 1))
				cout << doubleCommandsCombat[i] << endl;
			else
				cout << doubleCommandsCombat[i] + ", ";
		}
	}

	cout << endl;
}

void Main::printExits()
{
	printRoomInformation();
	printEnemies();

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

	cout << endl;
}

void Main::printRoomInformation()
{
	string desc = map->chamberList[hero->getYPos()][hero->getXPos()].getDescription();
	cout << desc << endl;
}

void Main::printMap()
{
	map->printMap(hero->getXPos(), hero->getYPos());
}

void Main::printInventory()
{
	hero->printInventory();
}

void Main::printSkills()
{
	hero->printSkills();
}

void Main::printRest()
{
	int level = hero->getLevel();
	hero->addCurrentHp(level);
	std::vector<Enemy*> enemies = map->chamberList[hero->getYPos()][hero->getXPos()].getAllEnemies();

	//TODO CHANCE that enemies are attacking you if size > 0
	bool enemiesAttacking = rand() % 2 == 1;
	if (enemies.size() > 0)
	{
		if (enemiesAttacking)
		{
			for (int i = 0; i < enemies.size(); ++i)
			{
				int damage = map->enemyAttack(hero->getXPos(), hero->getYPos(), *hero, i);
				hero->Hit(damage);
			}
		}
		else
			cout << "While resting the enemies did not attack " << endl;
	}
	else
		cout << "There were no enemies to attack you while resting" << endl;
	

	if (hero->getCurrentHp() == 0)
	{
		lastBreath();
	}
}

void Main::printItem()
{
	std::vector<string> items = map->chamberList[hero->getYPos()][hero->getXPos()].getItemTypes();
	if (items.size() > 0)
	{
		cout << hero->getName() << " found something secret" << endl;

		for (int i = 0; i < items.size(); ++i)
			cout << "item " << i << ": " << items[i] << endl;

		cout << "If you wanna add this to your inventory type 'pick' <itemname>" << endl;
	}
	else
		cout << "There are no items in this room" << endl;
}

void Main::printNotice()
{
	// Trying to find some traps in a chamber
	int notice = hero->getNotice();
	if (notice < 3)
	{
		int right = rand() % 3;
		if (right == 3 || right == 2 || right == 1)
		{
			//TODO notice traps
			if (map->chamberList[hero->getYPos()][hero->getXPos()].getTrap())
			{
				map->chamberList[hero->getYPos()][hero->getXPos()].setTrap(false);
				cout << hero->getName() << " discovered a secret trap!" << endl;
			}
			else
			{
				cout << "There are no traps in this room" << endl;
			}
		}
		else
		{
			cout << hero->getName() << " is unlucky with noticing traps in this room, try again" << endl;
		}
	}
	else
	{
		int right = rand() % 2;
		if (right == 1 || right == 2)
		{
			if (map->chamberList[hero->getYPos()][hero->getXPos()].getTrap())
			{
				map->chamberList[hero->getYPos()][hero->getXPos()].setTrap(false);
			}
			else
			{
				cout << "There are no traps in this room" << endl;
			}
		}
	}
}

void Main::printEnemies()
{
	if (map->hasEnemies(hero->getXPos(), hero->getYPos()))
		map->printEnemies(hero->getXPos(), hero->getYPos());
	else
	{
		cout << endl << "There are no enemies in this room" << endl << endl;
		inCombat = false;
	}
		
}

void Main::climbStairs(string side)
{
	if (side == "up")
	{
		if (floorNumber == 2 || floorNumber == 5)
		{
			if (floorNumber == 2)
			{
				if (hero->getKilledEnemies() >= map->getAmountOfEnemiesToKill())
				{
					if (map->chamberList[hero->getYPos()][hero->getXPos()].getAmountOfEnemies() == 0)
					{
						if (map->hasStairsUp(hero->getXPos(), hero->getYPos()))
						{
							floorNumber++;
							map = new Map(Map::horizontalMapSize, Map::verticalMapSize, floorNumber);
							hero->setKilledEnemies(0);
							floors.push_back(map);
							hero->setXPos(0);
							hero->setYPos(0);

							cout << hero->getName() << " climbed the stairs up to floor " << floorNumber << endl;
						}
					}
					else
						cout << hero->getName() << " cannot move to the next floor because the boos of this floor isn't killed" << endl;
				}
				else
					cout << hero->getName() << " cannot move to the next floor because the hero killed to less enemies in this floor" << endl;
			}
		}
		else
		{
			if (hero->getKilledEnemies() >= map->getAmountOfEnemiesToKill())
			{
				if (map->hasStairsUp(hero->getXPos(), hero->getYPos()))
				{
					floorNumber++;
					map = new Map(Map::horizontalMapSize, Map::verticalMapSize, floorNumber);
					hero->setKilledEnemies(0);
					floors.push_back(map);
					hero->setXPos(0);
					hero->setYPos(0);

					cout << hero->getName() << " climbed the stairs up to floor " << floorNumber << endl;
				}
				else
				{
					cout << "There is no stairs to the next floor" << endl;
				}
			}
			else
				cout << hero->getName() << " cannot move to the next floor because the hero killed to less enemies in this floor" << endl;
		}
		
	}
	else if (side == "down")
	{
		if (map->hasStairsDown(hero->getXPos(), hero->getYPos()))
		{
			floorNumber--;
			map = floors[(floorNumber - 1)];

			// Set the hero on the "H" spot where it was the last time
			for (int y = 0; y < map->verticalMapSize; ++y)
			{
				for (int x = 0; x < map->horizontalMapSize; ++x)
				{
					if (map->chamberList[y][x].hasStairsUp())
					{
						hero->setXPos(x);
						hero->setYPos(y);
					}
				}
			}

			cout << hero->getName() << " climbed the stairs down to floor " << floorNumber << endl;
		}
		else
		{
			cout << "There is no stairs to the previous floor" << endl;
		}
	}
	else
	{
		cout << endl << "There is no side " << side << endl;
	}
}

void Main::addSkills()
{
	int skillPoints = 3;

	cout << endl << "Congratulations you just leveled up to level: " << hero->getLevel() << endl;
	cout << endl << "You have " << skillPoints << " skill points to spend" << endl;

	while (skillPoints > 0)
	{
		string input;
		cout << endl << "Type a skill to add a point to (attack, defense, notice, hp)" << endl;
		cin >> input;

		if (input == "attack")
			hero->addAttack();
		else if (input == "defense")
			hero->addDefense();
		else if (input == "notice")
			hero->addNotice();
		else if (input == "hp")
			hero->addHp();
		else
			continue;

		skillPoints--;
	}
}

void Main::goTo(string exit)
{
	if (map->chamberList[hero->getYPos()][hero->getXPos()].getTrap())
	{
		hero->setCurrentHp(hero->getCurrentHp() - 1);
		cout << "Oops, a trap has not been discovered, " << hero->getName() << " loses 1 Hp, you have now " << hero->getCurrentHp() << " from a total of " << hero->getMaxHp() << endl;

		if (hero->getCurrentHp() <= 0)
		{
			lastBreath();
		}
	}

	if (map->hasExit(hero->getXPos(), hero->getYPos(), exit))
	{
		if (exit == "north")
		{
			hero->setYPos(hero->getYPos() - 1);
			lastRoomDirection = "south";
		}
		if (exit == "east")
		{
			hero->setXPos(hero->getXPos() + 1);
			lastRoomDirection = "west";
		}
		if (exit == "south")
		{
			hero->setYPos(hero->getYPos() + 1);
			lastRoomDirection = "north";
		}
		if (exit == "west")
		{
			hero->setXPos(hero->getXPos() - 1);
			lastRoomDirection = "east";
		}

		map->setVisited(hero->getXPos(), hero->getYPos());
		// TODO beschrijving van de specifieke kamer
		setDescriptionOfRoom(hero->getXPos(), hero->getYPos());
		cout << endl << "Welcome in the room to the " + exit + " of the previous room." << endl;

		printExits();

		if (map->hasStairsDown(hero->getXPos(), hero->getYPos()))
		{
			cout << "You are able to go one floor below, if you want that type 'climb' to go one floor lower" << endl;
		}

		if (map->hasStairsUp(hero->getXPos(), hero->getYPos()))
		{
			cout << "You are able to go one floor above, if you want that type 'climb' to go one floor up" << endl;
		}
	}
	else
	{
		cout << "There is no exit that way." << endl;
	}
}

void Main::setDescriptionOfRoom(int x, int y)
{
	//string description = map->chamberList[y][x].getDescription();
}

void Main::dropItem(string itemName)
{
	cout << endl;
	cout << hero->dropItem(itemName) << endl;
	cout << endl;
}

void Main::useItem(string itemName)
{
	if (itemName == "grenade" || itemName == "bomb")
	{
		if (inCombat)
		{
			int damage = (itemName == "grenade") ? 5 : 7;
			hero->useItem(itemName);
			cout << "You pulled the pin out of the grenade and threw it to some enemies";
			cout << endl << "3....." << endl;
			Sleep(1000);
			cout << endl << "2....." << endl;
			Sleep(1000);
			cout << endl << "1....." << endl;
			Sleep(1000);
			cout << endl << "BOOOOMM" << endl;
			attackEnemyWithGrenade(damage);
		}
		else 
		{
			cout << "You have to be in combat to use your grenade, go in combat with the command : engage" << endl;
		}
	}
	else
		hero->useItem(itemName);
}

void Main::pickItem(string itemName)
{
	hero->addItem(itemName);
	// Get the item type
	ItemType item = hero->getItemType(itemName);
	if (!(item == ItemType::NOITEM))
	{
		std::vector<string> itemsLeftInRoom = map->chamberList[hero->getYPos()][hero->getXPos()].getItemTypes();
		for (std::vector<string>::iterator iter = itemsLeftInRoom.begin(); iter != itemsLeftInRoom.end(); ++iter)
		{
			if (*iter == itemName)
			{
				// Remove item which is chosen and already added
				itemsLeftInRoom.erase(iter);
				map->chamberList[hero->getYPos()][hero->getXPos()].setItemTypes(itemsLeftInRoom);
				break;
			}
		}
	}
}

void Main::engage()
{
	if (map->hasEnemies(hero->getXPos(), hero->getYPos()))
	{
		inCombat = true;
		cout << "You are now in combat" << endl;
	}
	else
		cout << "There are no enemies to engage" << endl;

	cout << endl;
}

void Main::attackEnemy(string enemyName)
{
	cout << endl;

	int x = hero->getXPos();
	int y = hero->getYPos();
	if (map->hasEnemy(x, y, enemyName))
	{
		Enemy e = map->getEnemy(x, y, enemyName);
		int damage = hero->Attack(e);

		if (damage > 0)
			cout << "You succesfully hit the enemy with " << damage << " damage" << endl;
		else
			cout << "You failed to hit the enemy" << endl;

		if (damage >= e.getCurrentHp())
		{
			hero->setKilledEnemies(1);
			if (hero->addExperience(e.getEnemyLevel()))
				addSkills();
		}

		map->hitEnemy(x, y, enemyName, damage);

		cout << endl;

		for (int i = 0; i < map->getAmountOfEnemies(x, y); ++i)
		{
			int damage = map->enemyAttack(x, y, *hero, i);
			hero->Hit(damage);
		}

		cout << endl;

		cout << "You have " << hero->getCurrentHp() << " HP left -> you have " << hero->getExp() << "/" << hero->getExpNeeded() << " experience" << endl;

		if (hero->getCurrentHp() == 0)
		{
			cout << endl;
			cout << "You are dead" << endl;
			playing = false;
		}
	}
	else
	{
		cout << "There is no enemy: " << enemyName << endl;
	}

	cout << endl;

	if (!map->hasEnemies(x, y))
	{
		inCombat = false;
	}
}

void Main::attackEnemyWithGrenade(int damage)
{
	cout << endl;

	int x = hero->getXPos();
	int y = hero->getYPos();
	if (map->hasEnemies(x, y))
	{
		vector<Enemy*> enemies_in_chamber = map->getAllEnemies(x, y);
		for (int i = 0; i < enemies_in_chamber.size(); i++)
		{
			if (damage > 0)
				cout << "You succesfully hit enemy " << enemies_in_chamber[i]->getName() << " with damage of " << damage << endl;

			if (damage >= enemies_in_chamber[i]->getCurrentHp())
			{
				hero->setKilledEnemies(1);
				if (hero->addExperience(enemies_in_chamber[i]->getEnemyLevel()))
					addSkills();
			}
			map->hitEnemy(x, y, enemies_in_chamber[i]->getName(), damage);

			if (!map->hasEnemies(x, y))
				inCombat = false;
		}
		cout << "You have " << hero->getCurrentHp() << " HP left -> you have " << hero->getExp() << "/" << hero->getExpNeeded() << " experience" << endl;
	}
}

void Main::flee()
{
	cout << endl;

	if (lastRoomDirection != "")
	{
		inCombat = false;
		cout << "You succesfully fled from the battle" << endl;
		goTo(lastRoomDirection);
	}
	else
	{
		cout << "You can't flee from this battle" << endl;
	}

	cout << endl;
}

void Main::saveFile()
{
	hero->saveHeroInfo();
	cout << hero->getName() << " saved the hero information" << endl;
}

void Main::lastBreath()
{
	hero->saveHeroInfo();
	cout << endl;
	cout << "You are dead" << endl;
	playing = false;
}

void Main::doCommand(string command)
{
	/*
	//First check the general commands
	*/
	//if command = quit
	if (command == singleCommandsGeneral[QUIT])
	{
		exit(EXIT_SUCCESS);
		return;
	}
	//if command = ?
	if (command == singleCommandsGeneral[SHOWCOMMANDS])
	{
		printCommands();
		return;
	}
	//if command = inventory
	if (command == singleCommandsGeneral[INVENTORY])
	{
		printInventory();
		return;
	}
	//if command = enemies
	if (command == singleCommandsGeneral[ENEMIES])
	{
		printEnemies();
		return;
	}

	//if command = save -> save hero info to text file
	if (command == singleCommandsGeneral[SAVE])
	{
		saveFile();
		return;
	}
	//if command contains 'use' get and use an item
	if (command.find(doubleCommandsGeneral[USE]) != string::npos)
	{
		string item;

		if (command.size() > 3)
			item = command.substr(4);
		else
			item = "";

		useItem(item);

		return;
	}

	/*
	//If not in combat check the room commands
	*/
	if (!inCombat)
	{
		//if command = exits
		if (command == singleCommandsRoom[EXITS])
		{
			printExits();
			return;
		}
		//if command = map
		if (command == singleCommandsRoom[MAP])
		{
			printMap();
			return;
		}
		//if command = engage
		if (command == singleCommandsRoom[ENGAGE])
		{
			engage();
			return;
		}
		//if command = skills
		if (command == singleCommandsRoom[SKILLS])
		{
			printSkills();
			return;
		}
		// if command = rest 
		if (command == singleCommandsRoom[REST])
		{
			printRest();
			return;
		}
		if (command == singleCommandsRoom[SEARCH])
		{
			printItem();
			return;
		}
		// if command = notice
		if (command == singleCommandsRoom[NOTICE])
		{
			printNotice();
			return;
		}
		//if command contains 'go' get the exit
		if (command.substr(0,3).find(doubleCommandsRoom[GO]) != string::npos)
		{
			string exit;

			if (command.size() > 3)
				exit = command.substr(3);
			else
				exit = "";

			goTo(exit);

			return;
		}
		//if command = climb
		if (command.find(doubleCommandsRoom[CLIMB]) != string::npos)
		{
			string side;
			if (command.size() > 6)
				side = command.substr(6);
			else
				side = "";

			climbStairs(side);
			return;
		}
		//if command contains 'drop' get the item name
		if (command.find(doubleCommandsRoom[DROP]) != string::npos)
		{
			string itemName;
			if (command.size() > 5)
				itemName = command.substr(5);
			else
				itemName = "";

			dropItem(itemName);

			return;
		}
		if (hasNoticed)
		{
			if (command.find(doubleCommandsRoom[PICK]) != string::npos)
			{
				string itemName;
				if (command.size() > 5)
					itemName = command.substr(5);
				else
					itemName = "";

				pickItem(itemName);
				return;
			}
		}
		else
			cout << "You cannot pick an object which is not found";
	}
	/*
	//Else if in combat check the combat commands
	*/
	else
	{
		//if command = flee
		if (command == singleCommandsCombat[FLEE])
		{
			flee();
			return;
		}

		//if command contains 'attack' get and attack the enemy
		if (command.find(doubleCommandsCombat[ATTACK]) != string::npos)
		{
			string enemy;

			if (command.size() > 7)
				enemy = command.substr(7);
			else
				enemy = "";

			attackEnemy(enemy);

			return;
		}
	}
}

Main::Main()
{
	playing = false;
	inCombat = false;
	lastRoomDirection = "";
	string command;

	cout << "Welcome to this roquelike game! Please set the size of the map : " << endl;

	//catch string input
	while (!playing)
	{
		cout << "Horizontal : " << endl;
		cin >> horizontal;

		while (!cin) {
			cout << "Invalid input, please enter a number" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> horizontal;
		}

		cout << "Vertical : " << endl;
		cin >> vertical;

		while (!cin) {
			cout << "Invalid input, please enter a number" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> vertical;
		}

		if (horizontal >= 5 && vertical >= 5 && horizontal <= 20 && vertical <= 20)
		{
			playing = true;
		}
		else
		{
			cout << "The values are not correct, please enter new values. (minimum value = 5 and maximum value = 20)" << endl;
		}
	}

	cout << "\n";

	while (!hero_name_set)
	{
		cout << "Before we start on this adventure, what's your name?" << endl;
		cin >> hero_name;
		if (hero_name.size() > 25)
			cout << "Name has to contain 25 chars or less" << endl;
		else
		{

			cout << "\n" << "Welcome : " << hero_name << endl << "\n";
			hero_name_set = true;
		}
	}

	while (!start_item_selected)
	{
		cout << "Choose one item to start with, you can choose the following items to add in your inventory : " << endl << "\n";
		std::vector<string> items = printAvailableItems();
		cout << "\n";
		cin >> start_item;

		for (int j = 0; j < items.size(); j++)
		{
			if (start_item == items[j])
			{
				start_item_selected = true;
				cout << "\n" << "You selected the item : " << start_item << " to start your adventure with" << endl << "\n";
			}
		}
		if (start_item_selected == false)
			cout << "\n" << "Your selected item : " << start_item << " is not known, please select a known item to start with" << endl << "\n";

	}

	// Create new random Map
	map = new Map(horizontal, vertical, floorNumber);

	floors.push_back(map);

	std::vector<ItemType> item_types;

	// Create hero in the beginning with name and one item
	hero = new Hero(hero_name, start_item);

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

	string answer;
	cout << "Would you like to play again?" << endl;
	cin >> answer;

	if (answer == "yes")
		Main();
}

std::vector<string> Main::printAvailableItems()
{
	std::vector<string> string_item_types;
	string_item_types.resize(static_cast<size_t>(ItemType::NOITEM));

	string_item_types[static_cast<size_t>(ItemType::GRENADE)] = "grenade";
	string_item_types[static_cast<size_t>(ItemType::BEER)] = "beer";
	string_item_types[static_cast<size_t>(ItemType::POTION)] = "potion";
	string_item_types[static_cast<size_t>(ItemType::SWORD)] = "sword";

	for (int i = 0; i < string_item_types.size(); i++)
		cout << string_item_types[i] << endl;

	return string_item_types;
}

Main::~Main()
{
	delete map;
	delete hero;
}

int main()
{
	//Memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(170);
	Main();
	//_CrtDumpMemoryLeaks();
	return 0;
}

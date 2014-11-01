#include "PlayCommand.h"

const string singleCommandsGeneral[PlayCommand::MAXSINGLECOMMANDSGENERAL] = { "quit", "?", "inventory", "enemies" };
const string doubleCommandsGeneral[PlayCommand::MAXDOUBLECOMMANDSGENERAL] = { "use" };

const string singleCommandsRoom[PlayCommand::MAXSINGLECOMMANDSROOM] = { "exits", "map", "engage", "skills", "climb" };
const string doubleCommandsRoom[PlayCommand::MAXDOUBLECOMMANDSROOM] = { "go", "drop" };

const string singleCommandsCombat[PlayCommand::MAXSINGLECOMMANDSCOMBAT] = { "flee" };
const string doubleCommandsCombat[PlayCommand::MAXDOUBLECOMMANDSCOMBAT] = { "attack" };

PlayCommand::PlayCommand()
{
}


PlayCommand::~PlayCommand()
{
}

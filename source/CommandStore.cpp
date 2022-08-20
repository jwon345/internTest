#include <halter/CommandStore.hpp>

using namespace Halter;
#include <excpt.h>
#include <stdio.h>

//constructor to initialise the commands
CommandStore::CommandStore() { 
	CommandStore::indexAppender = 0;
	
	//adding commands to the list
	addCommand(0, MoveAB, 1, 2);
    addCommand(1, HoldPosition);

}

void CommandStore::addCommand(uint8_t id, uint8_t commandType, float ParameterA, float ParatmerB) {
  commandList[indexAppender].id = id;
  commandList[indexAppender].commandType = commandType;
  commandList[indexAppender].inputParameterA = ParameterA;
  commandList[indexAppender].inputParameterB = ParatmerB;
  indexAppender++;
	return;
}

void CommandStore::addCommand(uint8_t id, uint8_t commandType, float ParameterA) {
  commandList[indexAppender].id = id;
  commandList[indexAppender].commandType = commandType;
  commandList[indexAppender].inputParameterA = ParameterA;
  indexAppender++;

	return;
  
}

void CommandStore::addCommand(uint8_t id, uint8_t commandType) {
  commandList[indexAppender].id = id;
  commandList[indexAppender].commandType = commandType;
  indexAppender++;
	return;
}

uint8_t CommandStore::getCommandType(command command) { 
	return command.commandType;
}


void CommandStore::runCommand(command command) {

	switch (command.commandType) { 
		case Null:
				std::cout << "something went wrong";
			break;
		case MoveAB:
				std::cout << "moving from " << command.inputParameterA << "to" << command.inputParameterB << std::endl;
            break;
		case HoldPosition:
				std::cout << "holding position at " << command.inputParameterA << std::endl;
            break;
		
	}
}


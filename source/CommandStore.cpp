#include <halter/CommandStore.hpp>

using namespace Halter;
#include <excpt.h>

//constructor to initialise the commands
CommandStore::CommandStore() { 
	CommandStore::indexAppender = 0;
	
	//adding commands to the list
	addCommand(0, MoveAToB, 1, 2);
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

uint8_t CommandStore::getCommandType(uint8_t commandIndex) { 
	return CommandStore::commandList[commandIndex].commandType;
}


void CommandStore::runCommand(uint8_t commandIndex) {

	switch (CommandStore::commandList[commandIndex].commandType) { 
		case Null:
            printf("Command is empty");
			break;
		case MoveToA:
                  printf("moving Cow to Point %f",CommandStore::commandList[commandIndex].inputParameterA );
                break;
		case MoveAToB:
                  printf("moving Cow from Point %f to point %f", CommandStore::commandList[commandIndex].inputParameterA, CommandStore::commandList[commandIndex].inputParameterB);
			            break;
		case HoldPosition:
                  printf("holding the cow position");
			break;
		case MoveToAandHoldPosition:
                   printf("moving Cow to Point %f and Holding",CommandStore::commandList[commandIndex].inputParameterA );
			break;
	
		
	}
}


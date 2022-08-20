#include <halter/CommandStore.hpp>

using namespace Halter;
#include <excpt.h>

//constructor to initialise the commands
CommandStore::CommandStore() { 
	CommandStore::indexAppender = 0;
	
	//adding commands to the list
	addCommand(MoveFromBarnToFeild1, MoveAToB, 1, 2); //(Enum CommandName, Enum CommandType, A, B)
    addCommand(Hold, HoldPosition);// without CommandName

}

void CommandStore::addCommand(uint8_t id, uint8_t commandType, float ParameterA, float ParatmerB) {
  try {
    if (indexAppender < ListSize) 
	{
		commandList[indexAppender].id = id;
		commandList[indexAppender].commandType = commandType;
		commandList[indexAppender].inputParameterA = ParameterA;
		commandList[indexAppender].inputParameterB = ParatmerB;
		indexAppender++;
		return;
	}
	else
	{
		throw indexAppender;
	}
  }	
	catch(int index) {
    printf("index too high %u", index);
  }
}

void CommandStore::addCommand(uint8_t id, uint8_t commandType, float ParameterA) {

  try {
    if (indexAppender < ListSize) 
	{
		commandList[indexAppender].id = id;
		commandList[indexAppender].commandType = commandType;
		commandList[indexAppender].inputParameterA = ParameterA;
		commandList[indexAppender].inputParameterB = NULL;
		indexAppender++;
		return;
	}
	else
	{
		throw indexAppender;
	}
  }	
	catch(int index) {
    printf("index too high %u", index);
  }

  
}

void CommandStore::addCommand(uint8_t id, uint8_t commandType) {
  try {
    if (indexAppender < ListSize) 
	{
		commandList[indexAppender].id = id;
		commandList[indexAppender].commandType = commandType;
		commandList[indexAppender].inputParameterA = NULL;
		commandList[indexAppender].inputParameterB = NULL;
		indexAppender++;
		return;
	}
	else
	{
		throw indexAppender;
	}
  }	
	catch(int index) {
    printf("index too high %u", index);
  }
}


//Getters for command componenets

uint8_t CommandStore::getCommandType(uint8_t commandIndex) { 
	return CommandStore::commandList[commandIndex].commandType;
}
uint8_t CommandStore::getCommandID(uint8_t commandIndex) { 
	return CommandStore::commandList[commandIndex].id;
}
float CommandStore::getCommandParameterA(uint8_t commandIndex) { 
	return CommandStore::commandList[commandIndex].inputParameterA;
}
float CommandStore::getCommandParameterB(uint8_t commandIndex) { 
	return CommandStore::commandList[commandIndex].inputParameterB;
}


//without real function, prinf to represent command execution
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


#pragma once
#include <iostream>
namespace Halter {
    
	#define ListSize 10     //constant for the size of the list -> try fully utilize 
	enum commandType {
		Null,MoveToA, MoveAToB, HoldPosition, MoveToAandHoldPosition  };    //define types of commands

    enum commandName {  //for convienience of naming ID of commands
        MoveToMainFarm
    };
	
    struct command {
      uint8_t id;           // 256 unique id
      uint8_t commandType;  // Enum command Type
      float inputParameterA;
      float inputParameterB;
    };
    

  class CommandStore {
		public:
    
    CommandStore();

    uint8_t getCommandType(uint8_t commandIndex); // get the command type 
    void runCommand(uint8_t commandIndex);

    //adding extra commands in other parts of the code?
    void addCommand(uint8_t id, uint8_t commandType, float ParameterA, float ParatmerB);
    void addCommand(uint8_t id, uint8_t commandType, float ParameterA);
    void addCommand(uint8_t id, uint8_t commandType);


  private:
    uint8_t indexAppender = 0;
    command commandList[ListSize];  //range predfined, needs to be manually incremented with increase of commands 	


  };

}  // namespace Halter

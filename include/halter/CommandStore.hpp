#pragma once
#include <iostream>
namespace Halter {
    
	#define ListSize 10     //constant for the size of the list -> try fully utilize 
	enum commandType {
		Null,MoveToA, MoveAToB, HoldPosition, MoveToAandHoldPosition  };    //define types of commands

    enum commandName {  //for convienience of naming ID of commands
        MoveFromBarnToFeild1, Hold, MoveToBarn, MoveToFeild
    };
	
    struct command {
        //using unsigned byte to reduce memory size
      uint8_t id;           // 256 unique id
      uint8_t commandType;  // Enum command Type
      float inputParameterA;    //using float since parameter types are unknown.
      float inputParameterB;
    };
    

  class CommandStore {
		public:
    
    //init the default commands 
    CommandStore();
    
    //get each command parameter
    uint8_t getCommandID(uint8_t commandIndex); 
    uint8_t getCommandType(uint8_t commandIndex); 
    float getCommandParameterA(uint8_t commandIndex); 
    float getCommandParameterB(uint8_t commandIndex); 

    /// <summary>
    /// Template to run the function with the corresponding Parameters stored in the command
    /// </summary>
    /// <param name="commandIndex">Indexing the Command stored == enum commandName</param>
    void runCommand(uint8_t commandIndex);

    //adding extra commands in other parts of the code?
    
    /// <summary>
    /// insert a command structure into the command list
    /// </summary>
    /// <param name="id">Haler::enum commandName</param>
    /// <param name="commandType">Halter::enum commandType</param>
    /// <param name="ParameterA">A parameter at A referece in command type </param>
    /// <param name="ParatmerB">B parameter at B reference in command Type</param>
    void addCommand(uint8_t id, uint8_t commandType, float ParameterA, float ParatmerB);

    void addCommand(uint8_t id, uint8_t commandType, float ParameterA);
    void addCommand(uint8_t id, uint8_t commandType);


  private:
    uint8_t indexAppender; //for indexing the assignment of commandList
    command commandList[ListSize];  //range predfined, needs to be manually incremented with increase of commands 	


  };

}  // namespace Halter

#pragma once
#include <iostream>

namespace Halter {
	
	enum commandType {
		Null,HoldPosition, MoveAB, MoveToA, Bound,
  };    

    enum commandName {

    };
	
    struct command {
      uint8_t id;           // 256 unique id
      uint8_t commandType;  // Enum command Type
      float inputParameterA;
      float inputParameterB;
    };

	
	void testfunction() { std::cout << "testing this";
	}

  class CommandStore {
		public:

    uint8_t getCommandType(command command); // get the command type 
    void runCommand(command command);
  private:
    uint8_t indexAppender = 0;
    command commandList[10];  //range predfined, needs to be manually incremented with increase of commands 	
			//no linked lists
		//HashMap containing -> Id(int), Type(string?), Parameter(Enum)

    void addCommand(uint8_t id, uint8_t commandType, float ParameterA, float ParatmerB);
    void addCommand(uint8_t id, uint8_t commandType, float ParameterA);
    void addCommand(uint8_t id, uint8_t commandType);



  };

}  // namespace Halter

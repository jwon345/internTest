#include <doctest/doctest.h>

#include <string>

#include "halter/CommandStore.hpp"
	
#include <iostream>

using namespace Halter;

TEST_CASE("Testing Constructed Command Parameters") {
	CommandStore CS;
    CS.runCommand(0);
    CHECK(CS.getCommandID(0) == commandName(0));
    CHECK(CS.getCommandType(0) == MoveAToB);
    CHECK(CS.getCommandParameterA(0) == 1);
    CHECK(CS.getCommandParameterB(0) == 2);
       
    CHECK(CS.getCommandID(Hold) == Hold);
    CHECK(CS.getCommandType(Hold) == HoldPosition);
    CHECK(CS.getCommandParameterA(Hold) == NULL);
    CHECK(CS.getCommandParameterB(Hold) == NULL);

} 

TEST_CASE("Testing Added commands") {
	CommandStore CS;

    CS.addCommand(MoveToBarn, MoveToA,1);
    CS.addCommand(MoveToFeild, MoveToA,2);


    CHECK(CS.getCommandID(MoveToBarn) == MoveToBarn);
    CHECK(CS.getCommandType(MoveToBarn) == MoveToA);
    CHECK(CS.getCommandParameterA(MoveToBarn) == 1);
    CHECK(CS.getCommandParameterB(MoveToBarn) == NULL);
       
    CHECK(CS.getCommandID(MoveToFeild) == MoveToFeild);
    CHECK(CS.getCommandType(MoveToFeild) == MoveToA);
    CHECK(CS.getCommandParameterA(MoveToFeild) == 2);
    CHECK(CS.getCommandParameterB(MoveToFeild) == NULL);

} 



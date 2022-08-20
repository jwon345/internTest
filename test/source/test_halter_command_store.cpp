#include <doctest/doctest.h>

#include <string>

#include "halter/CommandStore.hpp"
	
#include <iostream>

using namespace Halter;

TEST_CASE("Example test") {
	CommandStore a;
  printf("hello world");
        a.runCommand(0);
	CHECK(0 == MoveAToB);

} 

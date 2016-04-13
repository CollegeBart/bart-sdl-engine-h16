// Conteneur STL -> Standard Template Library
// Insertion rapide par l'avant ou par l'arriere.
// Random access operator
#include <vector>
#include <iostream>

#include "TestEnvironment.h"

int main(int argc, char* args[])
{
	GEngine->Init("TestEnvironment", 800, 600);

	TestEnvironment* env = new TestEnvironment();

	return GEngine->Run();
}
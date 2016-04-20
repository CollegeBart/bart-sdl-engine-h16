// Conteneur STL -> Standard Template Library
// Insertion rapide par l'avant ou par l'arriere.
// Random access operator
#include <iostream>
#include "TestEnvironment.h"

int main(int argc, char* args[])
{
	GEngine->Init("TestEnvironment", 400, 300);

	TestEnvironment* env = new TestEnvironment();

	int res = GEngine->Run();

	delete env;

	return res;
}
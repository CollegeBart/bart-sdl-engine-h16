
// Conteneur STL -> Standard Template Library
// Insertion rapide par l'avant ou par l'arriere.
// Random access operator
#include <vector>
#include <iostream>

#include "Cochon.h"
#include "Vache.h"
#include "Poule.h"

#define NUM_ANIMAL 3

#include "Engine.h"
#include "Renaud.h"
#include "TextManager.h"
#include "TestEnvironment.h"

int main(int argc, char* args[])
{
	#pragma region Engine Tests

	GEngine->Init("TestEnvironment", 800, 600);

	// Creation de nos objets de jeu.
	//Sprite* renaud = new Sprite("Images\\JeSuisRenaud.png");
	Sprite* sprite = new Sprite("Images\\JeSuisRenaud.png");
	Renaud* renaud = new Renaud();
	//TextManager* test = new TextManager();
	TestEnvironment* env = new TestEnvironment();
	
	GEngine->Run();

	delete renaud;

	#pragma endregion

	return 0;
}
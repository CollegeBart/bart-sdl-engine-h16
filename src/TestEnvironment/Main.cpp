
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
#include "TestEnvironment.h"

int main(int argc, char* args[])
{
	#pragma region Heritage
	{
		//int length;
		//std::cin >> length;
		//
		//Animal** animaux = new Animal*[length];
		//animaux[0] = new Cochon();
		//animaux[1] = new Vache();
		//animaux[2] = new Poule();
		//
		//for (int i = 0; i < NUM_ANIMAL; i++)
		//{
		//	animaux[i]->Parle();
		//}
		//
		//// Upcast
		////((Cochon*)animaux[0])->Parle();
		////static_cast<Cochon*>(animaux[0])->Parle();
		//
		//for (int i = 0; i < NUM_ANIMAL; i++)
		//{
		//	delete animaux[i];
		//}
		//delete[] animaux;
	}
	#pragma endregion

	#pragma region Vector
	{
		//// Toujours initialiser à une valeur suffisante son vector
		//std::vector<int> vI = std::vector<int>(100);
		//vI.push_back(2);
		//vI.push_back(3);
		//vI.push_back(2);
		//
		//// Copie de vector
		//std::vector<int> vI2 = std::vector<int>(vI);
		//
		//for (int i = 0; i < vI.size(); i++)
		//{
		//	
		//}
		//
		//std::vector<int>::iterator iter;
		//for (iter = vI.begin(); iter != vI.end(); iter++)
		//{
		//	std::cout << *iter << std::endl;
		//}
		//
		//// Auto
		//auto it = vI.begin();
		//for (; iter != vI.end(); iter++)
		//{
		//
		//}
		//
		//std::cout << vI.capacity();
		//vI[0];
	}
	#pragma endregion

	#pragma region Engine Tests

	GEngine->Init("TestEnvironment", 800, 600);

	// Creation de nos objets de jeu.
	//Sprite* renaud = new Sprite("Images\\JeSuisRenaud.png");
	Sprite* sprite = new Sprite("Images\\JeSuisRenaud.png");
	Renaud* renaud = new Renaud();
	TestEnvironment* env = new TestEnvironment();
	
	GEngine->Run();

	delete renaud;

	#pragma endregion

	return 0;
}
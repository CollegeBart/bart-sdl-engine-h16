#include <iostream>

#include "Cochon.h"
#include "Vache.h"
#include "Poule.h"

#define NUM_ANIMAL 3

void main()
{

	int length;
	std::cin >> length;

	Animal** animaux = new Animal*[length];
	animaux[0] = new Cochon();
	animaux[1] = new Vache();
	animaux[2] = new Poule();

	for (int i = 0; i < NUM_ANIMAL; i++)
	{
		animaux[i]->Parle();
	}

	// Upcast
	//((Cochon*)animaux[0])->Parle();
	//static_cast<Cochon*>(animaux[0])->Parle();

	for (int i = 0; i < NUM_ANIMAL; i++)
	{
		delete animaux[i];
	}
	delete[] animaux;

	system("pause");

	return;
}
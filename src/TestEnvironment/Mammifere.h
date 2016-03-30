#pragma once
#include <iostream>
#include "Animal.h"

// Public, héritage simple jamais multiple

class Mammifere: 
	public Animal
{
public:

	Mammifere();
	Mammifere(bool _isHairy, int _numLegs);
	~Mammifere();

	void Parle() { std::cout << "Son animalier" << std::endl; }

private:

	bool isHairy;
	int numLegs;

};


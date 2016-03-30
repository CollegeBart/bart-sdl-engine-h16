#include "Mammifere.h"

Mammifere::Mammifere()
	: isHairy(false)
	, numLegs(0)
{
	std::cout << "Mammifere construit par défaut" << std::endl;
}

Mammifere::Mammifere(bool _isHairy, int _numLegs)
	: isHairy(_isHairy)
	, numLegs(_numLegs)
{
	std::cout << "Mammifere construit par parametre" << std::endl;
}

Mammifere::~Mammifere()
{
	std::cout << "Mammifere Deconstruit" << std::endl;
}

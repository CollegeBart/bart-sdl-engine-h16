#include "Cochon.h"

Cochon::Cochon()
	: Mammifere(true, 4)
{

}

Cochon::Cochon(bool poilu, int nbPattes)
	:Mammifere(poilu, nbPattes)
{
}

Cochon::~Cochon()
{
}

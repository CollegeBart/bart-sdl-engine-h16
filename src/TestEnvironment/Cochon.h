#pragma once

#include "Mammifere.h"

class Cochon:
	public Mammifere
{
public:
	Cochon();
	Cochon(bool poilu, int nbPattes);
	~Cochon();

	void Parle() 
	{ 
		Mammifere::Parle();
		std::cout << "Groin Groin!" << std::endl; 
	}
};


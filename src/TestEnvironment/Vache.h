#pragma once

#include "Mammifere.h"

class Vache:
	public Mammifere
{
public:
	Vache();
	Vache(bool poilu, int nbPattes);
	~Vache();

	void Parle() 
	{
		std::cout << "Meuh Meuh!" << std::endl; 
		Mammifere::Parle();
	}

private:

};


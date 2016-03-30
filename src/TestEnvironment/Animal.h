#pragma once

#include <iostream>

class Animal
{
public:
	Animal();
	~Animal();

	virtual void Parle() { std::cout << "Bruit quelconque" << std::endl; }

private:

	int i;

};


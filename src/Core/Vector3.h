#pragma once

#include <math.h>
#include "Common.h"


struct Vector3
{
public :

	Vector3() {};//default Constructor
	//Component x, y, and z of a Point 3 Vector.
	float x;
	float y;
	float z;
	

	//Shorthand form of different Vector3. i.e Vector3::back returns a Vector3 with x == 0, y = 0, z = -1
	const static Vector3 back;
	const static Vector3 left;
	const static Vector3 down;
	const static Vector3 forward;
	const static Vector3 right;
	const static Vector3 up;
	const static Vector3 one;
	const static Vector3 zero;
	

	float length = GetLength(x, y, z);
	Vector3* normalize = Normalize(x, y, z);

	~Vector3()
	{
	}

	Vector3(float x, float y)
		: x(x)
		, y(y)
		, z(0)
	{
	};
	Vector3(float x, float y, float z)
		: x(x)
		, y(y)
		, z(z)
	{
	};

};


Vector3::Vector3() 
	:x(0)
	,y(0)
	,z(0)
{
};

float GetLength(float x, float y, float z)
{
	float result;
	result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return result;
}

Vector3* Normalize(float x, float y, float z)
{
	Vector3* v3result;
	float extent;
	extent = x + y + z;
	v3result->x = x / extent;
	v3result->y = y / extent;
	v3result->z = z / extent;
	return v3result;

}


const Vector3 Vector3::back = const Vector3(0, 0, -1); // Negative z
const Vector3 Vector3::left = const Vector3(-1, 0, 0); // Negative x
const Vector3 Vector3::down = const Vector3(0, -1, 0); // Negative y
const Vector3 Vector3::forward = const Vector3(0, 0, 1); // Positive z
const Vector3 Vector3::right = const Vector3(1, 0, 0); // Positive x
const Vector3 Vector3::up = const Vector3(0, 1, 0); // Positive y
const Vector3 Vector3::one = const Vector3(1, 1, 1); // Unit Vector3
const Vector3 Vector3::zero = const Vector3(0, 0, 0); // Vector3 set to Zero

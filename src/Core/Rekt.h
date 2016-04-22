#pragma once

#include "SDL.h"

struct Rekt
{
	Rekt() 
	{
		std::cout << "New Rekt" << std::endl;
		this->x = 0.f;
		this->y = 0.f;
		this->w = 0.f;
		this->h = 0.f;
	}

	Rekt(float x, float y, float w, float h)
	{
		std::cout << "New Rekt" << std::endl;
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	Rekt(SDL_Rect* rect)
	{
		std::cout << "New Rekt" << std::endl;
		this->x = rect->x;
		this->y = rect->y;
		this->w = rect->w;
		this->h = rect->h;
	}

	~Rekt()
	{
		std::cout << "Delete Rekt" << std::endl;
	}

	class {
		float value;
	public:
		float & operator = (const float &i) { return value = i; }
		float & operator += (const float &i) { value += i; return value; }
		operator float() const { return value; }
	} x;

	class {
		float value;
	public:
		float & operator = (const float &f) { return value = f; }
		float & operator += (const float &i) { value += i; return value; }
		operator float() const { return value; }
	} y;

	class {
		float value;
	public:
		float & operator = (const float &f) { return value = f; }
		float & operator += (const float &i) { value += i; return value; }
		operator float() const { return value; }
	} w;

	class {
		float value;
	public:
		float & operator = (const float &f) { return value = f; }
		float & operator += (const float &i) { value += i; return value; }
		operator float() const { return value; }
	} h;

	SDL_Rect GetRect() 
	{
		SDL_Rect r;

		r.x = this->x;
		r.y = this->y;
		r.w = this->w;
		r.h = this->h;

		return r;
	}
};


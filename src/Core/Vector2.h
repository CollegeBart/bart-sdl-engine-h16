#pragma once

template < class T >
struct Vector2
{
	Vector2()
		: x(0), y(0) { }

	Vector2(T x, T y)
		: x(x), y(y) { }

	T x, y;

};

template <class T>
Vector2<T> Add(Vector2<T> left, Vector2<T> right)
{
	Vector2<T> result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}

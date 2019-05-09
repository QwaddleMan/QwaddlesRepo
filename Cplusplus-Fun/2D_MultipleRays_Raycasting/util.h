#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Boundry.h"
#include <cmath>


using namespace sf;

#ifndef _util
#define _util


float mag(Vector2f vec)
{
	return sqrt(pow(vec.x,2) + pow(vec.y,2));
}

Vector2f normalize(Vector2f vec)
{
	Vector2f temp = vec;
	float magnitude = mag(vec);

	if(magnitude > 0)
		temp /= magnitude;

	return temp;
}

Vector2f deg2vec(float deg)
{
	Vector2f ret;

	ret.x = 1 * cos(deg);
	ret.y = 1 * sin(deg);
	return ret;
}

#endif
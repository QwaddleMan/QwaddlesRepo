#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Boundry.h"
#include "util.h"


using namespace sf;

class Ray{

public:
	Ray(float x, float y);
	Ray(Vector2f pos, float angle);
	Line getRayLine();
	Vector2f cast(Boundry wall);
	void update();
	void lookAt(float x, float y);
	void setPosition(float x, float y);
public:
	Vector2f pos;
	Vector2f dir;
private:
	Line * rayLine;

};




Ray::Ray(float x, float y)
{
	pos.x  = x;
	pos.y = y;
	dir.x = 1;
	dir.y = 0;
	rayLine = new Line(pos.x, pos.y, pos.x + dir.x * 10, pos.y + dir.y * 10);

}

Ray::Ray(Vector2f pos, float angle)
{
	this->pos = pos;
	this->dir = deg2vec(angle);
	rayLine = new Line(pos.x, pos.y, pos.x + dir.x * 10, pos.y + dir.y * 10);
}

void Ray::setPosition(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Ray::lookAt(float x, float y)
{
	dir.x = x-pos.x;
	dir.y = y-pos.y;
	dir = normalize(dir);

}

Line Ray::getRayLine()
{
	return *rayLine;
}

void Ray::update()
{
	
	rayLine = new Line(pos.x, pos.y, pos.x + dir.x * 10, pos.y + dir.y * 10);
}

Vector2f Ray::cast(Boundry wall)
{
	

	const float x1 = wall.x1;
	const float y1 = wall.y1;
	const float x2 = wall.x2;
	const float y2 = wall.y2;

	const float x3 = pos.x;
	const float y3 = pos.y;
	const float x4 = pos.x + dir.x;
	const float y4 = pos.y + dir.y;

	const float den = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);

	if(den == 0)
		return Vector2f(-1,-1);


	const float t = ((x1-x3)*(y3-y4)-(y1-y3)*(x3-x4))/den;
	const float u = -((x1-x2)*(y1-y3)-(y1-y2)*(x1-x3))/den;

	if(t > 0 && t < 1 && u > 0)
	{
		Vector2f pt;
		pt.x = x1 + t * (x2 - x1);
		pt.y = y1 + t * (y2 - y1);
		return pt;
	}
	else
	{
		return Vector2f(-1,-1);
	}
}



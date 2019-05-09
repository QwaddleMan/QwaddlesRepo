#include <SFML/Graphics.hpp>
#include "Ray.h"
#include <vector>

using namespace sf;

#ifndef _Particle_h
#define _Particle_h

class Particle{
public:
	Particle(float x, float y);
	void show(RenderWindow & window);

public:
	Vector2f pos;
	std::vector<Ray> rays;
private:
	CircleShape part;

};

Particle::Particle(float x, float y)
{
	pos.x = x;
	pos.y = y;

	for(int i = 0; i < 360; i += 10)
	{
		rays.push_back(Ray(pos, i));
	}

	part = CircleShape(10);
	part.setPosition(pos);
	part.setFillColor(Color::Blue);
}


void Particle::show(RenderWindow & window)
{
	window.draw(part);

	for(int i = 0; i < rays.size(); i++)
	{
		rays[i].getRayLine().draw(window);
	}
}


#endif

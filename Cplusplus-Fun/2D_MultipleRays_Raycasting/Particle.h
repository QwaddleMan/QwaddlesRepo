#include <SFML/Graphics.hpp>
#include "Ray.h"
#include "Line.h"
#include "Boundry.h"
#include <vector>

using namespace sf;

#ifndef _Particle_h
#define _Particle_h


class Particle{
public:
	Particle(float x, float y);
	void setPosition(float x, float y);
	void update();
	void show(RenderWindow & window);
	void look(Boundry wall);
	void look(std::vector<Boundry> walls);

public:
	Vector2f pos;
	std::vector<Ray> rays;
	CircleShape part;

private:
	

};

Particle::Particle(float x, float y)
{
	pos.x = x;
	pos.y = y;

	Vector2f temp = pos;
	temp.x += 10;
	temp.y += 10;

	for(int i = 0; i < 360; i += 1)
	{

		rays.push_back(Ray(temp,i));
	}

	part = CircleShape(10);
	part.setPosition(pos);
	part.setFillColor(Color::Blue);
}

void Particle::update()
{
	part.setPosition(pos);
	for(unsigned long i = 0; i < rays.size(); i++)
	{
		rays[i].setPosition(pos.x+10, pos.y+10);
		rays[i].update();
	}

}

void Particle::look(Boundry wall)
{
	Vector2f temp;

	for (unsigned long i = 0; i < rays.size(); i++)
	{
		rays[i].lines.clear();
		temp = rays[i].cast(wall);
		if(temp != Vector2f(-1,-1))
		{
			rays[i].lines.push_back(Line(pos.x + 10, pos.y + 10, temp.x, temp.y));
		}
	}

}

void Particle::look(std::vector<Boundry> walls)
{
	Vector2f temp;

	for (unsigned long i = 0; i < rays.size(); i++)
	{
		rays[i].lines.clear();
		for(unsigned long j = 0; j < walls.size(); j++)
		{
			temp = rays[i].cast(walls[j]);
			if(temp != Vector2f(-1,-1))
			{
				rays[i].lines.push_back(Line(pos.x + 10, pos.y + 10, temp.x, temp.y));
			}
		}
	}

}



void Particle::setPosition(float x, float y)
{
	pos.x = x;
	pos.y = y;
}



void Particle::show(RenderWindow & window)
{
	window.draw(part);

	for(unsigned long i = 0; i < rays.size(); i++)
	{
		rays[i].getRayLine().draw(window);


		for(unsigned long j = 0; j < rays[i].lines.size(); j++)
		{
			rays[i].getShortest().draw(window);
		}
	}


}


#endif

#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

class Line {

public:
	Line(float x1,float y1,float x2,float y2);
	void update();
	void draw(RenderWindow & window);
	float length();
public:
	float x1,x2,y1,y2;
	VertexArray lines;

    
private:
};

Line::Line(float x1,float y1,float x2,float y2)
{
	lines = VertexArray(sf::LinesStrip, 2);
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;

	lines[0].position = sf::Vector2f(x1, y1);
    lines[1].position = sf::Vector2f(x2, y2);
}

void Line::update()
{
	lines[0].position = sf::Vector2f(x1, y1);
    lines[1].position = sf::Vector2f(x2, y2);
}

float Line::length()
{
	return sqrt(pow(x2-x1,2) + pow(y2 - y1,2));
}

void Line::draw(RenderWindow & window)
{

	window.draw(lines);
}



/*
 @author Jason
 @Description:
 	this class controls the goal that the 'characters' need to get to.
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace sf;

class Goal{
public:
	Goal();
	static int randomNumber(int low, int high);
	void newGoal();
	CircleShape getShape();
	void draw(RenderWindow & window);
	void setRed(bool isRed);
	bool getRed();
private:
	bool isRed; //is the goal in existance
	CircleShape * shape; //the goal that the spectator will see
	int x,y;//current location
};

//Constructor
Goal::Goal()
{
	shape = new CircleShape(50.f);
	shape->setFillColor(Color::Red);
	shape->setOrigin(50.f,50.f);
	x = randomNumber(0,800);
	y = randomNumber(0,800);
	shape->setPosition(x,y);
	isRed = true;
}

//getter for shape
CircleShape Goal::getShape()
{
	return *shape;
}

//getter for isRed which basically means if the goal is in existance
// at the current moment
bool Goal::getRed()
{
	return isRed;
}

//sets isRed
void Goal::setRed(bool isRed)
{
	this->isRed = isRed;
}

//random number wrapper
int Goal::randomNumber(int low, int high)
{
	int n = rand()%high + low;
	return n;
}

//creats a 'new' goal. which is actually just moving the current goals Position
//originally i made it destroy it then make a new goal entirly, but soon realized
// that was a bad idea
void Goal::newGoal()
{
	x = randomNumber(0,800);
	y = randomNumber(0,800);
	shape->setPosition(x,y);
	isRed = true;
}

//draws the shap to the screen
void Goal::draw(RenderWindow & window)
{
	window.draw(*shape);
}

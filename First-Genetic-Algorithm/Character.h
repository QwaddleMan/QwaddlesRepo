#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Goal.h"
#include "Fitness.h"
#include <cmath>

using namespace sf;

class Character{
public:
	Character();
	void movement(Time passed, Clock & time); //manual movement
	bool collisionDet(CircleShape goal);
	void onCollision(Goal * goal, Clock & time);
	void decrementScore();
	void screenWrap();

	Fitness getFitness();
	void setFitness(Goal * goal);
	void initializeFitness();
	void killFit();

	void lockControls();
	int getScore();
	CircleShape getShape();
	void resetScore();
	void setShapePosition(int x, int y);
	void draw(RenderWindow & window);
	bool isGoalLeft(Goal * goal);
	bool isGoalUp(Goal * goal);
	void goLeft(bool left);//decided movement
	void goUp(bool up);//decided movement
private:
	float xVel = 0, yVel = 0;
	float acc = .5f;
	CircleShape * shape;
	int score;
	bool ctrLock = false;
	Fitness * tempFit;
};



Character::Character()
{
	shape = new CircleShape(30.f);
	shape->setOrigin(30.f,30.f);
	shape->setFillColor(Color::Green);
	score = 0;
}

void Character::setShapePosition(int x, int y)
{
	shape->setPosition(x,y);
}

CircleShape Character::getShape()
{
	return *shape;
}

void Character::resetScore()
{
	score = 0;
}

void Character::lockControls()
{
	ctrLock = true;
}

int Character::getScore()
{
	return score;
}

void Character::decrementScore()
{
	score--;
}

bool Character::isGoalLeft(Goal * goal)
{
	CircleShape g = goal->getShape();
	if(shape->getPosition().x > g.getPosition().x)
		return true;
	else
		return false;
}
bool Character::isGoalUp(Goal * goal)
{
	CircleShape g = goal->getShape();
	if(shape->getPosition().y > g.getPosition().y)
		return true;
	else
		return false;
}

void Character::onCollision(Goal * goal, Clock & time)
{
	CircleShape g = goal->getShape();
	if(collisionDet(g))
	{
		goal->setRed(false);
		score++;
		time.restart();
		shape->setPosition(400,400);
	}
}

bool Character::collisionDet(CircleShape goal)
{
	Vector2f myPosition = shape->getPosition();
	Vector2f goalPosition= goal.getPosition();

	float radius = 50.f;

	if(myPosition.x > goalPosition.x-radius && myPosition.x < goalPosition.x + radius && myPosition.y > goalPosition.y-radius && myPosition.y < goalPosition.y +radius)
	{
		return true;
	}
	else
		return false;
}

void Character::movement(Time passed,Clock & time)
{
	float maxVel = 300.f;
	float minVel = -300.f;

	if(!ctrLock)
	{
		if(Keyboard::isKeyPressed(Keyboard::Left) && xVel > minVel)
		{
			xVel -= acc;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Right) && xVel < maxVel)
		{
			xVel += acc;
		}
		else
		{
			xVel = 0;
		}

		if(Keyboard::isKeyPressed(Keyboard::Up) && yVel > minVel)
		{
			yVel -= acc;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Down) && yVel < maxVel)
		{
			yVel += acc;
		}
		else
		{
			yVel = 0;
		}


		if(shape->getPosition().x < 0)
		{
			shape->setPosition(800,shape->getPosition().y);
		}
		if(shape->getPosition().x > 800)
		{
			shape->setPosition(0,shape->getPosition().y);
		}
		if(shape->getPosition().y < 0)
		{
			shape->setPosition(shape->getPosition().x,800);
		}
		if(shape->getPosition().y > 800)
		{
			shape->setPosition(shape->getPosition().x,0);
		}

		shape->move(xVel * passed.asSeconds(), yVel * passed.asSeconds());
	}
	else
	{
		if(Keyboard::isKeyPressed(Keyboard::R))
		{
			score = 0;
			ctrLock = false;
			time.restart();
		}
	}


}

void Character::draw(RenderWindow & window)
{
	window.draw(*shape);
}

void Character::screenWrap()
{
		if(shape->getPosition().x < 0)
		{
			shape->setPosition(800,shape->getPosition().y);
		}
		if(shape->getPosition().x > 800)
		{
			shape->setPosition(0,shape->getPosition().y);
		}
		if(shape->getPosition().y < 0)
		{
			shape->setPosition(shape->getPosition().x,800);
		}
		if(shape->getPosition().y > 800)
		{
			shape->setPosition(shape->getPosition().x,0);
		}
}

//controlled by genes
void Character::goLeft(bool left)
{
	if(left)
	{
		shape->move(-1,0);
	}
	else
	{
		shape->move(1,0);
	}


}

void Character::goUp(bool up)
{
	if(up)
	{
		shape->move(0,-1);
	}
	else
	{
		shape->move(0,1);
	}
}

Fitness Character::getFitness()
{
	return *tempFit;
}

void Character::initializeFitness()
{
	tempFit = new Fitness;
	tempFit->score = 0;
	tempFit->closestDistance = 1000000000.f;
}

void Character::setFitness(Goal * goal)
{
	CircleShape temp = goal->getShape();
	Vector2f goalPos = temp.getPosition();
	Vector2f charPos = shape->getPosition();
	float distance = sqrt( pow(goalPos.x - charPos.x,2) + pow(goalPos.y-charPos.y,2));


	if(distance < tempFit->closestDistance)
	{
		tempFit->closestDistance = distance;
		//printf("closest distance to goal so far is: %f\n",tempFit->closestDistance);
	}
	if(score > tempFit->score)
		tempFit->score = score;
	if(score == 5)
		tempFit->winLose = true;
	if(score == -5)
		tempFit->winLose = false;
}

void Character::killFit()
{
	delete tempFit;
}

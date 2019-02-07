#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Character.h"
#include "Goal.h"
#include "population.h"
#include <iostream>
using namespace sf;

void scoreUpdate(Text & text, Character * p, Population & pop, int & iter);

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(800,800),"Genetic Algorithm Project");

	//playerhape
	Character * green = new Character();
	//red balls
	Goal * red = new Goal();

	int gen = 0;
	//TIME
	Time passed;
	Time left;
	Clock Timer;
	Clock pTimer;
	Time toGetToGoal;
	toGetToGoal = seconds(5);
	left = pTimer.restart();
	//SCORE TEXT
	Font font;
	if(!font.loadFromFile("arial.ttf"))
	{
		printf("error loading font\n");
	}
	Text text("sup",font,50);
	text.move(400,100);

	green->setShapePosition(400,400);
	green->initializeFitness();

	int iter = 0;
	bool done = false;
	Population p(4);
	p.initialize();

	while(window.isOpen())
	{

		passed = Timer.restart();
		Event event;
		while(window.pollEvent(event))
		{

			if(event.type == Event::Closed)
			{
				window.close();
			}

			if(done && Keyboard::isKeyPressed(Keyboard::Space))
			{
				printf("space hit...\n");
				p.addGenesToFitness();
				p.sortFitest();
				p.sortFitest();
				printf("displaying fitness...\n");
				p.displayFitness();
				printf("next generation...\n");
				p = p.nextGen();
			//	p.displayGenes();
				iter = 0;
				gen++;
				done = false;
			}

		}

		if(!done)
		{
			//this shit
			scoreUpdate(text,green, p, iter);
			green->setFitness(red);


			if(!red->getRed())
				red->newGoal();

			green->onCollision(red, pTimer);
			p.makeDisicion(iter,green,green->isGoalLeft(red), green->isGoalUp(red));
			green->screenWrap();
			//to this shit
			//lower score if you dont make it to goal in under 20 seconds
			left = pTimer.getElapsedTime();
			//printf("%i\n",left.asSeconds());
			if(left >= toGetToGoal)
			{
				//printf("left reset...\n");
				green->decrementScore();
				pTimer.restart();
			}
		}
		//printf("iter: %i\n",iter);
	//	printf("iter is %i\n", iter);
		if(iter > p.getSize()-2)
		{
			done = true;
		}




		//green->movement(passed, pTimer);

		    window.clear();
			green->draw(window);

			if(red->getRed())
				red->draw(window);
			window.draw(text);
			window.display();
	}
	return 0;
}

void scoreUpdate(Text & text, Character * p, Population & pop, int & iter)
{
	std::string message;
	if(p->getScore() == -5)
	{
		message = "You Lose :(";
		iter++;
		printf("iter is : %i\n", iter);
		p->resetScore();
		p->setShapePosition(400,400);
		pop.setGeneFitness(p->getFitness());
		p->killFit();
		p->initializeFitness();
		//p->lockControls();
	}
	else if(p->getScore() == 5)
	{
		message = "You Win :)";
		iter++;
		printf("iter is : %i\n", iter);
		p->resetScore();
		p->setShapePosition(400,400);
		pop.setGeneFitness(p->getFitness());
		p->killFit();
		p->initializeFitness();
		//p->lockControls();
	}
	else
	{
		message = "Score: " + std::to_string(p->getScore());

	}

	text.setString(message);
}

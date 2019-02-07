/*
@author Jason
@description:
	This class controls the population.
 */

#pragma once
#include <vector>
#include "Goal.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Fitness.h"

using namespace std;

class Population{

public:
	Population(int size);
	void initialize();
	void initialize(Population & ret, std::vector<double> pa, std::vector<double> pb);
	void displayGenes();
	int getSize();
	void makeDisicion(int iteration, Character * p, bool left, bool up);
	void sortFitest();
	void addGenesToFitness();
	void addGenesToPopulaton(std::vector<double> d);
	std::vector<double> grabGene(int i);

	void setGeneFitness(Fitness fit);
	void displayFitness();

	Population nextGen();
	void determinMutation(int chance);

private:
	vector< vector<double> > pop;
	int size;
	std::vector<Fitness> popFitness;

};

//constructor
Population::Population(int size)
{
	this->size = size;
}

//returns the size of the population
int Population::getSize()
{
	return size;
}

//genes are a probability of going up down left or right given
//the goal is to the righ,left,up, or down of the character
//and is specifically in the order left, right, up, down
void Population::initialize()
{

	vector<double> * genes;
	double probability;
	for(int i = 0; i < size; i++)
	{
		genes = new vector<double>();
		for(int j = 0; j < 4; j++)
		{
			probability = (double)rand()/(double)RAND_MAX;
			genes->push_back(probability);
		}
		this->pop.push_back(*genes);
		delete genes;
	}
	displayGenes();

	printf("\n\n\n");
}

//displays all the genes of the population
void Population::displayGenes()
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%f, ",pop[i][j]);
		}
		printf("\n");
	}
}

//adds genes to Population
// takes a vector d
void Population::addGenesToPopulaton(std::vector<double> d)
{
	pop.push_back(d);
}

//this method tells the character which direction to go based
//on its genes and the location of the goal
void Population::makeDisicion(int iteration, Character * p, bool left, bool up)
{
	int randNum = rand() % 100;

	//printf("random number is %i\n",randNum);
	if(left)
	{
		if(randNum <= 100 * pop[iteration][0])
		{
			//printf("go left!\n");
			p->goLeft(true);//red->setRed(false);
		}
		else
		{
			//printf("go right!\n");
			p->goLeft(false);
		}
	}

	if(!left)
	{
		if(randNum <= 100 * pop[iteration][1])
		{
			//printf("go right!\n");
			p->goLeft(false);
		}
		else
		{
			//printf("go left!\n");
			p->goLeft(true);
		}
	}

	if(up)
	{
		if(randNum <= 100 * pop[iteration][2])
		{
			//printf("go up!\n");
			p->goUp(true);
		}
		else
		{
			//printf("go down!\n");
			p->goUp(false);
		}
	}

	if(!up)
	{
		if(randNum <= 100 * pop[iteration][3])
		{
			//printf("go down!\n");
			p->goUp(false);
		}
		else
		{
			//printf("go up!\n");
			p->goUp(true);
		}
	}


}

//sets fitness of a character then pushes it onto the
//fitness vector
void Population::setGeneFitness(Fitness fit)
{
	popFitness.push_back(fit);
}

//display the fitnesses of the population
void Population::displayFitness()
{
	printf("fitness is : \n");
	for(unsigned int i = 0; i < popFitness.size(); i++)
	{
		printf("closest distance: %f \n highest score: %i \n win: %d\n################\n\n",popFitness[i].closestDistance, popFitness[i].score,popFitness[i].winLose);
	}
}
//add the genes from the population to the fitness.
//should have done this from the begining but ive messed up
void Population::addGenesToFitness()
{
	printf("bug in here?\n");
	//adding genes to the fitness because I didnt think of it earlier and now im kicking myself
	for(unsigned int i = 0; i < pop.size(); i++)
	{

		for(unsigned int j = 0; j < pop[i].size(); j++)
		{
			printf("oh god how deep does this go...\n");
			popFitness[i].genes.push_back(pop[i][j]);
		}
	//	printf("%u \n",popFitness[i].genes.size());
	}
}

//sort fitness
//todo: use better sorting algorithm (bubble is trash)
void Population::sortFitest()
{
	unsigned int i;
	unsigned int j;
	Fitness temp;



	printf("is the \n");
	//sort
	for(i = 0; i < popFitness.size()-1; i++)
	{
		for(j = 0; j < popFitness.size()- i - 1; j++)
		{
			if(popFitness[j].score < popFitness[j+1].score/* fit could be the quickest duration to get the goal*/)
			{
				temp = popFitness[j];
				popFitness[j] = popFitness[j+1];
				popFitness[j+1] = temp;
			}
		}
	}
	printf("or somewhere else???\n");


}

//create a new generation from this population
Population Population::nextGen()
{
	//parents of the new population
	std::vector<double> parentA;
	std::vector<double> parentB;


	Population newP(size); // the new population
	printf("new population created\n");

	//get the top genes from this population and give it to the parents
	parentA = grabGene(0);
	parentB = grabGene(1);
	printf("parents made\n");

	//make new population
	printf("attempting to initialize...\n");
	initialize(newP, parentA,parentB);
	printf("success!\n");
	//newP.initialize();

	printf("the new genes are: \n");
	newP.displayGenes();
	//mutaion
	newP.determinMutation(5);

	//return population
	return newP;
}

//initialize the population... adding genes to the population of size
void Population::initialize(Population & ret, std::vector<double> pa, std::vector<double> pb)
{
	int random;
	std::vector<double> * newGene;

	printf("ret population size is %i\n",ret.getSize());
	for(int j = 0; j < ret.getSize(); j++)
	{

		newGene = new std::vector<double>();
		printf("on person: %i\n",j);
		for(int i = 0; i<4; i++)
		{
			printf("boop\n");
			random = 1 + rand() % 2;
			printf("random number is %i\n", random );
			if(random == 1)
			{
				printf("pushing %f to newGene\n", pa[i]);
				newGene->push_back(pa[i]);
			}
			if(random == 2)
				newGene->push_back(pb[i]);
		}
		printf("attempting to add genes to population\n");
		ret.addGenesToPopulaton(*newGene);
		printf("Success!!\n");
	}

	printf("population initialized...\n");

}

//gives a chance for mutation (small percentage)
void Population::determinMutation(int chance)
{
		int r;
	  double mutation;

		for(unsigned int i = 0; i < pop.size(); i++)
		{
			for(unsigned int j = 0; j < pop[i].size(); j++)
			{
				r = 1 + rand()%100;
			  printf("r is :%i\n", r);
				if(r <= chance)
				{
					printf("!!!MUTATION!!!\n");
					mutation = (double)rand()/(double)RAND_MAX;
					printf("%f\n", mutation);
					printf("!!!MUTATION!!!\n");
					pop[i][j] = mutation;
				}
			}
		}
}


//I do not think that I use this so ill probably get rid of it later

std::vector<double> Population::grabGene(int i)
{
	std::vector<double> temp;
	printf("pop at 0 1 is %f\n",pop[0][1]);
	temp = popFitness[i].genes;
	// for(unsigned int j = 0;j< popFitness[i].genes.size(); j++)  //smarter not harder lolololol
	// {
	// 	printf("currently pushing %f\n",popFitness[i].genes[j]);
	// 	temp.push_back(popFitness[i].genes[j]);
	// }

	printf("gene grabed\n");

	printf("gene is : \n");
	for(unsigned int j = 0; j < temp.size(); j++)
	{
		printf("%f, \n", temp[j]);
	}
	printf("\n");
	return temp;
}

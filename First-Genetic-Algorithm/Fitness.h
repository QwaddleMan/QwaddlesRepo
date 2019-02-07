#pragma once

using namespace std;

struct Fitness
{
	int score; //score the 'Character' got
	float closestDistance; // this will not be used. I originally was using distance to determin the greater fitness but I am going to use time to get to the goal instead
	bool winLose; // did the 'Character' win or lose the game
	vector<double> genes; //the 'Characters' genes
};

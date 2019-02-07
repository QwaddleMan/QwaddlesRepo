/**
 * @author Jason Bowerman
 * Space Knight is a sub object of gameObj. The space knight will be
 * a mainly attacking class and will aim to be more tanky than the rest of the
 * classes.
 */
#pragma once
#include "gameObj.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SpaceKnight : public gameObj {
public:
  SpaceKnight(string name, gameObj & c);
  void printObj();
  void Options(vector<gameObj *> opponent);
};



/**
 * display the options for SpaceKnight
 * @param opponent is the opposing team. Using this so I can let the user choose
 * who to attack. We do not want them to be able to attack their friendlies.
 */
void SpaceKnight::Options(vector<gameObj *> opponent) {
	int option, victom;
	cout << "Here are the options for " << this->getName() << ": \n"
		<< "(1) Lunge\n(2) Buff\n(3) Skip\nWhat is your choice: ";
	cin >> option;
	while (option < 1 || option >3 || cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "invalid option, try again: ";
		cin >> option;
	}
	cout << endl << endl;


	if (option == 1) {
		cout << "You chose to lunge.\n";
		for (int i = 0; i < opponent.size(); i++) {
			cout << i + 1 << " - ";
			opponent[i]->printObj();
		}
		cout << "Who would you like to attack?: ";
		cin >> victom;
		while (victom < 1 || victom > opponent.size() + 1 || cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "invalid victon, try again: ";
			cin >> victom;
		}
		this->Attack(opponent[victom - 1]);
	}
	if (option == 2)
	{
		this->setHealth(this->getHealth() + 2);
		cout << getName() << "'s health has increased by 2\n\n";
	}
	if (option == 3)
	{
		cout << "skipping...\n\n";
	}
}

/**
 * Constructor
 * @param name is the name of the Space Knight
 * @param c is the commander of the spaceknight
 */
SpaceKnight::SpaceKnight(string name, gameObj & c) : gameObj(name) {
  this->setAttack(40);
  this->setHealth(40);
  this->setNextLevel(100);
  this->setCommander(c);
}
/**
 * simply prints out the Space Knight's information
 */
void SpaceKnight::printObj() {
	if (isAlive())
	{
		cout << "Knight " << this->getName() << " H-" << this->getHealth() << " A-"
			<< this->getAttack() << " lvl-" << this->getLevel() << endl;
	}
	else
	{
		cout << "Knight " << this->getName() << " H-" << this->getHealth() << " A-"
			<< this->getAttack() << " lvl-" << this->getLevel() <<" *DEAD*"<< endl;
	}
}

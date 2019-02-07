/**
 * @author Jason Bowerman
 * Space Medic is the medic class and will have the option to heal all the
 * friendlies or just itself. The Space Medic will have a average health and
 * attack.
 */
#pragma once
#include "gameObj.h"
#include <iostream>
#include <string>

using namespace std;

class SpaceMedic : public gameObj {
public:
  SpaceMedic(string name,gameObj & command);
  void printObj();
  void Options(vector<gameObj *> opponent);
};
/**
 * Constructor
 * @param name is the name of the Space Medic
 * @param command is the commander of the space medic
 */
SpaceMedic::SpaceMedic(string name, gameObj & command) : gameObj(name) {
  this->setAttack(10);
  this->setHealth(60);
  this->setNextLevel(100);
  this->setCommander(command);
}
/**
 * simply print the Space Medic's information
 */
void SpaceMedic::printObj() {
	if (isAlive())
	{
		cout << "Medic " << this->getName() << " H-" << this->getHealth() << " A-"
			<< this->getAttack() << " lvl-" << this->getLevel() << endl;
	}
	else
	{
		cout << "Medic " << this->getName() << " H-" << this->getHealth() << " A-"
			<< this->getAttack() << " lvl-" << this->getLevel() <<" *DEAD*"<< endl;
	}

}
/**
 * Options for space medic
 * @param opponent is the vector of opponents
 */
void SpaceMedic::Options(vector<gameObj *> opponent)
{
	int option, victom;
	cout << "Here are the options for " << this->getName() << ": \n"
		<< "(1) Attack\n(2) Heal Friends\n(3) Heal Self Only\n(4) Skip\nWhat is your choice: ";
	cin >> option;
	while (option < 1 || option >4 || cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "invalid option, try again: ";
		cin >> option;
	}
	cout << endl << endl;
	if (option == 1)
	{
		cout << "You chose to Attack.\n";
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
}

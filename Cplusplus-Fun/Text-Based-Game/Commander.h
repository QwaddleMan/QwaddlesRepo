/**
 * @author Jason Bowerman
 * The commander is the leader of the teams.
 */
#pragma once
#include "gameObj.h"
#include <iostream>
#include <string>

using namespace std;

class Commander : public gameObj {
public:
  Commander(string name) : gameObj(name) {}
  Commander();
  void printObj();
};

/**
 * Constructor
 */
Commander::Commander() {
  this->setHealth(1000);
  this->setName("Commander " + this->getName());
}
/**
 * prints the commanders information
 */
void Commander::printObj() {
  cout << this->getName() << " H-" << this->getHealth() << " lvl-"
       << this->getLevel() << endl;
}

/**
 * @author Jason Bowerman
 * gameObj.h is the super class for all game objects such as space knight.
 * It contains basic getters and setters allong with some virtual methods.
 */
#pragma once
#include <iostream>
#include <string>

using namespace std;

class gameObj {
public:
  gameObj();
  gameObj(string name, int health, int attack);
  gameObj(string name, int health);
  gameObj(string name);

  void setName(string name);
  void setHealth(int health);
  void setAttack(int attack);
  void setAlive(bool alive);
  void setNextLevel(int next);
  void setExp(int exp);
  void setLevel(int level);
  void setCommander(gameObj &c);
  string getName();
  int getHealth();
  int getAttack();
  int getLevel();
  int getExp();
  int getNextLevel();
  gameObj &getCommander();

  bool isAlive();
  virtual void printObj();
  virtual void Attack(gameObj *e);
  virtual void Options(vector<gameObj *> opponent);
  virtual void LevelUp(gameObj *c);
  virtual void LevelUp();

protected:
private:
  int health;
  bool alive;
  string name;
  int attack;
  int lvl;
  int exp;
  int nextLvl;
  gameObj *command;
};
/**
 * check if the obj is alive
 * @return is the obj alive
 */
bool gameObj::isAlive() { return this->alive; }
/**
 * set wether or not the object is alive
 * @param alive determins if the obj is alive.
 */
void gameObj::setAlive(bool alive) { this->alive = alive; }
/**
 * Options displays the gameObj's turn options.
 * @param opponent is the opposing team
 */
void gameObj::Options(vector<gameObj *> opponent) {
  cout << "nothing to do!\n";
}

// TODO implement damage
/**
 * Attack gameObj deal damage.
 * @param e gameObj to Attack
 *
 */
void gameObj::Attack(gameObj *e) {
  bool toast = false;
  if (!e->isAlive())
    toast = true;
  cout << endl
       << endl
       << this->getName() << " is attacking " << e->getName() << endl;
  e->setHealth(e->getHealth() - this->getAttack());
  if (e->getHealth() <= 0) {
    if (!toast) {
      this->setExp(this->getExp() + 100);
      this->LevelUp(&this->getCommander());
    }
    e->setHealth(0);
    e->setAlive(false);
  }
  if (!toast)
    cout << e->getName() << " took " << this->getAttack() << " damage!\n\n";
  else
    cout << "OVERKILL!\n\n";

  cin.ignore(1, '\n');
  cin.get();
}

/**
 * Default Constructor
 */
gameObj::gameObj() {
  health = 10;
  name = "un-named";
  alive = true;
  attack = 10;
  lvl = 0;
  this->exp = 0;
  this->exp = 100;
}
/**
 * Constructor
 * @param name is the name of the gameObj
 * @param health is the health of the gameObj
 * @param attack is the damage the gameObj can deal
 */
gameObj::gameObj(string name, int health, int attack) {
  this->name = name;
  this->health = health;
  this->attack = attack;
  alive = true;
  lvl = 0;
  this->exp = 0;
  this->exp = 100;
}
/**
 * Constructor
 * @param name name of gameObj
 * @param health health of the gameObj
 */
gameObj::gameObj(string name, int health) {
  this->name = name;
  this->health = health;
  alive = true;
  lvl = 0;
  this->exp = 0;
  this->exp = 100;
}

/**
 * Constructor
 * @param name name of gameObj
 */
gameObj::gameObj(string name) {
  this->name = name;
  alive = true;
  lvl = 0;
  this->exp = 0;
  this->exp = 100;
}
/**
 * basic print out gameObj stats
 */
void gameObj::printObj() {
  cout << name << " H-" << health << " A-" << attack << " lvl-" << lvl << endl;
}
/**
 * sets name of gameObj
 * @param name is the name of the gameObj
 */
void gameObj::setName(string name) { this->name = name; }
/**
 * sets the health of the gameObj
 * @param health is the health of the gameObj
 */
void gameObj::setHealth(int health) { this->health = health; }

/**
 * sets attack damage of the gameObj
 * @param attack is the amount of attack damage the gameObj can deal
 */
void gameObj::setAttack(int attack) { this->attack = attack; }

/**
 * gets the gameObj's named
 * @return the name of the gameObj
 */
string gameObj::getName() { return name; }
/**
 * gets the health of the gameObj
 * @return the health of the gameObj
 */
int gameObj::getHealth() { return health; }
/**
 * gets attack of the gameObj
 * @return attack damage
 */
int gameObj::getAttack() { return attack; }
/**
 * gets the level of the gameObj
 * @return level
 */
int gameObj::getLevel() { return lvl; }

/**
 * get current exp
 * @retun current exp
 */
int gameObj::getExp() { return exp; }
/**
 * get the amount of exp for leveling up
 * @return The amount of exp needed
 */
int gameObj::getNextLevel() { return nextLvl; }
/**
 * set the amount of exp to level up. this comes in handy to make leveling
 * harder
 * @param next is the exp for next level
 */
void gameObj::setNextLevel(int next) { this->nextLvl = next; }
/**
 * sets the current exp. this is used for reseting the exp
 * @param exp is the amount to set exp to
 */
void gameObj::setExp(int exp) { this->exp = exp; }
/**
 * set the level of the gameObj
 * @param level is the level to be set
 */
void gameObj::setLevel(int level) { this->lvl = level; }
/**
 * Level up gameObj
 * @param c is the commander of the gameObj. The commander gets a percentage of
 * exp.
 */
void gameObj::LevelUp(
    gameObj *c) // TODO get exp earned by the level of badguy killed and a
                // percentage for the commander from this percentage
{

  if (this->getExp() >= this->getNextLevel()) {
    this->setLevel(this->getLevel() + 1);
    this->setExp(0);
    this->setNextLevel(this->getNextLevel() + 100);
    c->setExp(c->getExp() + 50);
  }
}

/**
 * Level up gameObj
 */
void gameObj::LevelUp() // TODO get exp earned by the level of badguy killed and
                        // a percentage for the commander from this percentage
{

  if (this->getExp() >= this->getNextLevel()) {
    this->setLevel(this->getLevel() + 1);
    this->setExp(0);
    this->setNextLevel(this->getNextLevel() + 100);
  }
}
/**
 * set the gameObj's commander
 * @param c is the commander
 */
void gameObj::setCommander(gameObj &c) { this->command = &c; }
/**
 * get gameObj's commander
 * @return commander
 */
gameObj &gameObj::getCommander() { return *command; }

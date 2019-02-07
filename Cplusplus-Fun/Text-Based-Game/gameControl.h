/**
 * @author Jason Bowerman
 * Game control controls the flow of the game.
 */
#pragma once
#include "Commander.h"
#include "SpaceKnight.h"
#include "SpaceMedic.h"
#include "gameObj.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class gameControl {
public:
  gameControl();
  void createMainChar();
  void Introduction();
  void setUpFriendlies();
  void displayFriendlies();
  void displayEnemies();
  void Fight();
  void setUpEnemies();
  void friendTurn();
  void enemyTurn();
  bool checkWin();
  bool checkLose();

protected:
private:
  gameObj *mainChar;
  gameObj *EC;
  vector<gameObj *> enemies;
  vector<gameObj *> friendlies;
};

/**
 * constructor
 */
gameControl::gameControl() {
  mainChar = new Commander();
  EC = new Commander();
  EC->setName("Commander Tim");
}
/**
 * prompts the user for name and sets the friendly commander.
 */
void gameControl::createMainChar() {
  string n;
  cout << "what is your name?: ";
  getline(cin, n);
  this->mainChar->setName("Commander " + n);
  this->mainChar->printObj();
}

/**
 * quick introduction to the game and how to play.
 */
void gameControl::Introduction() {
  cout << "Welcome, " << this->mainChar->getName() << " to Text Fighters!\n";
  // TODO write how to play the game
}

/**
 * set up the friendly team. This is the users team.
 * They can make it however they like.
 */
void gameControl::setUpFriendlies() {
  cout << "You get 4 friendlies, choose wisley!\n";
  int choice;
  string playerName;
  for (int i = 0; i < 4; i++) {

    cout << endl << endl;
    cout << "choose friendly " << i << endl;
    cout << "1 - Space Knight \n"
         << " 2 - Space Medic \n"
         << "choose: ";
    cin >> choice;

    while (choice > 2 || choice < 1 || cin.fail()) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "invalid, choose again: ";
      cin >> choice;
    }
    cout << "name: ";
    cin.ignore(1, '\n');
    getline(cin, playerName);

    switch (choice) {
    case 1:
      friendlies.push_back(new SpaceKnight(playerName, *mainChar));
      break;
    case 2:
      friendlies.push_back(new SpaceMedic(playerName, *mainChar));
      break;
    default:
      break;
    }
  }
}

/**
 * Set up enemy team. This will be done randomly once there are more class
 * options.
 */
// TODO randomize enemy choices
void gameControl::setUpEnemies() {
  this->enemies.clear();
  for (int i = 0; i < 4; i++) {
    this->enemies.push_back(new SpaceKnight("jim", *mainChar));
  }
}

/**
 * Display friendly team.
 */
void gameControl::displayFriendlies() {
  mainChar->printObj();
  for (int i = 0; i < this->friendlies.size(); i++) {
    friendlies[i]->printObj();
  }
}

/**
 * Display enemy team.
 */
void gameControl::displayEnemies() // god I hate myself. I miss her so much. why
                                   // did I do it?
{

  EC->printObj();
  for (int i = 0; i < enemies.size(); i++) {
    enemies[i]->printObj();
  }
}

/**
 * Fight stage(game or fight loop).
 */
void gameControl::Fight() {
  while (true) {
    friendTurn();
    if (checkWin()) {
      cout << "YOU WIN!\nYour Commander gets 200xp\n";
      mainChar->setExp(mainChar->getExp() + 200);
      mainChar->LevelUp();
      break;
    }
    if (checkLose()) {
      cout << "Better luck next time!\n";
      break;
    }
    enemyTurn();
    if (checkWin()) {
      cout << "YOU WIN!\nYour Commander gets 200xp\n";
      mainChar->setExp(mainChar->getExp() + 200);
      mainChar->LevelUp();
      break;
    }
    if (checkLose()) {
      cout << "Better luck next time!\n";
      break;
    }
  }
}

/**
 * Functionality for when it is the users turn
 */
void gameControl::friendTurn() {
  for (int i = 0; i < friendlies.size(); i++) {
    cout << "CURRENT STATE!\n";
    this->displayFriendlies();
    cout << endl;
    this->displayEnemies();
    cout << endl << endl;
    friendlies[i]->Options(enemies);
  }
  cout << "Your turn is over. Hit enter when you are ready to be attacked!";
  cin.ignore(1, '\n');
  cin.get();
}

/**
 * Functionality for enemy's turn
 */
void gameControl::enemyTurn() {
  cout << endl << endl;
  for (int i = 0; i < enemies.size(); i++) {
    cout << enemies[i]->getName()
         << " did nothing\n"; // just for now. it will randomize options. also
                              // enemy classes will not be the same as friendly
                              // classes.
    // TODO fix enemyTurn
  }

  cout << endl << endl;
}
/**
 * check if user won the fight
 * @return win or nothing
 */
bool gameControl::checkWin() {
  bool win = true;
  for (int i = 0; i < enemies.size(); i++) {
    if (enemies[i]->isAlive())
      win = false;
  }
  return win;
}
/**
 * check if user lost the fight
 * @return lose or nothing
 */
bool gameControl::checkLose() {
  bool lose = true;
  for (int i = 0; i < friendlies.size(); i++) {
    if (friendlies[i]->isAlive())
      lose = false;
  }
  return lose;
}

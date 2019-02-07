/**
 * @Author Jason Bowerman
 * A text based battle game. good example of polymorphism.
 */
#include "gameControl.h"
#include <iostream>
#include <string>

using namespace std;

void clear();

int main() {
  gameControl g;
  g.createMainChar();
  g.Introduction();
  g.setUpFriendlies();
  g.setUpEnemies();
  cout << endl << endl;

  while (true) // game loop
  {
    cout << "Here is your team!\n";
    g.displayFriendlies();
    cout << endl;
    cout << "When you are ready to fight hit enter\n";
    cin.get();
    clear();
    g.Fight();
    cin.get();
    clear();
    g.setUpEnemies();
  }

  return 0;
}

void clear() {

  for (int i = 0; i < 150; i++) {
    cout << endl;
  }
}

/**
 * @author Jason Bowerman
 * Find the largest palidrom using three digit numbers
 */

#include <iostream>
#include <string>

using namespace std;

bool isPalidrome(int n);
int main() {
  int a = 999; // starting with heighest the digit number
  int b = 999;
  int largest = 0;
  while (a != 2) // go through all of the palidromes because I thought it would
                 // look cool. not aiming for efficiency.
  {
    if (isPalidrome(a * b)) {
      cout << a << " * " << b << " = " << a * b << endl; // display it
      if (a * b > largest) // if we find a larger palidrom make it the new
                           // largest palidrome
        largest = a * b;
    }

    b--;
    if (b == 2) {
      a--; // just itteration
      b = 999;
    }
  }
  cout << largest; // print out the largest at the end
  return 0;
}
/**
 * check if number is a palidrome
 * @param  n [the number to check]
 * @return   [true if it is false if it isn't]
 */
bool isPalidrome(int n) {
  string pal = std::to_string(n); // convert int to string

  string revPal;

  for (int i = pal.size() - 1; i >= 0; i--) { // reverse the string
    revPal.push_back(pal[i]);
  }
  if (pal == revPal) // simply if it is equal it is a palidrome
    return true;
  else
    return false;
}

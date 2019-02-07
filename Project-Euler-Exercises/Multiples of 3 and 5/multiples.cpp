/*
 * @author Jason Bowerman
 * find the sum of all the multiples of 5 and 3 under 1000
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int count = 1;
  int three = 0, five = 0;
  int sum = 0;

  // go until both are over or equal to 1000
  while (three < 1000 || five < 1000) {
    three = 3 * count; // get new five and three
    five = 5 * count;

    if (three < 1000) { // check and add
      sum += three;
    }

    if (five < 1000 && five % 15 != 0) { // check, add and remove multiples of
                                         // 15 since all the multiples of 15
                                         // will be repeated
      sum += five;
    }
    count++; // increment multiplier
  }

  cout << sum; // output result
}

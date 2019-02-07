/**
 * @author Jason Bowerman
 * sum of even fibonacci numbers under 4000000
 */
#include <iostream>

using namespace std;

void Get_Fib(int fib[], int &size);
int Sum_even(int fib[], int size);
int main() {
  int fib[500];
  int size;
  Get_Fib(fib, size);
  cout << Sum_even(fib, size);
}

/**
 * get an array of fibonacci sequence limited to 4000000
 * @param fib  [the array of fibonacci numbers]
 * @param size [size of the array]
 */
void Get_Fib(int fib[], int &size) {
  size = 2;
  fib[0] = 1;
  fib[1] = 1;
  int i = fib[size - 1] + fib[size - 2];
  while (i < 4000000) {
    fib[size] = i;
    size++;
    i = fib[size - 1] + fib[size - 2];
  }
}

/**
 * add all the numbers together that are even
 * @param  fib  [the array of fibonacci numbers]
 * @param  size [size of the array]
 * @return      [returns the sum]
 */
int Sum_even(int fib[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (fib[i] % 2 == 0) {
      sum += fib[i];
    }
  }
  return sum;
}

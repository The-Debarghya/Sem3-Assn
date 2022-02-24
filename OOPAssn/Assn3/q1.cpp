/*Write a macro to find the maximum of two numbers.
Call the macro with i) two integers as the arguments and ii) two char * as the arguments.*/

#include <iostream>

#define  MAX(a,b) (((a)>(b))?(a):(b))

int main(int argc, char const *argv[]) {
  int x, y;
  std::cout << "Enter 2 numbers:";
  std::cin >> x >> y;
  char const *a = "zyxw";
  char const *b = "abcd";
  std::cout << "max of the 2 numbers:"<< MAX(x,y) << '\n';
  std::cout << "max of the 2 char *s:"<< MAX(a,b) << '\n';
  return 0;
}

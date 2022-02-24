/*Define functions f(int, int) and f (char, int).
Call the functions with arguments of type (int, char), (char,char) and (float, float).*/

#include <iostream>
void f(int, int) {

  std::cout << "Inside f(int, int)" << '\n';
}
void f(char, int) {
  std::cout << "Inside f(char, int)" << '\n';
}
int main(int argc, char const *argv[]) {
  int i=20;
  float fo=69.66, f1 = 56.87;
  char c='c', ch='s';
  f(i, c);
  f(c, ch);
  //f(fo, f1);
  return 0;
}

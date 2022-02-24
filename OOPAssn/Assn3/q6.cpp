/*Write a function void f(int) that prints “inside f(int)”.
Call the function with actual argument of type: i) int, ii) char, iii) float and iv) double.
Add one more function f(float) that prints “inside f(float)”.  Repeat the calls again and observe the outcomes.*/

#include <iostream>
void f(int) {
  std::cout << "Inside f(int)" << '\n';
}
void f(float) {
  std::cout << "Inside f(float)" << '\n';
}
int main(int argc, char const *argv[]) {
  int i=20;
  float fo=69.66;
  double d=86.98;
  char c='c';
  f(i);
  f(fo);
  f(c);
  //f(d);
  std::cout << '\n';
  f(i);
  f(fo);
  f(c);
  //f(d);
  return 0;
}

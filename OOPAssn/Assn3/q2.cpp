//Write a function to find the product of two numbers.  Call it number of times. Make the functions inline.

#include <iostream>
#include <chrono>
using namespace std::chrono;
inline int product(int a, int b){
  return a*b;
}
int prod(int a, int b){
  return a*b;
}
int main(int argc, char const *argv[]) {
  auto start2 = high_resolution_clock::now();

  for (size_t i = 0; i < 100; i++) {
    std::cout << prod(145, 634) << '\n';
  }
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);
  std::cout << "Time taken by normal function: " << duration2.count() << " microseconds" << '\n';

  auto start1 = high_resolution_clock::now();

  for (size_t i = 0; i < 100; i++) {
    std::cout << product(145, 634) << '\n';
  }
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  std::cout << "Time taken by inline function: " << duration1.count() << " microseconds" << '\n';

  return 0;
}

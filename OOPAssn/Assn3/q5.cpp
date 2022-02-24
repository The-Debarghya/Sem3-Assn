/*Write a function that will have income and tax rate as arguments and will return tax amount.
In case tax rate is not provided it will be automatically taken as 10%. Call it with and without tax rate.*/

#include <iostream>
float total_tax(int income, float r=10){
  float total = (income*r)/100;
  return total;
}

int main(int argc, char const *argv[]) {
  int income;
  float rate;
  char c;
  std::cout << "Enter your income:";
  std::cin >> income;
  std::cout << "Do you wish to enter your tax rate?(y/n)" << '\n';
  std::cin >> c;
  if(c=='y'){
    std::cout << "Enter tax rate %:";
    std::cin >> rate;
    std::cout << "Your total tax at " << rate << "% rate is:" << total_tax(income, rate) << "\n";
  }
  else{
    std::cout << "Your total tax at 10% rate is:" << total_tax(income) << "\n";
  }
  return 0;
}

/*Write a function max (a, b) that will return the reference of larger value.
Store the returned information to x where x is a i) variable of type a or b, ii) variable referring to type of a or b.
In both the cases modify x. Check also the values of a and b*/

#include<iostream>
int& max(int &a,int &b){
  if (a>b) {
    return a;
  } else {
    return b;
  }
}

int main(){

  int a,b;
  std::cout<<"Enter 2 numbers :";
  std::cin>>a>>b;
  int x=max(a,b);
  int &y=max(a,b);
  std::cout<<"Maximum of "<<a<<" and "<<b<<" is "<<x<<"\n";
  std::cout<<"Maximum(using reference) of "<<a<<" and "<<b<<" is "<<y<<"\n";
  x=79;
  y=79;
  std::cout<<"After changing x and y:\n";
  std::cout<<"Maximum of "<<a<<" and "<<b<<" is "<<x<<"\n";
  std::cout<<"Maximum(using reference) of "<<a<<" and "<<b<<" is "<<y<<"\n";
  return 0;
}

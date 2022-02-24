//Write a function swap (a, b) to interchange the values of two variables. Do not use pointers.

#include<iostream>

void swap(int &a,int&b){
    a=a^b;
    b=a^b;
    a=a^b;
}

int main(){
  int a,b;
  std::cout<<"Enter 2 numbers:";
  std::cin>>a>>b;
  std::cout<<"Before swapping: "<<a<<' '<<b<<"\n";
  swap(a,b);
  std::cout<<"After swapping: "<<a<<' '<<b<<"\n";
  return 0;
}

/*Write a program that will have an integer variable and a pointer (say, p) pointing to it. Also have a
pointer to pointer pointing to p. Take the value for the integer variable and print it using p, and pp.*/


#include <stdio.h>

int main(){        //driver code
  int x, *p;
  int *(*pp);      //declaring pointer to a pointer
  printf("Enter an Integer:");
  scanf("%d", &x);
  p = &x;           //location of x is put into p
  pp = &p;         //location of p is put into pp
  printf("The integer is:%d\n", *p);
  printf("The location of the integer:%p\n", p);
  printf("The integer is:%d\n", **pp);
  printf("The location of the pointer to the integer:%p\n", pp);
  return 0;
}

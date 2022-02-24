/*Implement the programs in one dimensional array breaking it into functions for i) getting the dimensions from user,
ii) dynamic memory allocation, iii) accepting the values and iv) printing the values.*/


#include <stdio.h>
#include <stdlib.h>

int getdimension(int *ptr){     //get the dimension of the array
  printf("No. of elements of the array:");
  scanf("%d", ptr);
  return *ptr;
}
int *memoryalloc(int *ptr, int x){    // allocate memory for required number of integers
  ptr = (int *)malloc(x*sizeof(int));
  if (ptr==NULL){  //check if malloc returns null
     printf("An error occured\n" );
     exit(0); //if null exit
  }
  return ptr;
}
void inputval(int *ptr, int x){ //take input of the values of the array
  printf("Enter the elements\n");
  for (int i = 0; i < x; i++) {
    scanf("%d", (ptr+i));
  }
}
void printval(int *ptr, int x) {  //print the values of the array
  printf("The elements are:\n");
  for (int j = 0; j < x; j++) {
    printf("%d ", *(ptr+j));
  }
  printf("\n");
}
int main() {  //driver code
  int x, *p;
  x = getdimension(&x);
  p = memoryalloc(p, x);  //get the allocated reference to the pointer
  inputval(p, x);
  printval(p, x);
  return 0;
}

/*Implement the programs in 2 dimensional breaking it into functions for i) getting the dimensions from user,
ii) dynamic memory allocation, iii) accepting the values and iv) printing the values.*/


#include <stdio.h>
#include <stdlib.h>
//using pointer to array
int getdimension(int *x) {   //get the dimensions of rows or columns
  scanf("%d", x);
  return *x;
}
void getval_print(int **p, int r, int c) {  //get the integers of the array and print them
  printf("Enter the elements:");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf(" %d", (*(p+i)+j));
    }
  }
  printf("The elements are:\n");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        printf("%d ", *(*(p+i)+j));
      }
      printf("\n");
    }
}
int **memoryalloc(int **p, int r, int c){ //allocate memory for the required no. of integers
  p = (int **)malloc(r*sizeof(int *)); //allocates r no of pointers to array
  for (int i = 0; i < r; i++) {
    p[i] = (int *)malloc(c * sizeof(int)); //allocates c no of integers for each pointer
  }
  if(p == NULL){ //check if malloc returns null
    printf("An error occurred!!\n");
    exit(0); //if null exit
  }
  return p;
}
int main() { //driver code
  int r, c;
  printf("No. of rows of the array:");
  r = getdimension(&r);
  printf("No. of cols of the array:");
  c = getdimension(&c);
  int **p;
  getval_print(memoryalloc(p, r, c), r, c);
  return 0;
}

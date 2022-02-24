/*Implement a two dimensional array of integers using a) pointer to an array and b) array of pointers.
Accept the value for the elements and print those.*/

#include <stdio.h>
#include <stdlib.h>

int main() { //driver code
  int r, c;
  printf("Enter no. of rows:");
  scanf("%d", &r);
  printf("Enter no. of columns:");
  scanf("%d", &c);
  //using array of pointers
  int **p;
  p = (int *)malloc(r*sizeof(int *));          //allocating memory for an array of pointers
  for (int i=0; i<r; i++){
    p[i] = (int *)malloc(c * sizeof(int));     //allocating memory for c no. of integers for each pointer
  }
  if(p == NULL){  //checking if malloc returns null
    printf("An error occurred!!\n");
    exit(0);    //if null exit
  }
  printf("Enter the elements:\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", (*(p+i)+j));
    }
  }
  printf("The elements are:\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", *(*(p+i)+j));   //printing wrt reference of p
    }
    printf("\n");
  }
  return 0;
}

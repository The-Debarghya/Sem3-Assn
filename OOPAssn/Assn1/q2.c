/*Implement a one dimensional array of integers where array size of the array will be provided during
runtime. Accept the value for the elements and print those using pointers.*/


#include <stdio.h>
#include <stdlib.h>

int main(){                               //driver code
  int x, *p;
  printf("Enter size of array:" );
  scanf("%d", &x);
  p = (int *)malloc(x*sizeof(int));       //allocating a block of memory for x integers
  if(p == NULL){                          //checking if malloc can allocate that memory
    printf("An unexpected error occured!!\n" );
    exit(0);    //if couldn't allocate, exit
  }
  printf("Enter the %d elements:", x);
  for (int i=0 ; i < x; i++) {
    scanf("%d", (p+i));

  }
  printf("The elements are:\n");
  for (int j = 0; j < x; j++) {
    printf("%d ", *(p+j));           //printing wrt reference of p
  }
  printf("\n");
  free(p);
  return 0;
}

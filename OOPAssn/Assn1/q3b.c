/*Implement a two dimensional array of integers using a) pointer to an array and b) array of pointers.
Accept the value for the elements and print those.*/


#include <stdio.h>
#include <stdlib.h>
//using pointer to array
int main() { //driver code
  int r, c;
  printf("Enter no. of rows:");
  scanf("%d", &r);
  printf("Enter no. of columns:");
  scanf("%d", &c);  //getting no. of rows and columns

int **p;  //declaring a pointer to array
p = (int **)malloc(r*sizeof(int *));  //allocating memory for each pointer
for (int i = 0; i < r; i++) {
  p[i] = (int *)malloc(c * sizeof(int));  //allocating c no. of integers
}
if(p == NULL){  //checking if malloc returns null
  printf("An error occurred!!\n");
  exit(0);  //if null exit
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
    printf("%d ", *(*(p+i)+j)); //printing values wrt reference of p
  }
  printf("\n");
}
return 0;
}

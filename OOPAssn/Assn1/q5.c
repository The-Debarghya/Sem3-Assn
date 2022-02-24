/*Store name and age of number of persons (number provided at run time). Collect the data and display
data in the ascending order of age. Implement without using structure. Write functions for memory
allocation of the list, sorting and display of data.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_BUFF 80   //defining a buffer for name size
int *age_memalloc(int *x, int n){  //allocate memory for ages of n members
  x = (int *)malloc(n*sizeof(int));
  return x;  //return the allocated pointer
}
char **name_memalloc(char **c, int x){  //allocate memory for names of n members
  c = (char **)malloc(x*sizeof(char *)); //allocate memeory for an array of strings
  for (int i = 0; i < x; ++i) {
    c[i] = (char *)malloc(CHAR_BUFF+1);
  }
  return c;  //return the allocated pointer
}
void display(char **name, int *age, int n){ //print the names and ages of members

  for (int i = 0; i < n; i++) {
    printf("%s\t\t%d\n", name[i], age[i]);
  }
}
void sort(char **name, int *age, int n) { //sort the names according to ascending order of age
  char temp_str[CHAR_BUFF];
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (age[i] > age[j]) { //if ith age > jth age
        temp = age[i];
        age[i] = age[j];    //swap the values
        age[j] = temp;
        strncpy(temp_str, name[i], CHAR_BUFF);
        strncpy(name[i], name[j], CHAR_BUFF);  //also the names, else the sequence will be lost
        strncpy(name[j], temp_str, CHAR_BUFF);
      }
      else
        continue;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%s\t\t%d\n", name[i], age[i]);  //print the sorted list
  }
}
int main() {  //driver code
  int x, *a;
  char **name;
  printf("How many data entries?");
  scanf("%d", &x);
  a = age_memalloc(a, x);
  name = name_memalloc(name, x);
  for (int i = 0; i < x; i++) {  //taking input of x no of members
    printf("Enter name %d ", i+1);
    scanf(" %80s", name[i]);
    printf("Enter age of %s:", name[i]);
    scanf(" %d", &a[i]);
  }
  printf("\nThe following data has been saved:\n" );
  printf("NAME\t \tAGE\n");
  display(name, a, x);
  printf("\nData in ascending order of age:\n" );
  printf("NAME\t \tAGE\n");
  sort(name, a, x);
  return 0;
}

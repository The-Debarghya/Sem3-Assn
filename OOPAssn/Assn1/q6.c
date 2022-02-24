/*Store name and age of number of persons (number provided at run time). Collect the data and display
data in the ascending order of age. Implement using structure. Write functions for memory
allocation of the list, sorting and display of data.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_BUFF 80  //defining a buffer for name size
struct records{  //a structure containing name and age as variables
  char name[CHAR_BUFF];
  int age;
};
struct records *memalloc(struct records *p, int n){  //allocate memory for n no of struct records
  p = (struct records *)malloc(n*sizeof(struct records));
  return p;  //return the allocated pointer
}
void display(struct records *ptr, int n){   //print the names and ages of members

  for (int i = 0; i < n; i++) {
    printf("%s\t\t%d\n", ptr[i].name, ptr[i].age);
  }
}
void sort(struct records *ptr, int n) { //sort the names according to ascending order of ages
  struct records tempo;  //temporary struct to swap the values
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (ptr[i].age > ptr[j].age) {  //if age of ith struct > age of jth struct
        tempo = ptr[i];
        ptr[i] = ptr[j];  //swap the structs
        ptr[j] = tempo;
      }
      else
        continue;
    }
  }
  for (int i = 0; i < n; i++) {  //print the sorted list
    printf("%s\t\t%d\n", ptr[i].name, ptr[i].age);
  }
}
int main() {  //driver code
  int x;
  printf("How many data entries?");
  scanf("%d", &x);
  struct records *p;
  p = memalloc(p, x);
  for (int i = 0; i < x; i++) {  //get names and ages of x no of members
    printf("Enter name %d:", i+1);
    scanf("%80s", p[i].name);
    printf("Enter age of %s:", p[i].name);
    scanf("%d", &p[i].age);
  }
  printf("The following data has been saved:\n" );
  printf("NAME\t \tAGE\n");
  display(p, x);
  printf("Data in ascending order of age:\n" );
  printf("NAME\t \tAGE\n");
  sort(p, x);
  return 0;
}

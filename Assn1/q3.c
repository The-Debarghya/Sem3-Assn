#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int linear_search(int *p, int n, int s) {
  for (size_t i = 0; i < n; i++) {
    if(p[i] == s){
      return i;
    }
  }
  return -1;
}
/*int iterativeBinarySearch(int *p, int n, int s){
  int start_index =0;
  int end_index = n-1;
   while (start_index <= end_index){
      int middle = start_index + (end_index-start_index )/2;
      if (p[middle] == s)
         return middle;
      if (p[middle] < s)
         start_index = middle + 1;
      else
         end_index = middle - 1;
   }
   return -1;
}*/
int recursiveBinarySearch(int *p, int start_index, int end_index, int s){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (p[middle] == s)
         return middle;
      if (p[middle] > s)
         return recursiveBinarySearch(p, start_index, middle-1, s);
      return recursiveBinarySearch(p, middle+1, end_index, s);
   }
   return -1;
}
int main() {
  int n, *p, loc, s;
  printf("How many elements of the array:");
  scanf("%d", &n);
  p =(int *)malloc(n*sizeof(int));
  printf("Enter the elements:");
  for (size_t i = 0; i < n; i++) {
    scanf("%d", p+i);
  }
  printf("Enter the item to search for:");
  scanf("%d", &s);
  loc = linear_search(p, n, s);
  //loc = iterativeBinarySearch(p, n, s);
  //loc = recursiveBinarySearch(p, 0, n-1, s);
  if (loc>0) {
    printf("%d found at index:%d\n", s, loc);
  }
  else {
    printf("%d not found\n", s);
  }
  return 0;
}

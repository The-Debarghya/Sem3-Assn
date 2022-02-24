#include <stdio.h>
#include <stdlib.h>
int main(){
  int n, *s, a = 1, d = 1, i;
  printf("Enter the no of elements of array:");
  scanf("%d", &n);
  s = (int *)malloc(n*sizeof(int));
  printf("Enter the elements:");
  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);
  i = 0;
  while ((a == 1 || d == 1) && i < n - 1) {
    if (s[i] < s[i+1])
      d = 0;
    else if (s[i] > s[i+1])
      a = 0;
    i++;
  }
  if (a == 1)
    printf("The array is sorted in ascending order.\n");
  else if (d == 1)
    printf("The array is sorted in descending order.\n");
  else
    printf("The array is not sorted.\n");
  return 0;
}

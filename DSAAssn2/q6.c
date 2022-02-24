#include <stdio.h>
#include <stdlib.h>
#define SIZE 12
int median(int x[], int n) {
  int med;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (x[i] > x[j]) {
        med = x[i];
        x[i] = x[j];
        x[j] = med;
      }
    }
  }
  med = x[n/2];
  return med;
}
int main() {
  int arr[SIZE] = {4, 5, 1, 13, 3, 25, 27, 18, 10, 3, 4, 9};
  int min[SIZE], max[SIZE], med[SIZE];
  int n = 3, temp;
  int l = (n-1)/2;
  int modarr[SIZE+2*l];
  for (int i = l, j=0; i<(SIZE+l) && j<12; i++, j++) {
    modarr[i] = arr[j];
  }
  for (int i = 0, j = SIZE+l; i < l && j<SIZE+2*l; i++, j++) {
    modarr[i] = 0;
    modarr[j] = 0;
  }
  int **window, tmp[n];
  window = (int **)malloc(n*sizeof(int *));
  for (int i = 0; i < n; i++) {
    window[i] = &modarr[i];
    tmp[i] = modarr[i];
  }
  for (int i = 0; i < SIZE; i++) {
    temp = i;
    med[i] = median(tmp, n);
    max[i] = tmp[n-1];
    min[i] = tmp[0];
    for (int j = 0; j < n; j++) {
      window[j] = &modarr[temp+1];
      tmp[j] = modarr[temp+1];
      temp++;
    }
  }
  printf("Actual array:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }printf("\n");
  printf("Max window filter:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", max[i]);
  }printf("\n");
  printf("Min window filter:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", min[i]);
  }printf("\n");
  printf("Median window filter:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", med[i]);
  }printf("\n");
  return 0;
}

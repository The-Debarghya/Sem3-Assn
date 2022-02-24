#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdbool.h>
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
void heapify(int arr[], int n, int i){
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}
}
int partition (int arr[], int low, int high){
    int pivot = arr[high]; // pivot
    int i = (low - 1);// Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++){
        // If current element is smaller than the pivot
        if (arr[j] < pivot){
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)  //preparing 2 lists
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {  //merging lists
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) { //remaining elements
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}
void heapSort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
void insertionSort(int *arr, int n){
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
void bubbleSort(int *arr, int n) {
  for (int i = 0; (i < n); i++) {
    for (int j = i+1; j < n; j++) {
      if (arr[i] > arr[j]) {
        swap(&arr[i], &arr[j]);
      }
    }
  }
}
void selectionSort(int *arr, int n) {
  int min_idx, temp;
  for (int i = 0; i < n-1; i++) {
    min_idx = i;
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(&arr[min_idx], &arr[i]);
  }
}
void mergeSort(int *arr, int lbnd, int ubnd) {
  int mid;
  if (lbnd < ubnd) {
    mid = lbnd + (ubnd-ubnd)/2;
    mergeSort(arr, lbnd, mid);
    mergeSort(arr, mid+1, ubnd);
    merge(arr, lbnd, mid, ubnd);
  }
}
void quickSort(int *arr, int l, int h) {
  int j;
  if (l<h) {
    j = partition(arr, l, h);
    quickSort(arr, l, j-1);
    quickSort(arr, j+1, h);
  }
}
void optimized_bSort(int arr[], int n){
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)     {
        if (arr[j] > arr[j+1])        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}
void CocktailSort(int a[], int n){
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped){
        swapped = false;
        for (int i = start; i < end; ++i){
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i){
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}
void shellSort(int *arr, int n) {
  for (int gap = n/2; gap >= 1; gap= gap/2) {
    for (int j = gap; j < n; j++) {
      for (int i = j-gap; i >=0; i=i-gap) {
        if (arr[i+gap] > arr[i]) {
          break;
        } else {
          swap(&arr[i+gap], &arr[i]);
        }
      }
    }
  }
}
#endif

#include<stdio.h>

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]){
	int i = 0, j = 0, k = 0;
	while (i<n1 && j <n2)	{
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}
	while (i < n1)
		arr3[k++] = arr1[i++];
	while (j < n2)
		arr3[k++] = arr2[j++];
}
int main(){
	int arr1[] = {1, 3, 5, 7};
	int n1 = sizeof(arr1) / sizeof(int);
	int arr2[] = {2, 4, 6, 8};
	int n2 = sizeof(arr2) / sizeof(int);
	int arr3[n1+n2];
	mergeArrays(arr1, arr2, n1, n2, arr3);
    printf("The 2 arrays are:\n");
    for(int i=0; i<n1; i++){
        printf("%d ", arr1[i]);
    }printf("\n");
    for(int i=0; i<n2; i++){
        printf("%d ", arr2[i]);
    }printf("\n");
	printf("Array after merging: " );
	for (int i=0; i < n1+n2; i++)
		printf("%d ", arr3[i]);
  printf("\n");
	return 0;
}

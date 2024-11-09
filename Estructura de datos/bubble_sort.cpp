#include <stdio.h>

void bubblesort(int arr[], int n){
	int i, j , tmp;
	
	for (i=0; i<n-1; i++){
		for(j=0; j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}

void printArray(int arr[], int n){
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(){
	int arr[] = {44,55,12,42,94,18,6,67};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	bubblesort(arr, n);
	
	printf("Arreglo ordenado: ");
	printArray(arr, n);
	return 0;
}

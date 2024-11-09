#include <stdio.h>

void seleccion(int arr[], int n){
	
	printf("Seleccion");
	int i, j, min_idx, tmp;
	
	for(i=0; i< n-1; i++){
		min_idx = i;
		for(j=i; j<n; j++){
			if(arr[j]<arr[min_idx]){
				min_idx = j;
			}
		}
		tmp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = tmp;
	}
}

void printArray(int arr[], int n){
	int i;
	for(i=0; i<n; i++)
		printf(" %d ", arr[i]);
	printf("\n");
}

int main(){
	int arr[] = {44,55,12,42,94,18,6,67};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	seleccion(arr, n);
	
	printf("Arreglo ordenado: ");
	printArray(arr, n);
	return 0;
}

#include <stdio.h>

void shellsort(int arr[], int n){
	printf("shell");
	int gap, i;
	for(gap = n/2; gap > 0; gap/=2){
		for(i = gap; i<n; i++){
			int temp = arr[i];
			int j;
			for(j=i; j>=gap && arr[j-gap]>temp; j-=gap)
				arr[j]=arr[j-gap];
			arr[j]=temp;
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
	
	shellsort(arr, n);
	
	printf("Arreglo ordenado: ");
	printArray(arr, n);
	return 0;
}

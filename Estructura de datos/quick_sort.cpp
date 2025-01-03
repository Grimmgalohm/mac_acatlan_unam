#include <stdio.h>

void swap(int*a, int*b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low-1);
	int j;
	
	for(j = low; j<=high-1; j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}	
	}
	swap(&arr[i+1, &arr[high]]);
	return (i+1);
}



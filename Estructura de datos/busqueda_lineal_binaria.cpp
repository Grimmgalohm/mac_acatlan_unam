#include <stdio.h>

int busquedaLineal(int arr[], int n, int x){
	int i;
	for(i = 0; i<n; i++){
		if(arr[i]==x){
			return i;
		}
	}
	return -1;
}

int busquedaBinaria(int arr[], int n, int x){
	int izquierda = 0, derecha = n - 1;
	while(izquierda <= derecha){
		int medio = izquierda + (derecha - izquierda)/2;
		
		if(arr[medio]==x){
			return medio;
		}
		if(arr[medio]<x){
			izquierda = medio + 1;
		}else{
			derecha = medio - 1;
		}
	}
	return -1;
}

int main(){
	int arreglo[] = {2,4,6,8,10,12,14,16,18,20};
	int n = sizeof(arreglo)/sizeof(arreglo[0]);
	
	int valorBuscado = 10;
	
	int resultadoLineal = busquedaLineal(arreglo, n, valorBuscado);
	
	if(resultadoLineal== -1){
		printf("Elemento no encontrado en busqueda lineal\n");
	}else{
		printf("Elemento %d encontrado en lineal en el indice %d\n",arreglo[resultadoLineal], resultadoLineal);
	}
	
	resultadoLineal = busquedaBinaria(arreglo, n, valorBuscado);
	
	if(resultadoLineal== -1){
		printf("Elemento no encontrado en busqueda binaria\n");
	}else{
		printf("Elemento %d encontrado en busqueda binaria en el indice %d\n", arreglo[resultadoLineal],resultadoLineal);
	}
}

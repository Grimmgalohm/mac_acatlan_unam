#include <stdio.h>
#include <stdlib.h>

typedef struct Arr{
	int arr[] = {};
}Array;

typedef struct Nodo{
	int dato;
	struct Nodo* siguiente;
}Nodo;

int contador(int i){
	return i;
}

void insertar(Nodo** cabeza, int valor){
	int i;
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	Array* nuevoArray = (Array*)malloc(siezof(Array));
	
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = *cabeza;
	*cabeza = nuevoNodo;
	nuevoArray->arr[contador(i++)] = valor;
}

void eliminar(Nodo** cabeza, int valor){
	Nodo* actual = *cabeza;
	Nodo* previo = NULL;
	
	if(actual==NULL){
		printf("La lista esta vacia\n");
		return;
	}
	
	//cuando el nodo a eliminar es el primero
	if(actual != NULL && actual->dato == valor){
		*cabeza = actual->siguiente;
		free(actual);
		printf("Nodo con valor %d eliminado\n", valor);
		return;
	}
	
	//Buscar el nodo a eliminar
	while(actual!=NULL && actual->dato!=valor){
		previo = actual;
		actual = actual->siguiente;
	}
	
	//si no se encontro el nodo
	if(actual==NULL){
		printf("Nodo con valor %d no encontrado", valor);
		return;
	}
	
	//desenlazar el nodo de la lista y liberar memoria
	previo->siguiente = actual->siguiente;
	free(actual);
	printf("Nodo con el valor %d eliminado\n", valor);
}

void imprimir(Nodo* cabeza){
	Nodo* actual = cabeza;
	while(actual != NULL){
		printf("%d->", actual->dato);
		actual = actual->siguiente;
	}
	printf("NULL\n");
}

int busquedaLineal(int arr[], int n, int x){
	for(i = 0; i<n; i++){
		if(arr[i]==x){
			return i;
		}
	}
	return -1;
}

/*void shellsort(int arr[], int n){
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
}*/

/*oid printArray(int arr[], int n){
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}*/

int main(){
	Nodo* cabeza = NULL;
	
	insertar(&cabeza, 3);
	insertar(&cabeza, 5);
	insertar(&cabeza, 7);
	
	printf("Lista inicial: \n");
	imprimir(cabeza);
	
}

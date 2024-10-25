#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* siguiente;
}Nodo;

void insertar(Nodo** cabeza, int valor){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = valor;
	if(*cabeza == NULL){
		*cabeza = nuevoNodo;
		nuevoNodo->siguiente = nuevoNodo; //apunta a si mismo
	}else{
		Nodo* actual = *cabeza;
		while(actual->siguiente != *cabeza){
			actual = actual->siguiente;
		}
		actual->siguiente = nuevoNodo;
		nuevoNodo->siguiente = *cabeza;
	}
}

void eliminar(Nodo** cabeza, int valor){
	if(*cabeza==NULL){
		printf("La lista está vacía\n");
		return;
	}
	
	Nodo *actual = *cabeza, *previo = NULL;
	if(actual->dato == valor){
		while(actual->siguiente != *cabeza){
			actual = actual->siguiente;
		}
		actual->siguiente=(*cabeza)->siguiente;
		free(*cabeza);
		*cabeza = actual->siguiente;
		printf("Nodo con el valor %d eliminado\n", valor);
		return;
	}
	previo=*cabeza;
	actual = (*cabeza)->siguiente;
	while(actual != *cabeza && actual->dato != valor){
		previo = actual;
		actual = actual->siguiente;
	}
	
	if(actual==*cabeza){
		printf("Nodo con valor %d no encontrado\n", valor);
		return;
	}
	
	previo->siguiente = actual->siguiente;
	free(actual);
	printf("Nodo con el valñor %d eliminado", valor);
}

void imprimir(Nodo* cabeza){
	if(cabeza == NULL) return;
	Nodo* actual = cabeza;
	do{
		printf("%d ->", actual->dato);
		actual = actual->siguiente;
	}while(actual != cabeza);
	printf("Vuelve al inicio\n");
}

int main(){
	Nodo* cabeza = NULL;
	insertar(&cabeza, 10);
	insertar(&cabeza, 20);
	insertar(&cabeza, 30);
	
	printf("Lista inicial: \n");
	
	imprimir(cabeza);
	
	eliminar(&cabeza, 20);
	printf("Lista despues de eliminar el 20\n");
	imprimir(cabeza);
	
	//Intentar eliminar algo que no existe
	printf("Eliminando un eleemento que no existe:\n");
	eliminar(&cabeza, 50);
	return 0;
}

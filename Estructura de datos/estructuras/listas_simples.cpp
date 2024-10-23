#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* siguiente;
}Nodo;

void insertar(Nodo** cabeza, int valor){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = *cabeza;
	*cabeza = nuevoNodo;
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

int main(){
	Nodo* cabeza = NULL;
	insertar(&cabeza, 3);
	insertar(&cabeza, 5);
	insertar(&cabeza, 7);
	
	printf("Lista inicial: \n");
	imprimir(cabeza);
	
	eliminar(&cabeza, 5);
	printf("Lista despues de eliminar el 5: \n");
	imprimir(cabeza);
	
	//Intentar eliminar algo que no existe
	printf("Eliminando un elemento que no existe:\n");
	eliminar(&cabeza, 10);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* siguiente;
	struct Nodo* anterior;
}Nodo;

void insertar(Nodo** cabeza, int valor){
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = *cabeza;
	nuevoNodo->anterior = NULL;
	
	if(*cabeza != NULL){
		(*cabeza)->anterior=nuevoNodo;
	}
	
	*cabeza = nuevoNodo;
}

void eliminar(Nodo** cabeza, int valor){
	Nodo* actual = *cabeza;
	
	//Buscar el nodo a eliminar
	while(actual!=NULL && actual->dato != valor){
		actual = actual->siguiente;
	}
	
	//si no se encontró el nodo
	if(actual == NULL){
		printf("Nodo con valor %d No encontrado\n", valor);
		return;
	}
	
	//si el nodo a eliminar es la cabeza
	if(actual == *cabeza){
		*cabeza = actual->siguiente;
	}
	
	//actualizar el nodo anterior
	if(actual->anterior != NULL){
		actual->anterior->siguiente = actual->siguiente;
	}
	
	//actualizar el nodo siguiente
	if(actual->siguiente != NULL){
		actual->siguiente->anterior = actual->anterior;
	}
	
	free(actual);
	printf("Nodo con el valor %d eliminado\n",valor);
}

void imprimir(Nodo* cabeza){
	Nodo* actual = cabeza;
	printf("NULL <->");
	while(actual != NULL){
		printf("%d <->", actual->dato);
		actual = actual->siguiente;
	}
	printf("NULL\n");
}

int main(){
	Nodo* cabeza = NULL;
	insertar(&cabeza, 2);
	insertar(&cabeza, 4);
	insertar(&cabeza, 6);
	
	printf("Listia inicial: \n");
	imprimir(cabeza);
	
	eliminar(&cabeza, 4);
	printf("La lista despues de eliminar a 4\n");
	imprimir(cabeza);
	
	printf("Intentar eliminar 10\n");
	imprimir(cabeza);
}

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo* izquierdo;
	struct Nodo* derecho;
};

struct Nodo* crearNodo(int dato){
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->izquierdo = NULL;
	nuevoNodo->derecho = NULL;
	return nuevoNodo;
}

void preorden(struct Nodo* nodo){
	if(nodo == NULL) return;
	printf("%d", nodo->dato); //primero se visita la raiz
	preorden(nodo->izquierdo); //luego el sub-arbol izquierdo
	preorden(nodo->derecho); //luego el sub-arbol derecho
}

void inorden(struct Nodo* nodo){
	if(nodo == NULL) return;
	inorden(nodo->izquierdo); //Primero se visita el arbol izquierdo
	printf("%d", nodo->dato); //luego visitamos la raiz
	inorden(nodo->derecho); //finalmente el sub-arbol derecho
}

void postorden(struct Nodo* nodo){
	if(nodo == NULL) return;
	postorden(nodo->izquierdo); //primero sub-arbol izquierdo
	postorden(nodo->derecho); //luego subarbol derecho
	printf("%d", nodo->dato); //finalmente la raíz
}

int main(){
	struct Nodo* raiz = crearNodo(1);
	
	raiz->izquierdo = crearNodo(2);
	raiz->derecho = crearNodo(3);
	raiz->izquierdo->izquierdo = crearNodo(4);
	raiz->izquierdo->derecho = crearNodo(5);
	raiz->derecho->izquierdo = crearNodo(6);
	raiz->derecho->derecho = crearNodo(7);
	raiz->derecho->izquierdo->izquierdo = crearNodo(8);
	raiz->derecho->izquierdo->derecho = crearNodo(9);
	
	printf("recorrido en preorden\n");
	preorden(raiz);
	printf("\n");
	
	printf("recorrido en inorden\n");
	inorden(raiz);
	printf("\n");
	
	printf("recorrido en postorden\n");
	postorden(raiz);
	printf("\n");
	
	return 0;
}

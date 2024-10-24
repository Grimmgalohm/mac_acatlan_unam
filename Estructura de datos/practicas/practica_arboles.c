/*
	Genera un programa en C que permita
	- Recorrer en postorden
	- Recorrer en inorden
	- Recorrer en preorden
	- Calcular la suma de los nodos (valor dentro del nodo)
	- Contar el numero de nodos
	- Salir
*/

#include <stdio.h>
#include <stdlib.h>

int suma;

typedef struct Nodo{
	int dato;
	struct Nodo* left;
	struct Nodo* right;
}Nodo;

struct Nodo* crearNodo(int dato){
	Nodo* newNodo = (Nodo*)malloc(sizeof(struct Nodo));
	
	newNodo->dato = dato;
	newNodo->left = NULL;
	newNodo->right = NULL;
	
	return newNodo;
}

void preorden(struct Nodo* nodo){
	if(nodo == NULL) return;
	printf("%d", nodo->dato);
	preorden(nodo->left);
	preorden(nodo->right);
}

void inorden(struct Nodo* nodo){
	if(nodo == NULL) return;
	inorden(nodo->left);
	printf("%d", nodo->dato);
	inorden(nodo->right);
}

void postorden(struct Nodo* nodo){
	if(nodo == NULL) return;
	postorden(nodo->left);
	postorden(nodo->right);
	printf("%d", nodo->dato);
}

int sumador(struct Nodo* nodo){
	if(nodo == NULL) return 0;
	sumador(nodo->left);
	sumador(nodo->right);
	suma = suma + (int)nodo->dato;
	return suma;
}

int contador(struct Nodo* nodo){
	if(nodo == NULL) return 0;
	contador(nodo->left);
	contador(nodo->right);
	suma++;
	return suma;
}

int main(){
	int opt;
	
	Nodo* raiz = crearNodo(4);
	raiz->left = crearNodo(5);
	raiz->right = crearNodo(6);
	raiz->right->left = crearNodo(5);
	
	do{
		
		printf("\nQue buscas hacer?\n");
		printf("[1]recorrer en postorden [2] recorrer en inorden [3] recorrer en preorden [4] Suma de nodos [5] suma de datos [0] salirme yaaaaa~");
		scanf("%d", &opt);
		switch(opt){
			case 0:
				return 0;			
			case 1:
				postorden(raiz);
				break;
			case 2:
				inorden(raiz);
				break;
			case 3:
				preorden(raiz);
				break;
			case 4:
				printf("%d", sumador(raiz));
				break;
			case 5:
				printf("%d",contador(raiz));
				break;
			default:
				system("cls");
				main();
				break;
		}
	}while(opt>0);
	
	return 0;
}

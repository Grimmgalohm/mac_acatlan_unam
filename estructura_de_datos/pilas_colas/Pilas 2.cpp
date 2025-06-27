#include<stdio.h>
#include<stdlib.h>

struct nodo{
	int dato;
	struct nodo* siguiente;
};
struct nodo* nuevoNodo(int valor){
	struct nodo* nodo=(struct nodo*)malloc (sizeof (struct nodo));
	nodo->dato=valor;
	nodo->siguiente=NULL;
	return nodo;
}
int esVacia(struct nodo* tope){
	return !tope;
}
void push(struct nodo** tope, int valor){
	struct nodo* nodo = nuevoNodo(valor);
	nodo->siguiente = *tope;
	*tope = nodo;
	printf("\n%d agregado a la pila", valor);
}

int pop(struct nodo** tope){
	if(esVacia(*tope)){
		printf("Error esta vacia");
		return -1;
	}
	else{
		struct nodo* temp = *tope;
		*tope = (*tope)->siguiente;
		int eliminado = temp->dato;
		free(temp);
		return eliminado;
	}
}

int peek(struct nodo* tope){
	if(esVacia(tope)){
		printf("\nError esta vacia");
		return -1;
	}
	else{
		return tope->dato;
	}
}

int main(){
	struct nodo* tope = NULL;
	push(&tope, 10);
	push(&tope, 20);
	push(&tope, 30);
	
	printf("\nElemento superior %d\n",peek(tope));
	printf("Elemento eliminado %d\n",pop(&tope));
	printf("Elemento eliminado %d\n",pop(&tope));
	printf("Elemento superior %d\n",peek(tope));
	
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
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
int evaluarPostfija(char* expresion){
	struct nodo* tope=NULL;
	int i=0;
	while(expresion[i]!='\0'){
		if(isdigit(expresion[i])){
			int num = expresion[i]-'0';
			push(&tope,num);
		}else{
			int val2=pop(&tope);
			int val1=pop(&tope);
			switch(expresion[i]){
				case'+': push(&tope, val1 + val2);
				case'-': push(&tope, val1 - val2);
				case'/': push(&tope, val1 / val2);
				case'*': push(&tope, val1 * val2);
			}
		}
		i++;
	}
	return pop(&tope);
}

int main(){
	char expresion [10];
	printf("Ingrese un exepresion posfija: ");
	fflush(stdin);
	scanf("%s",expresion);
	int resultado = evaluarPostfija(expresion);
	printf("Resultado es: %d \n",resultado);
									 
return 0;
}

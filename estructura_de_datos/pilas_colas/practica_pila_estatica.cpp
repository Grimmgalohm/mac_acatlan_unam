#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/*
	Practica de una pila estatica de tipo fijo
*/
int pila[MAX], tope = -1;

/*
	Este metodo ingresa el tipo de dato a la pila
	Si la pila se encuentra llena, solo retorna
*/
void push(int i){
	if(tope == MAX-1){
		printf("La pila está llena");
		return;
	}
	pila[++tope]=i;
}



void pop(){
	if(tope==-1){
		printf("La pila está vacía.");
		return;
	}
	tope--;
	return pila[tope];
}

int main(){
	scanf("");
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int pila[MAX];
int tope=-1;
int esLlena(){
	return tope==MAX-1;
}
int esVacia(){
	return tope==-1;
}
void push(int valor ){
	if(esLlena()){
		printf("Error la pila esta llena");
	}else{
		pila[++tope]=valor;
		printf("\n %d arregado a la pila",valor);
	}
}
int pop(){
	if(esVacia()){
			printf("Error la pila esta Vacia");
			return -1;
	}else{
		return pila[tope--];
	}
}
int peek(){
	if(esVacia()){
			printf("Error la pila esta Vacia");
			return -1;
	}else{
		return pila[tope];
	}
}
int main(){
	push(10);
	push(20);
	push(30);
	printf("\nElemento superior %d\n",peek());
	printf("Elemento eliminado %d\n",pop());
	printf("Elemento eliminado %d\n",pop());
	printf("Elemento superior %d\n",peek());
}

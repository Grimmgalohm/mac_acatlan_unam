#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
/*
	No quiero hacer nada y me voy a poner a practicar xd
*/
char pila[MAX], cola[MAX];
int tope=-1, rear=-1, front=-1;

//Metodos de ingreso en pila y cola
void push(char c){
	if(tope == MAX-1){
		printf("La pila est� llena\n");
		return;
	}
	pila[++tope]=c;
	printf("%c a�adido a la pila\n", pila[tope]);
}

void enqueue(char c){
	if(rear==MAX-1){
		printf("La cola est� llena");
		return;
	}else{
		if(front==-1)front=0;
		rear++;
		cola[rear]=c;
		printf("%c a�adido a la cola", cola[rear]);
	}
}

//Metodos para eliminar elementos de la pila y la cola
//No s� si realmente voy a usar estos dos m�todos... pero los voy a dejar
char pop(){
	if(tope==-1){
		printf("La pila est� vac�a");
	}
	tope--;
	printf("%c", pila[tope]);
	return pila[tope];
}

char dequeue(){
	if(rear == -1 || front>rear){
		printf("La cola est� vacia �w� \n");
	}
	rear--;
	printf("%c", cola[rear]);
	return cola[rear];
}

int main(){
	
	char c[MAX];
	int i;
	
	scanf("%s", &c);
	
	for(i=0; i<strlen(c); i++){
		push(c[i]);
	}
	
	printf("%c",pila[0]);
	
	return 0;
}

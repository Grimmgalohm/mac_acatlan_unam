#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
	char preguntaORespuesta[100];
	struct Nodo* izquierdo; //Respuesta Si
	struct Nodo* derecho; //Respuesta No
};

struct Nodo* crearNodo(char* texto){
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	strcpy(nuevoNodo->preguntaORespuesta, texto);
	nuevoNodo->izquierdo = NULL;
	nuevoNodo->derecho = NULL;
	return nuevoNodo;
}

void jugar(struct Nodo* nodo){
	
	char respuesta[3];
	
	if(nodo->izquierdo == NULL && nodo->derecho == NULL){
		printf("Estas pensando en %s? (si/no)", nodo->preguntaORespuesta);
		scanf("%s", respuesta);
		if( strcmp(respuesta, "si") == 0 ){
			printf("He adivinado el animal\n");
		}else{
			char nuevoAnimal[100];
			char nuevaPregunta[100];
			
			printf("OH!, no pude adivinar, cual es el animal?: \n");
			scanf(" %[^\n]", nuevoAnimal);
			
			printf("Dame una pregunta que sea verdadera para %s pero falsa para %s", nuevoAnimal, nodo->preguntaORespuesta);
			scanf(" %[^\n]", nuevaPregunta);
			
			struct Nodo* animalAnterior = crearNodo(nodo->preguntaORespuesta);
			struct Nodo* nuevoAnimalNodo = crearNodo(nuevoAnimal);
			
			strcpy(nodo->preguntaORespuesta, nuevaPregunta);
			nodo->izquierdo = nuevoAnimalNodo;
			nodo->derecho = animalAnterior;
			
		}
		return;
	}
	
	//Si no es una hoja es una pregunta
	printf("%s (Si/No)", nodo->preguntaORespuesta);
	scanf("%s", respuesta);
	if(strcmp(respuesta,"si") ==0 ){
		jugar(nodo->izquierdo);
	}else{
		jugar(nodo->derecho);
	}
}

void liberarArbol(struct Nodo* nodo){
	if(nodo == NULL) return;
	liberarArbol(nodo->izquierdo);
	liberarArbol(nodo->derecho);
	free(nodo);
}

int main(){
	
	struct Nodo* raiz = crearNodo("Es un mamifero?");
	raiz->izquierdo = crearNodo("perro");
	raiz->derecho = crearNodo("Aguila");
	
	printf("Juego para adivinar animales\n");
	char continuar = 's';
	while(continuar == 's'){
		jugar(raiz);
		printf("Quieres jugar de nuevo?");
		scanf(" %c", &continuar);
	}
	
	liberarArbol(raiz);	
	printf("Gracias por jugar\n");
	return 0;
	
}

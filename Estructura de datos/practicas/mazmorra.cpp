#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Code asssitance para errores en el codigo :3

typedef struct Mazmorra{
	int tipo;
	struct Mazmorra* siguiente;
	struct Mazmorra* anterior;
}Mazmorra;

Mazmorra* crearMazmorra(int tipo){
	Mazmorra* nuevaMazmorra = (Mazmorra*)malloc(sizeof(Mazmorra));
	nuevaMazmorra->tipo = tipo;
	nuevaMazmorra->siguiente = NULL;
	nuevaMazmorra->anterior = NULL;
	return nuevaMazmorra;
};

void agregarMazmorra(Mazmorra** inicio, Mazmorra** fin, int tipo){
	Mazmorra* nuevaMazmorra = crearMazmorra(tipo);
	if(*inicio == NULL){
		*inicio = *fin = nuevaMazmorra;
	}else{
		(*fin)->siguiente = nuevaMazmorra;
		nuevaMazmorra->anterior = *fin;
		*fin = nuevaMazmorra;
	}
}

void mostrarMazmorras(Mazmorra* inicio){
	Mazmorra* actual = inicio;
	int indice = 1;
	while(actual != NULL){
		printf("MAzmorra %d Tipo %d\n", indice ++, actual->tipo);
		actual = actual->siguiente;
	}
}

Mazmorra* retrocederMazmorras(Mazmorra* actual, int n){
	int i;
	actual->tipo =0;
	for(i=0; i<n && actual->anterior != NULL; i++){
		actual = actual->anterior;
	}
	return actual;
}

Mazmorra* avanzarMazmorras(Mazmorra* actual, int n){
	int i;
	actual->tipo = 0;
	for(i=0; i<n && actual->siguiente != NULL; i++){
		actual = actual->siguiente;
	}
	return actual;
}

int main(){
	srand(time(NULL));
	int vida = 100, i;
	
	int numMazmorras = rand() % 20 + 5;
	Mazmorra *inicio = NULL, *fin = NULL;
	
	//crear N mazmorras
	for(i=0; i<numMazmorras; i++){
		int tipo = rand() % 5 + 1;
		agregarMazmorra(&inicio, &fin, tipo);
	}
	
	printf("Bienvenido al juego de mazmorras\n");
	mostrarMazmorras(inicio);
	
	Mazmorra * actual = inicio;
	int paso = 1;
	while(vida>0 && actual !=NULL){
		printf("\nPaso %d; Te encuentras en la mazmorra de tipo %d, Vida actual: %d\n", paso++, actual->tipo,vida);
		
		switch(actual->tipo){
			case 1:
				printf("No pasa nada\n");
				break;
			case 2:
				vida -= 10;
				printf("Pierdes 10 puntos de vida\n");
				break;
			case 3:
				vida += 10;
				printf("Ganas 10 puntos de vida\n");
				break;
			case 4:{
				int n = rand()%3+1;
				printf("Retrocede %d mazmorras.\n", n);
				actual = retrocederMazmorras(actual, n);
				continue;
			}
			case 5: int n = rand()%3+1;
				printf("avanza %d mazmorra.\n", n);
				actual = avanzarMazmorras(actual, n);
				continue;
		}
		actual = actual->siguiente;
	}
	if(vida <= 0){
		printf("\n Game Over");
	}else{
		printf("Terminaste todas las mazmorras con %d de vida\n", vida);
	}
	
	while(inicio != NULL){
		Mazmorra* temp = inicio;
		inicio = inicio->siguiente;
		free(temp);
	}
	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cards{
	int id;
	char titulo;
	char descripcion;
	int prioridad;
	struct Cards* siguiente;
};

struct Cards createCard(int id, char titulo, char descripcion, int prioridad){
	struct Cards* newCard = (struct Cards*)malloc(sizeof(struct Cards));
	newCard->id = id;
	newCard->titulo = titulo;
	newCard->descripcion = descripcion;
	newCard->prioridad = prioridad;
	newCard->siguiente = NULL;
	
	return newCard;
};

void push(struct Cards* tope, int id, char titulo, char descripcion, int prioridad){
	struct Cards* newCard = createCard(id, titulo, descripcion, prioridad);
	
	newCard->siguiente = *tope;
	*tope = newCard;
	
	printf("Tarjeta '%s' añadida.", tope->titulo);
}

void menuRegistrarTarjeta(){
	printf("Solo un nuevo menu");
}

void menuPrincipal(){
	int opt;
	
	printf("==================================================\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|                  To-Do List                    |\n");
	printf("|                                                |\n");
	printf("|   Presiona una de las opciones para empezar    |\n");
	printf("==================================================\n");
	printf("\n\n");
	printf("[1] Registrar nueva tarjeta\n");
	printf("[2] Listar tarjetas\n");
	printf("[0] Salir\n");

	scanf("%d", &opt);
	
	switch(opt){
		case 0:
			return;
		case 1:
			printf("");
			break;
		case 2:
			printf("xd2");
			break;
		default:
			system("cls");
			menuPrincipal();
	}
}

int main(){
	
	menuPrincipal();
	
	return 0;
}

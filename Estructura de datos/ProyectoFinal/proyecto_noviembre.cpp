#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TTL 150
#define DSC 500

void menuRegistrarTarjeta();
void menuPrincipal();
void push();

struct Tarjeta{
	char titulo[TTL];
	char descripcion[DSC];
	int prioridad;
	struct Tarjeta* siguiente;
};

struct Tarjeta* crearTarjeta(char titulo[TTL], char descripcion[DSC], int prioridad){
	
	struct Tarjeta* nuevaTarjeta = (struct Tarjeta*)malloc(sizeof(struct Tarjeta));
	
	nuevaTarjeta->titulo[TTL] = titulo[TTL];
	nuevaTarjeta->descripcion[DSC] = descripcion[DSC];
	nuevaTarjeta->prioridad = prioridad;
	nuevaTarjeta->siguiente = NULL;
	
	return nuevaTarjeta;
};


void push(struct Tarjeta** tope, char titulo[TTL], char descripcion[DSC], int prioridad){
	
	struct Tarjeta* nuevaTarjeta = crearTarjeta(titulo, descripcion, prioridad);
	
	nuevaTarjeta->siguiente = *tope;
	
	*tope = nuevaTarjeta;
	
	printf("Tarjeta '%s' añadida.", nuevaTarjeta->titulo);
	
}

void registrarTarjeta(){
	struct Tarjeta* tope = NULL;
	char titulo[TTL], descripcion[DSC];
	int prioridad, opt;
	do{
		
		printf("Escribe el titulo: \n");
		fgets(titulo, sizeof(titulo), stdin);
		fflush(stdin);
		printf("Descripcion:\n");
		fgets(descripcion, sizeof(descripcion), stdin);
		printf("Prioridad: [1] Trivial, [2] Baja, [3] Media, [4] Alta [5] Bloqueante");
		scanf("%d", &prioridad);
		   
		push(&tope, titulo, descripcion, prioridad);
		
		printf("Titulo: %s", titulo);
		printf("Descripción:\n");
		printf("%s", descripcion);
		printf("Prioridad: %d", prioridad);
		
		printf("Añadir nueva tarjeta?\n");
		printf("[1]Si / [2]No\n");
		
		scanf("%d", &opt);
	}while(opt!=2);
}

void menuRegistrarTarjeta(){
	int opt;
	system("cls");
	printf("==================================================\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|                  To-Do List                    |\n");
	printf("|                                                |\n");
	printf("|   Presiona una de las opciones para continuar  |\n");
	printf("==================================================\n");
	printf("\n\n");
	printf("[1] Nueva tarjeta\n");
	printf("[2] Editar tarjeta\n");
	printf("[0] Atrás\n");

	scanf("%d", &opt);
	
	switch(opt){
		case 0:
			menuPrincipal();
			break;
		case 1:
			registrarTarjeta();
			break;
		case 2:
			printf("Editar una tarjeta xd");
			break;
		default:
			system("cls");
			menuRegistrarTarjeta();
	}
	
}

void menuPrincipal(){
	int opt;
	system("cls");
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
	fflush(stdin);
	
	switch(opt){
		case 0:
			return;
		case 1:
			menuRegistrarTarjeta();
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

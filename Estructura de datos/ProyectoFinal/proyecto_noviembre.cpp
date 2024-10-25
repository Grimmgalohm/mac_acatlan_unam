#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuRegistrarTarjeta();
void menuPrincipal();

struct Tarjeta{
	int id;
	char titulo;
	char descripcion;
	int prioridad;
	struct Tarjeta* siguiente;
};

struct Tarjeta* crearTarjeta(int id, char titulo, char descripcion, int prioridad){
	
	struct Tarjeta* nuevaTarjeta = (struct Tarjeta*)malloc(sizeof(struct Tarjeta));
	
	nuevaTarjeta->id = id;
	nuevaTarjeta->titulo = titulo;
	nuevaTarjeta->descripcion = descripcion;
	nuevaTarjeta->prioridad = prioridad;
	nuevaTarjeta->siguiente = NULL;
	
	return nuevaTarjeta;
};

void push(struct Tarjeta** tope, int id, char titulo, char descripcion, int prioridad){
	
	struct Tarjeta* nuevaTarjeta = crearTarjeta(id, titulo, descripcion, prioridad);
	
	nuevaTarjeta->siguiente = *tope;
	
	*tope = nuevaTarjeta;
	
	printf("Tarjeta '%s' añadida.", nuevaTarjeta->titulo);
	
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
			fflush(stdin);
			break;
		case 1:
			printf("Agregar nueva tarjeta :D");
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
			fflush(stdin);
			break;
		case 2:
			fflush(stdin);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cards{
	int id;
	char titulo;
	char descripcion;
	int prioridad;
	struct Cards* siguiente;
	struct Cards* anterior;source
}Card;

struct Cards createCard(){
	
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
			printf("xd");
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

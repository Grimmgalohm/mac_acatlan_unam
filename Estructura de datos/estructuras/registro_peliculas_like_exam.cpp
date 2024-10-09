/*
	¿Registro de peliculas?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
	ACCION,
	COMEDIA,
	TERROR,
	SUSPENSO,
	FICCION
}Generos;

typedef enum{
	A,
	AA,
	B,
	B15,
	C,
	D
}Clasificacion;

typedef struct
{
	char titulo[50];
	int duracion;
	Generos genero;
	Clasificacion clasificacion;
}Peliculas;

const char* obtenerGenero(Generos genero){
	switch (genero){
		case ACCION: return "Accion";
		case COMEDIA: return "Comedia";
		case TERROR: return "Terror";
		case SUSPENSO: return "Suspenso";
		case FICCION: return "Ficcion";
		default: return "Desconocido";
	}
}

const char* obtenerClasificacion(Clasificacion clasificacion){
	switch (clasificacion){
		case A: return "A";
		case AA: return "AA";
		case B: return "B";
		case B15: return "B15";
		case C: return "C";
		case D: return "D";
		default: return "Desconocido";
	}
}

void ingresaPelicula(Peliculas *pelicula){
	printf("\nTitulo:");
	scanf("%s", pelicula->titulo);
	printf("\nduracion:");
	scanf("%d", &pelicula->duracion);
	printf("\nGeneros: 0: Accion, 1: Comedia, 2: Terror, 3: Suspenso, 4: Ficcion");
	scanf("%d", (int*)&pelicula->genero);
	printf("\nClasificacion: 0: A, 1: AA, 2: B, 3: B15, 4: C, 5: D");
	scanf("%d", (int*)&pelicula->clasificacion);
}

void mostrarPeliculas(Peliculas pelicula){
	printf("Titulo: %s", pelicula.titulo);
	printf("Duracion %d", pelicula.duracion);
	printf("Genero: %s", obtenerGenero(pelicula.genero));
	printf("Clasificacion: %s", obtenerClasificacion(pelicula.clasificacion));
}

int main(){
	int i, j;
	Peliculas *peliculas = (Peliculas*)malloc(2*sizeof(Peliculas));
	
	if(peliculas==NULL){
		printf("Error en la asignacion de memoria");
		return 1;
	}
	
	do{
		i++;
		printf("Ingresa los datos de las peliculas\n");
		ingresaPelicula(&peliculas[i]);
	}while(i!=2);
	
	printf("Catalogo de peliculas");
	for(j=0; j<2; j++){
		printf("Pelicula %d", j+1);
		mostrarPeliculas(peliculas[j]);
	}
	
	free(peliculas);
	return 0;
}

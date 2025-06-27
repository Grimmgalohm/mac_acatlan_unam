#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Una estructura
typedef struct Persona{
	int id;
	int edad;
	char nombre[50];
	char apellido[50];
}Person;

Persona createPersona(int id, int edad, char nombre[50], char apellido[50]){
	Persona p;
	
	p.id = id;
	p.edad = edad;
	strcpy(p.nombre, nombre);
	strcpy(p.apellido, apellido);
	
	return p;	
	
}

void imprimir(Persona p){
	printf("ID: %d \n",p.id);
	printf("Nombre: %s %s \n",p.nombre, p.apellido); 
	printf("Edad: %d \n",p.edad);
	
	return;
}

int main(){
	int id, edad; 
	char nombre[50], apellido[50];
	
	printf("Ingresa el id \n");
	scanf("%d", &id);
	printf("Ingresa la edad: \n");
	scanf("%d", &edad);
	printf("Ingresa el nombre \n");
	scanf("%s", &nombre);
	//fgets(apellido, 50, stdin);
	printf("Ingresa el apellido \n");
	scanf("%s", &apellido);
	//fgets(apellido, 50, stdin);
	
	Persona p = createPersona(id, edad, nombre, apellido);
	
	imprimir(p);
	
	return 0;
}



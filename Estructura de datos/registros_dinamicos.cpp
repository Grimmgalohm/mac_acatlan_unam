//Registro dinamico
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Empleado
{
	int id;
	char nombre[50];
	float salario;
};

int main()
{
	struct Empleado* empleados = (struct Empleado*)malloc(3 * sizeof(struct Empleado));
	//struct Empleado* empleados = malloc(3 * sizeof(struct Empleado));

	
	if(empleados == NULL ){
		printf("Error al asignar memoria");
		return 1;
	}
	
	empleados[0].id = 1;
	strcpy(empleados[0].nombre, "Juan");
	empleados[0].salario = 1500.50;
	
	empleados[1].id = 2;
	strcpy(empleados[1].nombre, "Maria");
	empleados[1].salario = 2200.50;
	
	empleados[2].id = 3;
	strcpy(empleados[2].nombre, "Pedro");
	empleados[2].salario = 1100.50;
	
	printf("ID\tNombre\tSalario\n");
	
	for(int i=0;i<3;i++){
		printf("%d\t%s\t\t%.2f\n", empleados[i].id, empleados[i].nombre, empleados[i].salario);
	}
	
	free(empleados);
	
	return 0;
	
		
}

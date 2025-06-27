#include <stdio.h>
#include <stdlib.h>
#define MAX 50
//Memoria dinamica con malloc y realloc... o algo así era.



int main(){
	int item,contador,resp, i;
	//definimos el puntero
	int *arreglo;
	//asignamos el arreglo a un puntero declarado anteriormente
	//el puntero   |le asignamos la        |Se asigna la memoria
	//             |dirección de memoria   |del tamaño que necesita un int
	arreglo=(int*)malloc(sizeof(int));
	if(arreglo == NULL){
		printf("error al asignar memoria al puntero");
		return 0;
	}
	
	do{
		printf("Ingresa otro número al arreglo");
		scanf("%d", item);
		arreglo = (int*)realloc(item,(contador+1)*sizeof(int));
		printf("¿Quieres ingresar otro?");
		scanf("%d", resp);
		
		if(resp==0){
			for(i, i<sizeof(arreglo), i++){
				printf("%d", item[i]);
			}
		}
			
	}while(resp == 1);
	
	return 0;
	
}

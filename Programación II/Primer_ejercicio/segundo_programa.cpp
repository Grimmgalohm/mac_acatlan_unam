#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LEN 5

void session_time(time_t tini);
void converter(int opc);

int main(){
	//Para el contador
	time_t tini, tfin;
    tini = time(NULL);
    int opc=NULL;
    
    do{
		printf("Bienvenido al convertidor de divisa\n");
		printf("Ingresa la opcion de conversion\n");
		printf("1 - Convertir de: MXN a USD\n");
		printf("2 - Convertir de: USD a MXN\n");
		printf("0 - Para salir, oprima 0\n");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				converter(opc);
				break;
			case 2:
				converter(opc);
				break;
			case 0:
				system("cls");
    			session_time(tini);
				return 0;
				break;
			default:
				main();	
		}
		
	}while(opc == 0);
	
	system("cls");
    session_time(tini);
	return 0;
}

//Funcion que evalua el tiempo de sesión del usuario dentro del programa.
void session_time(time_t tini){
    time_t tfin = time(NULL);

    printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
	printf("\n timepo de salida %s", asctime(localtime(&tfin)));
	printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
}

void converter(int opc){
	char dnamei[LEN], dnamel[LEN];
	int repeat;
	float input, output, local;
	do{
		switch(opc){
			case 1:
				strcpy(dnamei,"MXN");
				strcpy(dnamel,"USD");
				local = 19.84496;
				break;
			case 2:
				strcpy(dnamei,"USD");
				strcpy(dnamel,"MXN");
				local = 0.0503;
				break;
			default:
				printf("Mala opcion. Intenta de nuevo\n");
				main();
		};
		
		printf("Ingresa la cantidad en %s (Sin signo. Puedes usar decimales)\n",dnamei);
		scanf("%f",&input);
		output=input/local;
		printf("------------------------\n");
		printf("|\n| %f %s --> %s = %f |\n|",input,dnamei,dnamel,output);
		printf("------------------------\n");
		printf("¿Quieres convertir otra cantidad?\n");
		scanf("%d", &repeat);
		system("cls");
	}while(repeat==1);
	system("cls");
	printf("\n\nBye!\n\n");
	system("pause");
	return;
}

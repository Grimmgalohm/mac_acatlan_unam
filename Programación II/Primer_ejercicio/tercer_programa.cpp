#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void session_time(time_t tini){
    time_t tfin = time(NULL);

    printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
	printf("\n tiempo de salida %s", asctime(localtime(&tfin)));
	printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
}

int main(){
	//Para el contador
	time_t tini, tfin;
    tini = time(NULL);
    
    //configurar la semilla para generar números aleatorios.
    srand(time(NULL));
    
    //Crea el número con rango máximo de 100
    int magicNumber=rand()%101;
    
    int lifePoints=3, answer, tryAgain;
    	
    printf("Número mágico: %d", magicNumber);
    
    do{
    	
    	printf(" --------------------------------- \n");
    	printf("|        Adivina el número.       |\n"):
    	printf(" --------------------------------- \n");
    	printf("Presiona 1 para jugar.\n");
    	printf("Presiona 0 para salir del programa.\n");
    	scanf("%d", &tryAgain)
    	
		if(tryAgain!=0){
			system("cls");
			printf("Estoy pensando en un número entero entre el 0 y el 100\n");
			printf("Adivinas cual es?\n");
			printf("Respuesta: ");
			scanf("%d", &answer);	
		}
		
		printf("Quieres jugar otra vez? \n");
		scanf("%d", &tryAgain);
				
	}while(tryAgain != 1 );
	
    session_time(tini);
	return 0;
}

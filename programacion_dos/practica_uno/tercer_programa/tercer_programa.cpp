#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void session_time(time_t tini){
    time_t tfin = time(NULL);

    printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
	printf("\n tiempo de salida %s", asctime(localtime(&tfin)));
	printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
}

void game(){
	
	//configurar la semilla para generar números aleatorios.
    srand(time(NULL));
    
    //Crea el número con rango máximo de 100
    int magicNumber=rand()%101;
    
    system("cls");
    
    printf("Número mágico: %d", magicNumber);
    
}

int main(){
	//Para el contador
	time_t tini;
    tini = time(NULL);
    
    int lifePoints=3, answer, tryAgain, exit=1;
    
    do{
    	
    	printf(" --------------------------------- \n");
    	printf("|        Adivina el número.       |\n");
    	printf(" --------------------------------- \n");
    	printf("Presiona 1 para jugar.\n");
    	printf("Presiona 0 para salir del programa.\n");
    	scanf("%d", &tryAgain);
    	
		switch(tryAgain){
			case 1:
				break;
				
			case 0:
				exit = 0;
				break;
				
			default:
				exit = 1;
		}
		
		printf("Quieres jugar otra vez? \n");
		scanf("%d", &tryAgain);
				
	}while(exit == 1);
	
    session_time(tini);
	return 0;
}

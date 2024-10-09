#include <stdio.h>
#include <stdlib.h>

void session_time(time_t tini){
    time_t tfin = time(NULL);

    printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
	printf("\n timepo de salida %s", asctime(localtime(&tfin)));
	printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
}

int main(){
	//Para el contador
	time_t tini, tfin;
    tini = time(NULL);
    
    int lifePoints=3, answer,tryAgain;
    
    printf("Bienvenido a: adivina el numero\n");
    
    do{
    	if()
    	int magicNumber=rand()%101;
    	printf("\n\nIntentos:")
    	printf("Adivina, adivina...\n");
    	printf("¿Cual es el numero magico? (Pista: es un entero positivo del 0 al 100 :v)\n");
    	scanf("%d", &answer);
    	
    	if(answer==maginNumber){
    		
		}else{
			lifePoints--;
			
		}
    	
	}while(lifePoints == 0 && tryAgain == 0);
	
	system("cls");
    session_time(tini);
	return 0;
}



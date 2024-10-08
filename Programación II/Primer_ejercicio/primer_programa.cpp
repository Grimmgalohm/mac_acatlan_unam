#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void get_data(){
    double volumen, area, radio, altura;
    system("cls");
    printf("Bienvenido a la calculadora de volumen y area de un cilindro");
    printf("\nIngresa los siguientes datos: Radio del cilindro\n");
    scanf("%lf", &radio);
    printf("\nIngresa los siguientes datos: Altura del cilindro\n");
    scanf("%lf", &altura);
    volumen = 3.1416*(pow(radio,2)*altura);
    area = 2*(3.1416*(radio*(radio+altura)));
    
    printf("\nEl area del cilindro es: %lf\n",area);
    printf("\nEl volumen del cilindro es: %lf\n",volumen);
    
    system("pause");
    
}

void session_time(time_t tini){
    time_t tfin = time(NULL);

    printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
	printf("\n timepo de salida %s", asctime(localtime(&tfin)));
	printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
}

int main(){
    int opt;
    time_t tini, tfin;
    tini = time(NULL);

    do{
        get_data();
        system("cls");
        printf("¿Quieres calcular otro cilindro?\n");
        printf("[Yes = 1](Digita 1) [No = 0](Digita 0)\n");
        scanf("%i", &opt);

    }while(opt==1);

    system("cls");
    session_time(tini);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void session_time(time_t tini){
  time_t tfin = time(NULL);
  
  printf("Tiempo de inicio:\n%s\n", asctime(localtime(&tini)));
  printf("Tiempo de salida:\n%s\n", asctime(localtime(&tfin)));
  printf("Tiempo de permanencia en el sistema: \n%.2f seg\n", difftime(tfin, tini));
}

int magicNumberGenerator(){
  srand(time(NULL));
  return rand() % (100 + 1);
}

void playGame(){
  printf("\033[2J\033[H");
  int magicNumber = magicNumberGenerator(), answer, intents;
  bool surrender;
  char higher[6]="mayor",lower[6]="menor";

  printf("\t\tJuguemos!\nPara responder ingresa el numero entero que crees es el numero magico\n");
  printf("Para rendirte y salir, ingresa -1 como respuesta\n");
  
  do{
    system("clear");
    
    printf("Adivina el numero magico...\nEl numero magico es...\n");
    do{
      system("clear");
      scanf("%d", &answer);
      if(answer<-1) printf("Ingresa un numero entero positivo\n");
      while(getchar() != '\n' && getchar() != EOF); 
    }while(answer<-1);
    
    intents+=1;
    
    if(answer==magicNumber){
      system("clear");
      printf("Correcto! Has ganado la partida en %d intentos\n", intents);
      playGame();
    }
    if(answer!=-1){
      // Condiciones si el número es diferente. Intentemos no hacer if anidados xd
      system("clear");
      printf("Whops! Incorrecto... el número es %s\n", answer>magicNumber?lower:higher);
    }else{
      system("clear");
      printf("Tan pronto? Solo has intentado %d veces!\n", intents);
      printf("El numero magico es: %d", magicNumber);
      return;
    }
  }while(answer != magicNumber && surrender == false);
}

int main(){
  //Para el contador
  time_t tini;
  tini = time(NULL);
  int endLoop = 1, answer;
  
  do{
    printf("Juego: Numero magico\n");
    printf("¿Quieres empezar a jugar?\n");
    printf("[1]Play/[0]Exit\n");

    scanf("%d", &answer);
    
    switch(answer){
    case 1:
      //calls game function
      playGame();
      break;

    case 0:
      endLoop = 0;
      break;

    default:
      printf("Wrong answer... try again\n");
      //Limpiamos el buffer de entrada si ingresa un carácter raro
      while(getchar() != '\n' && getchar() != EOF);
    }
   
  }while(endLoop!=0);

  session_time(tini);
  return 0;
}

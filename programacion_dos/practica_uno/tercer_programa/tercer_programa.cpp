#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void session_time(time_t tini){
  time_t tfin = time(NULL);
  
  printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
  printf("\n tiempo de salida %s", asctime(localtime(&tfin)));
  printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
}

int magicNumberGenerator(){
  srand(time(NULL));
  return rand() % (100 + 1);
}

void playGame(){
  printf("\033[2J\033[H");
  int magicNumber = magicNumberGenerator(), answer;
  bool surrender;
  
  do{
    /*TODO: 
      - set a counter for intents
      - set a subquestion for exit if cant doit
      - for each intent evaluate and told the player is mayor or lesser
      - if wins, gives another number until player stops game
     */
  }while(answer != magicNumber && surrender == false);
  printf("Magic number is: %d\n", magicNumber);
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

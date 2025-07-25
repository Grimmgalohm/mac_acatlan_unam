#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void session_time(time_t tini){
  time_t tfin = time(NULL);

  printf("Tiempo de inicio del programa:\n%s\n", asctime(localtime(&tini)));
  printf("Tiempo de salida:\n%s\n", asctime(localtime(&tfin)));
  printf("Tiempo de permanencia en el sistema: \n%.2f seg\n", difftime(tfin, tini));
}

void print_matrix(){
  int size,i,j;
  bool isPair = true;
  srand(time(NULL));
  //Pues... la lógica de las matrices.
  do{
    printf("De que tamaño será la matriz?\n");
    scanf("%d",&size);
    if((size%2)==0) isPair=false; system("clear");
    while(getchar()!='\n' && getchar()!= EOF);
  }while(isPair);

  for(i=0; i<size; i++){
    printf(" ");
    for(j=0; j<size; j++){
      if(i<j){
	printf("%d ", rand()%(9) );
      }else{
	printf("0 ");
      }
    }
    printf("\n");
  }
}

int main(){
  time_t tini;
  tini = time(NULL);
  int option;
  bool tflag = true;
  do{
    system("clear"); 
    printf("=== Matriz triangular ===\n");
    printf("[1] Crear una matriz triangular\n");
    printf("[0] Salir del programa\n");
    scanf("%d",&option);

    switch(option){
      case 0:
	tflag = false;
        break;
      case 1:
	print_matrix();
        break;
      default:
	printf("Opción inválida\n");
	system("clear");
    }
  
  }while(tflag); 
  session_time(tini);
  return 0;
}

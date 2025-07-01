 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 void session_time(time_t tini){
     time_t tfin = time(NULL);

     printf("\n tiempo de inicio: %s", asctime(localtime(&tini)));
     printf("\n tiempo de salida %s", asctime(localtime(&tfin)));
     printf("\n Tiempo de permanencia en el sistema %.2f seg", difftime(tfin, tini));
 }

 int generateMagicNumber(){
   //configurar la semilla para generar números aleatoriosi
   srand(time(NULL));
   //Crea el número con rango máximo de 100
   int magicNumber=rand()%101;
   system("cls");
   printf("Número mágico: %d", magicNumber);
   return magicNumber;
 }

 void game(){
   int magic_number = generateMagicNumber(), userAnswer;
   char tryAgain = "", greater[] = "greater", lower[] = "lower";
   
   do{
     printf("What is the magic number im thinking of?\n");
     scanf("%s",userAnswere);

     if((userAnswer>magic_number || userAnswer<magic_number)&&userAnswer!=magic_number){
       printf("Magic Number is %s\n", userAnswer>magic_number?greater:lower);
       userAnswer = "";
     }
     
   }while(magic_number != userAnswer || (tryAgain != "Y" || tryAgain != "y"));
   
 }

 int main(){
   //Para el contador
   time_t tini;
   tini = time(NULL);

   int lifePoints=3, answer, tryAgain, exit=1;
   do{
      printf(" --------------------------------- \n");
      printf("|        Magic Number Game        |\n");
      printf(" --------------------------------- \n");
      printf("Presiona 1 para jugar.\n");
      printf("Presiona 0 para salir del programa.\n");
      scanf("%d", &tryAgain);
      switch(tryAgain){
        case 1:
	  game();
	  break;
	  
        case 0:
	  return 0;
	  
        default:
	  exit = 1;
      }   
      printf("Quieres jugar otra vez? \n");
      scanf("%d", &tryAgain);
   }while(exit == 1);
   session_time(tini);
   return 0;
 }

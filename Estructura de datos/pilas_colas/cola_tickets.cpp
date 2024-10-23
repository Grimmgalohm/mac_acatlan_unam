#include <stdio.h>
#define MAX 5
int queue[MAX];
int front =-1, rear =-1;
void enqueue(int value){
	if(rear==MAX-1){
		printf("La cola esta llena\n");	
	}else{
		if(front==-1) front=0;
		rear++;
		queue[rear]=value;
		printf("Se ha enconlado el valor %d\n",value);	
	}
}
void dequeue(){
	if(front==-1 || front>rear){
		printf("La cola esta vacia \n");
	}else{
		printf("Se ha desenconlado el valor %d\n",queue[front]);
		front++;
	}
}
void peek(){
	if(front==-1 || front>rear){
		printf("La cola esta vacia \n");
	}else{
		printf("Se ha desenconlado el valor %d\n",queue[front]);
	}
}
void display(){
	if(front==-1 || front>rear){
		printf("La cola esta vacia \n");
	}else{
		printf("Ticket en espera: ");
		for (int i=front;i<=rear;i++){
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
}
int main(){
	int opcion, ticket=1;
	do{
		printf("Sitema de ticket \n");
		printf("1. Anadir al caarito\n");
		printf("2. Procesar ticket\n");
		printf("3. Mostrar tickets \n");
		printf("4. Salir \n");
		printf("Elije un opcion");
		fflush(stdin);
		scanf("%d",&opcion);
		switch (opcion){
			case 1: enqueue(ticket++); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: printf ("salir "); break;
			default: break;
		}
	}while (opcion!=4);
	
	return 0;
	}


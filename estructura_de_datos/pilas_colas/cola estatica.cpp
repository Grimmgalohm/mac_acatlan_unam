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
		printf("Cola: ");
		for (int i=front;i<=rear;i++){
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
}
int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	display();
	dequeue();
	dequeue();
	display();
	return 0;
}

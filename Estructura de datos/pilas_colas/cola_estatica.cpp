/*
	Clase 07/10/2024
*/

#include <stdio.h>
#define MAX 5

int enum[MAX]
int front =-1, rear = -1;

void enqueue(int value){
	if(rear == MAX -1){
		printf("LA cola esta llena\n");
	}else{
		if(front == MAX-1) front = 0;
			rear ++;
			queue[rear] = value;
			printf("Se ha encolado el valor %d\n", value);
	}
}

void dequeue(){
	if(front == -1 || front > rear){
		print("La cola está vacía\n");
	}else{
		printf("Se ha desencolado el valor %d\n", queue[front]);
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

#include <stdio.h>
#include <stdlib.h>
struct nodo{
	int data;
	struct nodo* next;
};
struct nodo* front = NULL;
struct nodo* rear = NULL;
void enqueue(int value){
	struct nodo* newnodo = (struct nodo*)malloc(sizeof (struct nodo));
	newnodo->data = value;
	newnodo->next = NULL;
	if(rear == NULL){
		front = rear = newnodo;
	}else{
		rear->next=newnodo;
		rear=newnodo;
	}
	printf("Se ha encolado el valor %d\n",value);
}

void dequeue(){
	if(front==NULL){
		printf("La cola esta vacia\n");
		return;
	}
	struct nodo* temp = front;
	printf("Se ha desencolado el valor %d\n", front->data);
	front = front->next;
	if(front == NULL){
		rear = NULL;
	}
	free(temp);
}

void display(){
	if(front == NULL){
		printf("LA cola esta vacia\n");
	}
	else{
		struct nodo* temp = front;
		printf("Cola:\n");
		while(temp != NULL){
			printf("%d\t", temp->data);
			temp = temp->next;
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 15

char pila[MAX], cola[MAX];
int front=-1, rear=-1, tope =-1;

void push(char c){
	if(tope == MAX-1){
		printf("Full\n");
		return;
	}
	pila[++tope]=c;
	printf("Done: %c\n", c);
}

void enqueue(char c){
	if(rear == MAX-1){
		printf("Full\n");
	}else{
		if(front == MAX-1) front = 0;
			cola[++rear] = c;
			front++;
			printf("Done: %c\n", c);
	}
}

char pop(){
	int j;
	if(tope == -1){
		return '\0';
	}
	return pila[tope--];
}

char dequeue(){
	int i;
	if(front == -1 || front > rear){
		printf("Empty\n");
	}else{
		i++;
		printf("%d\n", i);
		return cola[++i];
	}
}



int main(){
	char word[MAX];
	int i, j;

	scanf("%s", &word);
	
	for(i=0;i<strlen(word);i++){
		push(word[i]);
		enqueue(word[i]);
	}
	
	printf("%c", cola[0]);
	
	for(j=0;j<strlen(word); j++){
		//printf("%c\n", pop());
		printf("%c\n", dequeue());
	}
	
	return 0;
}


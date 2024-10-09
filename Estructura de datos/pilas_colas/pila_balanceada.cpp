/*
	Clase 04/10/24
	Balanceador de pila
*/

#include <stdio.h>
#include <string.h>

#define MAX 100
char pila[MAX];
int tope = -1;

//mete caracteres en la pila
void push(char c){
	if(tope == MAX-1){
		printf("La pila está llena\n");
		return;
	}
	pila[++tope]=c;
}

char pop(){
	if(tope == -1){
		return '\0';
	}
	return pila[tope--];
}

int coincidencia(char apertura, char cierre){
	if(apertura=='(' && cierre == ')') return 1;
	if(apertura=='{' && cierre == '}') return 1;
	if(apertura=='[' && cierre == ']') return 1;
	return 0;
}

int estabalanceada(char* expresion){
	int i;
	for(i = 0; i<strlen(expresion); i++){
		if(expresion[i] == '(' || expresion[i] == '{' || expresion[i] == '['){
			push(expresion[i]);
		}else if(expresion[i]==')' || expresion[i]=='}' || expresion[i]==']'){
			char apertura = pop();
			if(!coincidencia(apertura, expresion[i])){
				return 0;
			}
		}
	}
	return (tope == -1);
}

int main(){
	char expresion[MAX];
	printf("Ingresa una cadena a evaluar\n");
	scanf("%s", expresion);
	if(estabalanceada(expresion))
	{
		printf("La cadena esta balanceada");
	}else{
		printf("La cadena NO esta balanceada");
	}
	return 0;
}

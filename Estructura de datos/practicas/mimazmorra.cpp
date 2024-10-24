#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dungeon{
	int type;
	struct Dungeon* next;
	struct Dungeon* previous;
}Dungeon;

Dungeon* createDungeon(int type){
	Dungeon* newDungeon = (Dungeon*)malloc(sizeof(struct Dungeon));
	
	newDungeon->type = type;
	newDungeon->next = NULL;
	newDungeon->previous = NULL;
	
	return newDugeon;
}

void addDugeon(Dungeon** head, Dungeon** rear, int type){
	Dungeon* newDungeon = createDungeon(type);
	if(*inicio == NULL) {
		*head = *rear = newDungeon;
	}else{
		(*rear)->next = newDungeon;
		newDungeon->previous = *rear;
		*rear = newDungeon;
	}
}

void showDungeon(){
}

int main(){
}

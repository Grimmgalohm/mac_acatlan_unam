#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
	Batallas Pokémon :d
	
	1.- Calcular el daño: https://pokemon.fandom.com/es/wiki/Da%C3%B1o
	2.- Sistema de seleccion de pokemones para pelear (por parte del usuario)
		a.- 3 pokemones por contrincante
		b.- jugador CPU se elige al azar
		c.- las selecciones serán por entrada cruzada
	3.- Estadisticas base https://pokemon.fandom.com/es/wiki/Lista_de_Pok%C3%A9mon_con_sus_estad%C3%ADsticas_base (no tomaré todas)
	4.- https://www.wikidex.net/wiki/Lista_de_Pok%C3%A9mon_por_tipo
*/

typedef enum{
	FERALIGATR,
	GENGAR,
	GYARADOS,
	CHARIZARD,
	BULBASAUR,
	SUICUNE,
	RHYDON,
	ARIADOS,
	ENTEI,
	SCEPTILE,
	MAGIKARP,
	POKELIST_SIZE
}PokeNombre;

typedef enum{
	ACERO,
	AGUA,
	BICHO,
	DRAGON,
	ELECTRICO,
	FANTASMA,
	FUEGO,
	HADA,
	HIELO,
	LUCHA,
	NORMAL,
	PLANTA,
	PSIQUICO,
	ROCA,
	SINIESTRO,
	TIERRA,
	VENENO,
	VOLADOR,
	POKECLASE_SIZE
}PokeClase;

typedef struct Nodo{
	int id;
	int nivel;
	int ataqueBase;
	int ataqueEspecial;
	int defensa;
	int tipo;
	int vida;
	struct Nodo* siguiente;
	struct Nodo* anterior;
}Nodo;

const char* obtenerNombre(PokeNombre nombre){
	switch (nombre){
		case FERALIGATR: return "Feraligatr";
		case GENGAR: return "Gengar";
		case GYARADOS: return "Gyarados";
		case CHARIZARD: return "Charizard";
		case BULBASAUR: return "Bulbasaur";
		case SUICUNE: return "Suicune";
		case RHYDON: return "Rhydon";
		case ARIADOS: return "Ariados";
		case ENTEI: return "Entei";
		case SCEPTILE: return "Sceptile";
		case MAGIKARP: return "Magikarp";
		default: return "Desconocido";
	}
}

int random(){
    return 1 + rand() % (POKELIST_SIZE - 1 + 1);
}

void insertar(Nodo** cabeza, int id, int nivel, int ataqueBase, int ataqueEspecial, int defensa, int tipo){
	
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	
	if(nuevoNodo==NULL){
		printf("Error en la asignacion de memoria");
		return;
	}
	
	nuevoNodo->id = id;
	nuevoNodo->nivel = nivel;
	nuevoNodo->ataqueBase = ataqueBase;
	nuevoNodo->ataqueEspecial = ataqueEspecial;
	nuevoNodo->defensa = defensa;
	nuevoNodo->tipo = tipo;
	nuevoNodo->vida = 100;
	
	nuevoNodo->siguiente = *cabeza;
	nuevoNodo->anterior = NULL;
	
	if(*cabeza != NULL){
		(*cabeza)->anterior=nuevoNodo;
	}
	
	*cabeza = nuevoNodo;
}

int eliminar(Nodo** cabeza, int valor){
	Nodo* actual = *cabeza;
	
	//Buscar el nodo a eliminar
	while(actual!=NULL && actual->id != valor){
		actual = actual->siguiente;
	}
	
	//si no se encontró el nodo
	if(actual == NULL){
		printf("Pokemon no encontrado\n");
		return 0;
	}
	
	//si el nodo a eliminar es la cabeza
	if(actual == *cabeza){
		*cabeza = actual->siguiente;
	}
	
	//actualizar el nodo anterior
	if(actual->anterior != NULL){
		actual->anterior->siguiente = actual->siguiente;
	}
	
	//actualizar el nodo siguiente
	if(actual->siguiente != NULL){
		actual->siguiente->anterior = actual->anterior;
	}
	
	free(actual);
	printf("Pokemon %s tomado \n",obtenerNombre((PokeNombre)valor));
}

void imprimirTodos(Nodo* cabeza){
	Nodo* actual = cabeza;
	printf("");
	while(actual != NULL){
		printf("[%d] %s \n", actual->id, obtenerNombre((PokeNombre)actual->id));
		actual = actual->siguiente;
	}
	printf("");
}

void listaPokemon(Nodo** lista, int elemento){
	switch(elemento){
				//FERALIGATR
				case 0:
					insertar(lista,elemento,15,105,79,100,1);
					break;
				//GENGAR
				case 1:
					insertar(lista,elemento,15,65,130,60,5);
					break;
				//GYARADOS
				case 2:
					insertar(lista,elemento,15,125,60,79,1);
					break;
				//CHARIZARD
				case 3:
					insertar(lista,elemento,15,84,109,78,6);
					break;
				//BULBASAUR
				case 4:
					insertar(lista,elemento,15,49,65,49,11);
					break;
				//SUICUNE
				case 5:
					insertar(lista,elemento,15,75,90,115,1);
					break;
				//RHYDON
				case 6:
					insertar(lista,elemento,15,130,45,120,15);
					break;
				//ARIADOS
				case 7:
					insertar(lista,elemento,15,90,60,70,2);
					break;
				//ENTEI
				case 8:
					insertar(lista,elemento,15,115,90,85,6);
					break;
				//SCEPTILE
				case 9:
					insertar(lista,elemento,15,85,105,65,11);
					break;
				//MAGIKARP
				case 10:
					insertar(lista,elemento,15,10,15,65,1);
					break;
				default: printf("Opcion no valida\n"); break;
		}
}

void listarTeamCpu(Nodo* listaUser, Nodo** listaCPU){
	int i, elemento;
	//Llenar la pokelista
	while(i!=3){
		elemento = random();
		if(!eliminar(&listaUser, elemento)){
			i=i;
			continue;
		}else{
			listaPokemon(listaCPU, elemento);
			i++;
		}
	}
}

void seleccionarPokemones(Nodo** listaUser, Nodo** listaCPU){
	
	system("cls");
	Nodo* cabeza = NULL;
	int i, j=1, elemento;
	
	//Llenar la pokelista
	for(i=0; i<POKELIST_SIZE; i++){
		insertar(&cabeza,i,0,0,0,0,0);
	}
	
	while(j<4){
		imprimirTodos(cabeza);
		printf("\nSelecciona el Pokemon #%d de tu equipo\n", j);
		printf("(Recuerda que en el orden que los selecciones pelearan)\n");
		scanf("%d", &elemento);
		listaPokemon(listaUser, elemento);
		if(!eliminar(&cabeza, elemento)){
			eliminar(listaUser, elemento);
			j=j;
		}else{
			j++;
		}
	}
	listarTeamCpu(cabeza,listaCPU);
	system("cls");
}

int calcularDanioAtaque(int nivel, int ataqueBase, int defensaRival){
	float efectividad=0.5, bonus=1;
	int variable=random(), damage;
	damage = 0.01*ataqueBase*efectividad*variable*(((((0.2*nivel)+1)*ataqueBase)*(ataqueBase)/(25+defensaRival))+2)/100;
	floor(damage);
	return (int)damage;
}

void batalla(Nodo** listaUser, Nodo** listaCPU){
	int hit;
	system("cls");
	while((listaUser != NULL || listaCPU != NULL)){
		printf("%s vs %s \n\n", obtenerNombre((PokeNombre)(*listaUser)->id), obtenerNombre((PokeNombre)(*listaCPU)->id));
		
		do{
			
			printf("%s ataca a %s\n",obtenerNombre((PokeNombre)(*listaUser)->id), obtenerNombre((PokeNombre)(*listaCPU)->id));
			hit = calcularDanioAtaque((*listaUser)->nivel, (*listaUser)->ataqueBase, (*listaCPU)->defensa);
			printf("%s hace %d de daño a %s\n", obtenerNombre((PokeNombre)(*listaUser)->id),hit,obtenerNombre((PokeNombre)(*listaCPU)->id));
			(*listaCPU)->vida = ((*listaCPU)->vida)-hit;
			printf("Vida restante de %s: %d\n",obtenerNombre((PokeNombre)(*listaCPU)->id), (*listaCPU)->vida);
			
			printf("%s ataca a %s\n",obtenerNombre((PokeNombre)(*listaCPU)->id), obtenerNombre((PokeNombre)(*listaUser)->id));
			hit = calcularDanioAtaque((*listaCPU)->nivel, (*listaCPU)->ataqueBase, (*listaUser)->defensa);
			printf("%s hace %d de daño a %s\n", obtenerNombre((PokeNombre)(*listaCPU)->id),hit,obtenerNombre((PokeNombre)(*listaUser)->id));
			(*listaUser)->vida = ((*listaUser)->vida)-hit;
			printf("Vida restante de %s: %d\n",obtenerNombre((PokeNombre)(*listaUser)->id), (*listaUser)->vida);
			system("pause");
			break;
		}while( ((*listaUser)->vida>=0 && (*listaCPU)->vida >=0 ) );
		
		if((*listaUser)->vida==0){
			eliminar(listaUser, (*listaUser)->id);
		}else if((*listaCPU)->vida==0){
			eliminar(listaCPU, (*listaCPU)->id);
		}
	}
	
	if(listaUser !=NULL){
		printf("El ganador del duelo es usted y su pokemon: %s", obtenerNombre((PokeNombre)(*listaUser)->id));
	}else{
		printf("El ganador del duelo es CPU y su pokemon: %s", obtenerNombre((PokeNombre)(*listaCPU)->id));
	}
}

int main(){
	srand(time(0));
	Nodo* cabezaUser = NULL;
	Nodo* cabezaCPU = NULL;
	int opt, opt2;
	do{
		printf("Bienvenido al sistema de batallas Pokemon\n");
		printf("Quieres inciar un duelo?\n");
		printf("[1] Si, [0] No, salir\n");
		scanf("%d", &opt);
		if(opt==1){
			seleccionarPokemones(&cabezaUser, &cabezaCPU);
			printf("Es correcta la seleccion?\n");
			printf("[1] Si, [0] No, salir\n");
			scanf("%d", &opt2);
			switch(opt2){
				case 0:
					seleccionarPokemones(&cabezaUser, &cabezaCPU);
					break;
				default: batalla(&cabezaUser, &cabezaCPU);
					continue;
			}
		}
	}while(opt!=0);	
	
	return 0;
}


/*  Compilación: gcc -Wall -Wextra -o lista_enlazada lista_enlazada.c*/
  
/* Lee la entrada estándar y almacena los caracteres (incluidos espacio, saltos de línea, etc.) en una lista enlazada. */
/* Control-d es fin de datos */
/*  Probar bien desde teclado ./lista_enlazada  o bien con ./lista_enlazada   < lista_enlazada.c*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	char dato;
	struct nodo *enlace; //cada nodo apunta al nodo siguiente
} LISTA;

void mostrar_lista(LISTA *ptr);
void insertar(LISTA **ptr, char elemento);
// void borrar(); //para borrar entera la lista
//ojo! primero ver si esta vacia sino puede dar error un free(null)??
//borrar ult elto --> irte al penultimo (mediante dos punteros para una vez llegar al ultimo parar y borrar el ult elto -> free(ptr_penult->enlace) )
//borrar la lista entera le pones un free al puntero y ya

//insertar principio --> primero ver si vacia,
//pido un malloc para reservar hueco, y hago un puntero aux, meto el nuevo

int main()
{
	LISTA * n1 = NULL; //el puntero no apunta a nada
	char elemento; //introduzco caracter a caracter

	printf("\nIntroduzca uno o varios elementos. Para finalizar Control-d:\n");
	do
	{
		elemento = getchar(); //leo el caracter
		if(elemento != EOF)
			insertar(&n1, elemento); //lo inserto, como n1 es un puntero la direccion que paso es un doble puntero
	} while(elemento != EOF); //leo hasta que se devualva end of line

	/*
	
	
	*/

	printf("\nLa nueva lista enlazada es:\n");
	mostrar_lista(n1); //si n1 es null esta vacio, si distinto apunta al primero de la lista, que apunta al segundo... si apunta a null es ult nodo de la lista
/*Se debe liberar la memoria pedida, que queda como ejercicio*/ //borrar la lista
	return 0;
}

void mostrar_lista(LISTA *ptr) //le pasamos el puntero al primer elto de la lista
{	//recorro la lista
	while(ptr != NULL) //mientras que sea distinto de null 
	{
		printf("%c",ptr->dato); //muestro el dato, como es una estructura uso -> para dentro de ese puntero mostrar el dato
		ptr = ptr->enlace; //paso al siguiente nodo ptr es el siguiente enlace, recorro lista de primero a ult
	}
/*	printf("\n");*/
}

/* ejercicio : Insertar por el principio */
void insertar(LISTA **ptr, char elemento) //inserta al final el nuevo elto
{
	LISTA *p1, *p2;

	p1 = *ptr;

    // Si mi lista está vacía...
	if(p1 == NULL)
	{
        //Inserto un elemento (aqui es donde necesito un doble puntero)
		p1 = malloc(sizeof(LISTA)); //pido memoria dinamica, calloc(1, sizeof(LISTA));

		if (p1 != NULL){ //si la peticion de memoria se ha realizado con exito
			p1->dato = elemento; //asigno el elemento
			p1->enlace = NULL; //pongo q es ult elto
			*ptr = p1; // así la lista no está vacía
		}
	}else{

        //Tenemos que posicionarnos en el ultimo elemento de la tabla
		while(p1->enlace != NULL)
			p1 = p1->enlace;

		//una vez estamos en el ult elto
		p2 = malloc(sizeof(LISTA)); //pido espacio
		if(p2 != NULL)
		{
			p2->dato = elemento;// Ponemos el caracter
			p2->enlace = NULL; // Fin de lista, y por tanto null
			p1->enlace = p2; // Asigno mi puntero al p1
		}
	}
}
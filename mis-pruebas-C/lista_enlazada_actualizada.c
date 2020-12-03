/*  Compilación: gcc -Wall -Wextra -o lista_enlazada lista_enlazada.c*/
  
/* Lee la entrada estándar y almacena los caracteres (incluidos espacio, saltos de línea, etc.) en una lista enlazada. */
/* Control-d es fin de datos */
/*  Probar bien desde teclado ./lista_enlazada  o bien con ./lista_enlazada   < lista_enlazada.c*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	char dato;
	struct nodo *enlace;
} LISTA;

void mostrar_lista(LISTA *ptr);
void insertar(LISTA **ptr, char elemento);

int main()
{
	LISTA * n1 = NULL;
	char elemento;

	printf("\nIntroduzca uno o varios elementos. Para finalizar Control-d:\n");
	while( (elemento = getchar()) != EOF  ) insertar(&n1, elemento);
	printf("\nLa nueva lista enlazada es:\n");
	mostrar_lista(n1);
/*Se debe liberar la memoria pedida, que queda como ejercicio*/
	return 0;
}

void mostrar_lista(LISTA *ptr)
{
	while(ptr != NULL)
	{
		printf("%c",ptr->dato);
		ptr = ptr->enlace;
	}
/*	printf("\n");*/
}

void insertar(LISTA **ptr, char elemento)
{
	LISTA *p1, *p2;

	p1 = *ptr; //direccion de la lista
	if(p1 == NULL)
	{
		p1 = malloc(sizeof(LISTA));//y si usamos calloc ¿qué cambia?
		if (p1 != NULL)
		{
			p1->dato = elemento;
			p1->enlace = NULL;
			*ptr = p1;
		}
	}
	else
	{
		while(p1->enlace != NULL)//recorrer la lista hasta el último
			p1 = p1->enlace;
		p2 = malloc(sizeof(LISTA));//y si usamos calloc ¿qué cambia?
		if(p2 != NULL)
		{
			p2->dato = elemento;
			p2->enlace = NULL;
			p1->enlace = p2;
		}
	}
}
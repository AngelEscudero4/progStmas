/**************************************************************
* Se trata de construir una lista  de listas de números          *
* El primer arguumento que se pasa al programa da cuántas líneas *
* hay y los restantes el número de números de cada línea.       */

/*************** TAREAS *****************************************/

/* Completar las comprobaciones que son:
	Antes de usar alguno de los argumentos que se le van a pasar
al programa, es necesario saber si se le han pasado o no.
	Se debe mirar si cuando pedimos memoria dinámica, nos la concede.
	Cuando se explique la función strtol() se debe eliminar atoi() y
comprobar si los argumentos son números.                               */

/* Se debe liberar toda la memoria dinámica pedida     */

/* Cuando se expliquen los ficheros de ayuda para las prácticas
	auxiliar.h y auxiliar.c
usarlos o dar la salida de errores equivalente        */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int i, j, k, l; float **a;

	k = atoi(argv[1]);
	a = (float **) malloc(k * sizeof(float *));
	for(i = 0; i < k; i++)
	{
		l = atoi(argv[i+2]);
		a[i] = (float *) malloc(l * sizeof(float));
		for(j = 0; j < l; j++) *(a[i]+j) = 1.0 /(i+j+1.0);
	}
	for(i = 0; i < k; i++)
	{
		l = atoi(argv[i+2]);
		for(j = 0; j < l; j++) printf("%f ",*(a[i]+j) );
		printf("\n");
	}


	exit(0);
} 

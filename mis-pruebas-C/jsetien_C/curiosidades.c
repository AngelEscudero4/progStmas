/* Directivas de preprocesado. */
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

/* Posibles tareas para el alumno:
*  Definir si estamos o no estamos en una máquina como triqui (cambian los modificadores de printf)
*  Usar otros tipos como float, double etc
*  Combinar con modificadores de tipo como signed, unsigned, short, long
*  Cuando se definan arrays, struc o union también                */

int main(void)
{
	// Para jugar se puede mirar scanf
	/* Se puede usar unsigned o signed, para ver cambios, también modificadores a hexacedimal, etc.*/
	char a='A', b='5';
	int m,n, *p; unsigned int mu=5, nu=7;
	float x = 10.0, y = -1.0, z;
	
	/**** char como enteros *************/
	printf("%d+%d=%d\n",a,b,a+b);
	printf("%c+%c=%c\n",a,b,a+b);
	
	/******** operaciones no claras y/o hay que tener cuidado *********/
	printf("%u-%u=%u\n",mu,nu,mu-nu); // son números sin signo
	b=4*a; printf("b es %d y también b es %c\n",b,b); // a qué corresponde, encontrar el equivalente en int
	
	/******** tamaños de tipos ********/
	printf("Tipo char %lu bytes\n", sizeof(char));
	printf("Tipo int %lu bytes\n", sizeof(int));
	printf("Todos los punteros ocupan %lu bytes\n", sizeof(void *));
	/******* punteros y más *****************/
	printf("el lugar ocupado en la memoria de a es %p\n",&a);
	printf("el lugar ocupado en la memoria de b es %p\n",&b);
	printf("el lugar ocupado en la memoria de m es %p\n",&m);
	printf("el lugar ocupado en la memoria de n es %p\n",&n);
	printf("el lugar ocupado en la memoria de p es %p\n",&p);
	printf("el lugar ocupado en la memoria de mu es %p\n",&mu);
	printf("el lugar ocupado en la memoria de nu es %p\n",&nu);
	
	m = 6; p = &n;
	n = 5; printf("n = %d\t*p = %d\n",n,*p);
	*p += m; printf("n = %d\t*p = %d\n",n,*p);
	
	/******* el operador ternario **********/
	z = (x > y) ? x : y;
	printf("el máximo de x e y es %g\n",z);
	exit(EX_OK);
}


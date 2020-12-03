/* librería estándar de entrada salida */
#include <stdio.h>
/* para usar atoi, atof aunque es mejor usar strtod*/
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i, k;
	float j;		  // cambiar tipo a double
	unsigned char *p; //NO se puede poner *p='a' --> es como si apuntara a null
	p = (unsigned char *)&j;
	for (i = 1; i < argc; i++)
	{
		j = atof(argv[i]); // cambiar ato
		for (k = 0; k < sizeof(j); k++)
			printf(" %02x", p[k]); //x de hexadecimal, escribir numero en hexadecimal de dos cifras
		printf("\n");
	}

	//aritmetca de punteros
	printf("Aunq &j=%p y p =%p son iguales\n", &j, p);
	printf("se tiene &j+1=%p y p+1=%p NO son iguales\n", &j + 1, &p + 1);
	j = 7.0;
	p[1] = 8;
	printf("ahora j vale %f\n", j);

	exit(0);
}
/* ejercios:
   Cambiar tipos.
   Usar strtod para comprobar si los argumentos son numeros correctos y strings cualesquiera. --> man strol
   Hacer que al compilar no dé warnings
   Dependiendo de la arquitectura de la máquina, es mejor recorrer el for en el
otro sentido
   Quien quiera saber más, puede sacar los bits. Se deben mirar, entonces, las operaciones de bits & | ~ >> << ^
*/

/*char **c; c+5 es el valor de c+5sizeof(char *)*/
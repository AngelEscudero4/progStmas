/* Basado en C Pocket Reference  Editorial O'REILLY     */

/* Lee las primeras líneas de un fichero de texto y las muestra por la salida estándar *
*  Uso: leyendounfichero fichero                                                       */

#include <stdio.h>
#define LINEAS 20 /* Directivas de preprocesado.    */

void mostrar_pagina(FILE *); /* Prototipo de función */

int main(int argc, char *argv[])
{
	FILE *paf;
	int codigo_salida = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Uso: leyendounfichero nombredefichero\n");
		codigo_salida = 1;
	}
	else if ((paf = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error abriendo el fichero\n");
		codigo_salida = 2;
	}
	else
	{
		mostrar_pagina(paf);
		fclose(paf);
	}
	return codigo_salida;
}
void mostrar_pagina(FILE *paf)
{
	int cuenta = 0;
	char linea[81];

	while (cuenta < LINEAS && fgets(linea, 81, paf) != NULL)
	{
		fputs(linea, stdout);
		cuenta++;
	}
}

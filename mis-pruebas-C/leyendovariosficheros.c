/* Este programa lee varios ficheros (unas líneas) */
/* Los nombres están en la línea de comandos */

//EJERCICIOS 

//1) no imprimir inmediatamente, sino guardar una cantidad fija de lineas (100 con define) en un doble array y cuando acabe leer. mirar las funciones de string.h que permiten copiar cadenas(String)
//2) Hacerlo con memoria dinamica
#include <stdio.h> 
#include <stdlib.h>

#define LINEAS 10

void mostrar_pagina(FILE *); /* Prototipo de la funcion */

int main(int argc, char *argv[]){
    //Fichero
    FILE * paf;

    // Para recorrer cada uno de los ficheros que quiero leer 
    int k;

    // Si tenemos más argumentos quiere decir que hemos introducido un argumento correspondiente a un fichero
    if(argc > 1){

        for(k = 1; k < argc; k++){

            // Si lo ha podido abrir...
            if( (paf = fopen(argv[k], "r")) != NULL    ){
                mostrar_pagina(paf);
                fclose(paf);
            }else{ 

                //Envio un error por la salida de error estandar
                fprintf(stderr, "El fichero %s no se ha podido abrir\n", argv[k]);
            }
        }
    } else { /* leer la entrada estandar */
        mostrar_pagina(stdin);
    }


    exit(0);
}

void mostrar_pagina(FILE *paf) {
	int cuenta = 0;
	char linea[81];
	
	while(cuenta < LINEAS && fgets(linea,81,paf) != NULL ) 	{  //81=tamaño de la linea
		fputs(linea,stdout);
		cuenta++;
	}
}
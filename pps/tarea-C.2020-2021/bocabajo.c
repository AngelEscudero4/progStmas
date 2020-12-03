#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliar.h"

int main(int argc, char *argv[])
{
    argv0 = "bocabajo";

    //inicializo la pila
    NODO *pila = NULL;

    //variable en la que guardar la linea leida
    char *linea;

    //Si se le llama sin argumentos leo entrada estandar
    if (argc == 1)
    {
        //2049 para tamaño maximo de linea (2048) mas caracter fin de linea
        linea = (char *)malloc(2049);
        comprobarAsignacionMemoria(linea);
        //mientras que haya lineas que leer por la entrada estandar las meto en la pila
        while (fgets(linea, 2048, stdin) != NULL)
        {
            push(&pila, linea);
        }

        //libero el espacio utilizado para linea ya que no es necesario
        free(linea);
    }

    //Si solo le paso la ayuda ejecuto ayuda
    else if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        printf("bocabajo: Uso: [ fichero... ] \n");
        printf("bocabajo: Invierte el orden de las líneas de los ficheros (o de la entrada).\n");
        exit(0);
    }
    else
    {
        //Leo cada fichero recibido como argumento
        FILE *paf;
        int k;
        for (k = 1; k < argc; k++)
        {

            // Si lo ha podido abrir
            if ((paf = fopen(argv[k], "r")) != NULL)
            {
                //2049 para tamaño maximo de linea mas caracter fin de linea
                linea = (char *)malloc(2049);
                comprobarAsignacionMemoria(linea);
                //mientras que haya lineas que leer por la entrada estandar las meto en la pila
                while (fgets(linea, 2048, paf) != NULL)
                {
                    push(&pila, linea);
                }
                //cierro el fichero
                fclose(paf);
                //libero el espacio utilizado para linea ya que no es necesario
                free(linea);
            }
            else
            {
                //Envio un error por la salida de error estandar
                Error(EX_NOINPUT, "No existe el fichero: \"%s\"", argv[k]);
            }
        }
    }

    //mientras que la pila no este vacia muestro su dato y lo saco de la pila
    while (pila != NULL)
    {
        printf("%s", pila->dato);
        pop(&pila);
    }

    exit(0);
}

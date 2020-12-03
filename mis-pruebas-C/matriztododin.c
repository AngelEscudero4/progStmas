// Tercero NO sabiendo de antemano cuántas filas hay, pero la cantidad de números de cada fila va en los argumentos de la llamada */
/* El primer argumento (no el del nombre del programa) nos dice cuántas filas*/
/* Se realiza con memoria dinámica*/

// Se puede completar con pedir más filas con scanf y redimensionar matriz



#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[]) {


    long ** matriz; //
    long m ,n, aux, filas;

    //Compruebo si tengo el número de filas en la línea de comandos
    if(argc == 1){
        fprintf(stderr, "Se necesitan más argumentos\n");

        //Salgo con un num distinto de 0
        exit(2);
    }

    // Primero saco el numero de filas
    filas = atol(argv[1]);

    //Compruebo si tengo valores en el argumento de la linea de comandos
    if((argc - 2) != filas){
        fprintf(stderr, "No coincide el número de argumentos con el de filas\n");

        //Salgo con un num distinto de 0
        exit(1);
    }

    // Reservo memoria dinámica
    matriz = malloc(filas * sizeof(long *));

    for(m = 0; m < filas; m++){
        // Dejo que entre por teclado el valor
        aux = atol(argv[m + 2]);
        matriz[m] = (long *) malloc(aux * sizeof(long));

        for(n = 0; n < aux; n++){
            *(matriz[m] + n) = 10 * m + n;
        }
    }

    // Lo saco por pantalla

    for (m = 0; m < filas; m++) {

        aux = atol(argv[m+2]);

        for(n = 0; n < aux; n++){
            printf("%02ld\t", *(matriz[m]+ n));
        }
        free(matriz[m]);
        printf("\n");
    }

    free(matriz);

    exit(0);
}
/*Vamos a hacer de varias formas algo similar a 
12 34 56
13
1 2 3 4 5 6 
*/
//En cada linea puede haber varios numeros, no es una matriz rectangular
//Primero sabiendo de antemano cuantas filas tiene la matriz y la cantidad de numeros de cada fila
//el valor sera 10*fila+columna

//Segundo caso --> sabiendo de antemano cuantas filas hay pero la cantidad de nums de cada fila va en los de la llamada


//En este caso, 5 filas y cada una tiene numero de fila + 1 numeros
//Se realiza con memoria DINAMICA

//En todos se pedira saber que es *(*matriz+2)+3

//Se deberia usar strtol en vez e atol, mirar man strtol para saber si es un num

#include <stdio.h>
#include <stdlib.h>

#define FILAS 5

int main(int argc, char * argv[]){
    long * matriz[FILAS], m, n, aux; //creo una matriz cuadrada de tamaño FILASxFILAS

    //si vamos a usar atol vamos a comprobar primeramente que exista
    if (argc-1!=FILAS)
    {
        fprintf(stderr, "No coincide el numero de argumentos con el numero de filas\n");
        exit(1); //devolvemos que ha ocurrido un error (nº diferente de 0)
    }
    

    //primero calculo
    for (m = 0; m < FILAS; m++)
    {
        aux= atol(argv[m+1]);  //no comprueban si la cadena es realmente un numero
        matriz[m] = malloc(aux*sizeof(long)); // al puntero m le hago un hueco para meter aux numeros de tamaño long
        for (n = 0; n < aux; n++)
            *(matriz[m]+n)=10*m+n; //al valor del puntero le sumo n y asi calculo la posicion

        
    }

    //ahora saco por pantalla
    for (m = 0; m < FILAS; m++)
    {
        aux= atol(argv[m+1]);
        for (n = 0; n < aux; n++)
            printf("%02ld\t", *(matriz[m]+n));

        free(matriz[m]); //libero el espacio que habia reservado
        printf("\n");
    }
    exit(0);
    
}
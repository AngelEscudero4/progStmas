/*Vamos a hacer de varias formas algo similar a 
12 34 56
13
1 2 3 4 5 6 
*/
//En cada linea puede haber varios numeros, no es una matriz rectangular
//Primero sabiendo de antemano cuantas filas tiene la matriz y la cantidad de numeros de cada fila
//el valor sera 10*fila+columna

//En este caso, 5 filas y cada una tiene numero de fila + 1 numeros
//Se realiza con memoria estatica

//En todos se pedira saber que es *(*matriz+2)+3

#include <stdio.h>
#include <stdlib.h>

#define FILAS 5

int main(){
    long matriz[FILAS][FILAS], m, n; //creo una matriz cuadrada de tamaño FILASxFILAS

    //primero calculo
    for (m = 0; m < FILAS; m++)
    {
        for (n = 0; n <= m; n++)
        {
            matriz[m][n]=10*m+n;
        }
        
    }

    //ahora saco por pantalla
    for (m = 0; m < FILAS; m++)
    {
        for (n = 0; n <= m; n++)
        {
            printf("%02ld\t", matriz[m][n]); //02ld --> long entero con 2 cifras
        }
        printf("\n");
    }
    exit(0);
    
}
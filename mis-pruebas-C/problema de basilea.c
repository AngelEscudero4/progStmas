//Problema de Basilea
//La suma desde uno hasta infinito de 1/n^2
//sumar desde 1 a 100, el 100 se poner con #define
//escribir con 8 decimales


/*

#include <stdio.h>

#define MAX 100

int main(){

int i;
double res=0.0;

for(i=1; i<=MAX; i++){   //declarar el valor en el for, sino esta mal supuestamente
res+=1.0/(double) (i*i); //si no ponemos 1.0 haria division entre enteros --> 1/4=0
						 //(double) es hacer un CASTING, en este caso no seria necesario ya que ponemos 1.0
}

printf("La suma vale: %8f \n", res); //%8f --> 8 decimales

return 0;

}

*/

//sumar hasta un millon o que la diferencia entre dos sumas consecutivas sea menor que 1e-10

#include <stdio.h>
#include <math.h>

#define MAX 1000000

int main(void){

int i=1;
double suma=0.0;
double aux;

do{
	aux=suma;
	suma+=1.0/(double) (i*i);
	i++;
}while( /*fabs*/(suma-aux) >1e-10 && i<=MAX); //no seria necesario ya que suma-aux siempre va a ser positivo


printf("La suma vale: %8f \n", suma); //%8f --> 8 decimales

return 0;














}

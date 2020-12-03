// Funciones

/*
Prototipo:
valor_devuelto nombre(lista de tipos de argumentos);

Cuando se pone sin prototipo:
valor_devuelto nombre(lista de variables con tipos de argumentos){
}

*/

//funcion que suma dos valores x+y (tipo float) y devuelve el resultado

#include <stdio.h>

float suma(float, float);
void inter(float *, float *);

//variables globales --> visible hasta el final del fichero
float pi = 3.14;

int main()
{

    float x, y, z;

    x = 3.8;
    y = 4.3 + x;
    z = suma(x, 3 * y);

    printf("suma: z= %f \n", z);

    printf("x esta en la direccion %p\n", &x); //%p es para punteros

    inter(&x, &y);
    printf("intercambio: x= %f, y= %f \n", x, y);

    return 0;
}

float suma(float x, float y)
{
    return x + y;
}

void inter(float *x, float *y)
{

    float aux = *x; //aux es el valor de lo que apunta x
    *x = *y;        //el valor de lo que apunta x ahora es igual al valor de lo que apunta y
    *y = aux;
}

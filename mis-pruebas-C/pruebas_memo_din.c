//Pequeñas cosas con punteros y memoria dinamica

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int * i, * j; //declaro un puntero a un entero

    long *k;

    printf("i=%p \n",i);

    
    //conveniente poner el sizeof por si cambiamos de maquina se pueda seguir ejecutando
    i=malloc(sizeof(int)); //NO sabremos que va a haber en la dir de memoria que nos ha dado
    //guardo hueco para un int, si quiero para n ints --> n*sizeof(int)

    j=calloc(1, sizeof(int));  //lo que nos de estara todo a 0
    //guardo hueco para un int

    //faltan las comprobaciones de que nos ha dado la memoria pedida
    *i = 4; // que valga 4    
    printf("*i=%d\t*j=%d\n", *i,*j); // \t es tabulador

    k= calloc(100000000000, sizeof(long)); //muchisima memoria

    //al hacer esto podemos usar k[45] o lo que es lo mismo *(k+45)

    //ahora solo quiero 1000 posiciones
    k=realloc(k, 1000*sizeof(long)); //tiene que tener un puntero generado por un malloc o calloc
    //si ponemos i=j perdemos la direccion de memoria de la i y no podriamos usar lo que esta almacenado en la direccion de i --> agujeros de memoria


    free(i);
    free(j);
    free(k);

    exit(0);


}
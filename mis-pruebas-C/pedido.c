#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    FILE * paf;
    int k;

    //pongo k=1 para asi saltare el nombre del programa
    for(k=1; k<argc; k++){
        if( (paf=fopen(argv[k],"r") ) != NULL ){ //C asigna lo q devuelva a C y si es distinto de null --> verdadero
            char linea[1024];
            //leer lineas del fichero
            while(fgets(linea, 1024, paf)){
                printf("%s\n", linea);
            }


            //cerrar fichero
            fclose(paf);
        }
        else{
            //escribir mensaje por la salida de error
            fprintf(stderr, "el fichero %s no se ha podido abrir\n", argv[k]);
        }
    }

    exit(0);

}

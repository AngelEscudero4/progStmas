#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int k; FILE * paf; //paf apunta a la direccion 0

	paf = fopen("leyendo", "r"); //path, mode

	if(paf!=NULL){
		fclose(paf); //siempre que abramos ficheros luego hay que cerrarlo --> no puedo cerrarlo si no lo habia abierto
		printf("lo ha abierto \n");
	} 

	else{
		fprintf(stderr, "NO HA ABIERTO \n");
		exit(1);
	}

	exit(0);

}

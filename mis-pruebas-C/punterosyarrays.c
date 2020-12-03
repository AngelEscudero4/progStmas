/*ejemplo de arrays*/

#include <stdio.h>
#include <stdlib.h>

//argc es el num de argumentos en la llamada del programa, contando el propio programa!!
// *argv[] es un doble puntero
int main(int argc, char *argv[]){

	int j[5]; //reserva en memoria hueco para 5 enteros. Los valores pueden usarse cualquier valor --> puedes pisar memoria de otra cosa!!
	//puedo acceder a j[34] pero a saber que hay, imaginate que lo modifico...
	//empiezan en 0!!

	float x[3] = {1.3, 2.6, 3}; // solo lo puedo hacer asi en la declaracion

	char cadena[10]="Hola"; //Estoy declarando Hola+finDeCadena --> dejo el resto de parametros sin determinar

	double y[3][6][2]; // creacion de matriz

	// cadena[0] es 'H'
	//cadena[5] es 0 '\0'

	long m[2][3]={{1,2,43}, {4,6,7}};
	//igual que long m[2][3]={1,2,43, 4,6,7};

	//j, y, x, cadena, m son punteros constantes

	float z[3];

	//z==x pero pregunta si los punteros son iguales --> falso

	int * p; //declaro p como un puntero a un entero
	p=j; //asigno a la variable p la direccion donde esta almacenado j (p apunta a j --> j[0])

	//	OPERACIONES POSIBLES:
	//sumar puntero y entero dando un puntero del mismo tipo
	//restar punteros del mismo tipo
	//comparar punteros del mismo tipo

	p+=3; //avanzo 3 posiciones en esa direccion (apuntaria a j[3])

	*(p+3); //es lo mismo que p[3] que en este caso es j[3] --> +[j+3]

	printf("direccion de m es %p \n", m); //%p significa que imprima un puntero

	int k;

	for (k = 0; k < 5; k++)
	{
		j[k]=k;
	}
	k=0;
	for(p=j; p<j+5; p++){
		*p=k++;
	}

	printf("hay %d arguments \n", argc);
	for (k = 0; k < argc; k++)
	{
		printf("el argumento %d es %s \n", k, argv[k]); //%s para pasarle un String--> puntero al 1er char
		//IMPORTANTE %s --> imprime desde la direccion del puntero hasta final de cadena
		
	}

	char c[]="hola y adios"; //aqui si pone fin de cadena
	char d[10]={'h','o','l','a', '\0'}; //aqui no pone fin de cadena

	printf("%s\n", c); // lo mismo que fprintf(stdout, "%s\n", c)

	for(k=12; k<100; k++) c[k]='x';

	printf("%s\n", c); //he cambiado c, entonces es inesperado lo que pase luego ya que no habiamos reservado ese sitio

	exit(0);
	
	 









}

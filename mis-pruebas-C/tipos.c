
/*pequeñas cosas de C*/

#include <stdio.h>  /*hay que ponerlo siempre*/

void main(void)
{
  /*tipos básicos de C*/
  //Para comentarios de la linea, en comentarios poner tildes pero no en el resto del codigo
  
  // char int float double
  
  //modificadores singed usnigned long short y mas
  
  char a = 'A', b=5; //toma valores de -128 a 127
  //no es necesario los espacios, variables empezar por letra
  unsigned char c; //0 a 255 --> unsigned NUMS POSITIVOS
  int n=-4, m=7;
  unsigned int m4; // es lo mismo que poner solo unsigned
  
  printf("a y b en enteros son %d %d \n", a, b); // %d lo saca como enteros
  
  printf("a y b en enteros son %c %c \n", a, b); // %c lo saca como caracter
  
  printf("a + b en enteros son %d \n", a+b);
  
  printf("a + b en carácter son %c \n", a+b);
  
  printf("el tamaño de char es %d Bytes\n", sizeof(char)); //sizeof es una macro en la que devuelve tamaño de la variable o tipo que ponemos entre parentesis
  
  printf("el tamaño de int es %u Bytes\n", sizeof(m4)); //%u creo que es para sin signo
  
  a++;b++; //incrementa y lo guarda en variable (igual que en java)
  
  printf("a y b en enteros son %d %d \n", a, b); // %d lo saca como enteros
  
  ++a;++b; //primero incrementa y luego hace lo que le pida, guardando el valor
  
  printf("a y b en enteros son %d %d \n", a, b);
  
  // + - * / %
  //ojo / con enteros 2/5 = 0
  
  
  //  && || != !...
  
  a += 7; //a=a+7; --> a-=
  a*=3; // /= %=

}



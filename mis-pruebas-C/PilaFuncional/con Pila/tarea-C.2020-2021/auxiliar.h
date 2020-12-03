/*
** auxiliar.h
*/

#ifndef _AUXILIAR_H_
#define _AUXILIAR_H_

#include <sysexits.h>

extern char *argv0;

/*
 * Muestra por el estándar error un mensaje de error
 * con el formato adecuado, y termina llamando a exit().
 */
void Error(int exitval, char *fmt, ...);

/*
 * Intenta interpretar como double el texto de tira.
 * Devuelve: conseguido (1) o no (0).
 */
int Toma_Double(double *valor, char *tira);

/*
 * Intenta interpretar como long el texto de tira.
 * Devuelve: conseguido (1) o no (0).
 */
int Toma_Long(long *valor, char *tira);

/*
 * Estructura que representa un nodo o nodo en la pila.
 */
typedef struct nodo
{
    char *dato;
    struct nodo *next;
} NODO;

/*
 * Estructura para representar la pila --> sera un puntero al nodo cima
 */
typedef struct pila
{
    struct nodo *cima;
} PILA;

void crearPila(PILA *pila);
void push(PILA *p, char *linea);
void pop(PILA *p);
int estaVacia(PILA p);
void comprobarAsignacionMemoria(void *atrib);

#endif /* _AUXILIAR_H_ */

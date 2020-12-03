/*
 * Libreria de manejo de entrada y salida.
 */
#include <stdio.h>
/* 
 * Esta libreria nos permite solicitar pedazos de memoria al sistema operativo, que nos devolvera un la 
 * direcion de memoria en donde empieza el bloque. 
 */
#include <malloc.h>  

/*
 * Estructura que representa un nodo o elemento en la pila.
 */
struct elemento {
	int dato;
	struct elemento *next;
};

/*
 * Estructura para representar la pila.
 */
struct pila {
	struct elemento *frente;
	int tamano;
};

int crear(struct pila *);
int apilar(struct pila *, struct elemento);
int desapilar(struct pila *, struct elemento *);
int estaVacia(struct pila);


int main()
{
	struct pila mi_pila;
	struct elemento e1;
	struct elemento e2;
	struct elemento e3;

	
	crear(&mi_pila);

	e1.dato = 200;
	e2.dato = 100;
	e3.dato = 1;
	
	apilar(&mi_pila, e1);
	apilar(&mi_pila, e2);
	apilar(&mi_pila, e3);

	e1.dato = 10000;
	e2.dato = -45;
	e3.dato = 'A';

	struct elemento elemento_sacado;

	printf("mi cabeza es:%i\n", mi_pila.frente->dato);

	desapilar (&mi_pila, &elemento_sacado);

		printf("mi nueva cabeza es:%i\n", mi_pila.frente->dato);
		printf("mi elemento sacado es:%i\n", elemento_sacado.dato);

	
	return (0);
}

/*
 * Inicializamos la estructura de la pila, ponemos el valor de frente en NULL y el contador de objetos en 0
 */
int crear(struct pila *p) {
	p->frente = NULL;
	p->tamano = 0;
	return 1;
}

int apilar(struct pila *p, struct elemento elemento){
	/* Creamos un elemento nuevecito para meterlo en la pila
	 * y que el usuario no pudeda luego hacerle nada!
	 * Copiamos los datos del usuario en nuestro nuevo elemento.
	 */
	struct elemento *nuevo = (struct elemento *) malloc(sizeof(struct elemento));
	// Si por cualquier situacion el OS no puede asignarnos mas memoria la variable queda en NULL, si este
	// es el caso nosotros regresaremos un -1 indicando que la operacion fallo.
	if (nuevo == NULL) { return -1; }
	nuevo->dato = elemento.dato;
	nuevo->next = NULL;

	/* Ahora metemos ese nuevo elemento en la pila,
	 * ahora cualquier cambio que haga el usuario no nos afectara
	 * en nada
	 */
	
	nuevo->next = p->frente;
	p->frente = nuevo;
	p->tamano++;
	return 1;
}

int desapilar(struct pila *p, struct elemento *elemento){
	// si la pila esta vacia retornamos -1
	if (estaVacia(*p) ) { return -1; }
	// COPIAMOS el dato a retornar al usuario.
	elemento->dato = p->frente->dato;
	p->frente = p->frente->next;
	p->tamano--;
}

int estaVacia(struct pila p){
	if (p.tamano == 0) { return 1; }
	//if (p.frente == NULL) { return 1; }
	return 0;
}

int tamano(struct pila p){
	return p.tamano;
}
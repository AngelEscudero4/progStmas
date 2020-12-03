/* Definiendo y usando estructuras */

#include <stdio.h>
#include <stdlib.h>

struct
{
    char nombre[10];
    int unidades;
    float precio;
} articulo1, *articulo2;

articulo1.precio = 10.12;
(*articulo2).unidades = 4;

// Podiamos haberlo puesto como
articulo2->unidades = 4;

// Mejor forma de definirlo

struct Articulo
{
    char nombre[10];
    int unidades;
    float precio;
} articulo1, *articulo2; // el tipo es struct articulo

// Si ahora quiero definir un tercer artículo, solo tengo que:
struct Articulo articulo3 = {"manzana", 10, 23, 2};

// Para abreviar tipos
typedef unsigned char UCHAR;

// ESTA ES LA QUE MÁS LE GUSTA
typedef struct Articulo
{
    char nombre[10];
    int unidades;
    float precio;
} ARTICULO;

// Si quiero definir un punto, también lo puedo hacer como
typedef struct
{
    double x;
    double y;
} PUNTO;

PUNTO a = {1.2, 2.3}, origen = {0f, 0f};

// Estructuras dinámicas
struct nodo
{
    char dato;
    struct nodo *puntero;
}; // Estructura autoalusiva

// Mejor definido
typedef struct nodo
{
    char dato;
    struct nodo *puntero;
} NODO;

NODO primero = {'a', NULL};

/*
Ej 1- Dado un árbol binario que proviene de la transformación de un bosque de árboles de cadenas, 
verificar que todos los árboles tienen algún nodo cuya clave comience con consonante y
 haya tenido grado par (>0) en el árbol original
*/

#include <stdio.h>
#include <stdlib.h>

// Definición conceptual del tipo arbol (asumiendo la estructura típica de un nodo)
typedef struct nodo {
    char cadena[100]; // O el tipo de dato que uses para las cadenas/caracteres
    struct nodo* izq;
    struct nodo* der;
} Nodo;

typedef Nodo* arbol;

// Prototipos de las funciones para que compile en orden
int incisoA(arbol a);
int subArbolCumple(arbol a);
int nodoCumple(arbol a);


int incisoA(arbol a) {
    arbol aux;
    int cumple = 1;
    
    aux = a;
    while (aux != NULL && cumple) {
        if (!nodoCumple(aux)) {
            cumple = subArbolCumple(a->izq); 
        }
        aux = aux->der;
    }
    return cumple;
}


int subArbolCumple(arbol a) {
    if (a == NULL) {
        return 0;
    } else {
        if (!nodoCumple(a)) {
            return subArbolCumple(a->izq) || subArbolCumple(a->der);
        } else {
            return 1;
        }
    }
}


int nodoCumple(arbol a) {
    int grado = 0;
    arbol aux = a->izq;
    
    while (aux != NULL) {
        grado++;
        aux = aux->der;
    }
    
    return (grado != 0 && grado % 2 == 0 && a->cadena[0] != 'A' && a->cadena[0] != 'E' && a->cadena[0] != 'I' && a->cadena[0] != 'O' && a->cadena[0] != 'U'); 
}
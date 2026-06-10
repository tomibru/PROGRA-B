//Ej 1- Dado un árbol binario de cadenas, determinar el nivel en el que se encuentra la cadena más
//  larga menor a CAD (dato de entrada). Si hubiera más de una, considerar la primera encontrada.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 50

// Estructura del nodo del árbol
typedef struct nodoA {
    char cad[max];
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA* arbol;

// Prototipo de la función
void incisoA(arbol a, char cad[], int *lengMax, int n, int *nmax);


/* --- FUNCIÓN PRINCIPAL (MAIN) --- */
int main() {
    arbol a;
    int lengMax = 0, hmax = -1; // Usás hmax en la declaración pero nmax en la llamada
    char CAD[max];
    
    cargarArbol(a); 
    
    printf("Ingrese cad: ");
    scanf("%s", CAD);
    
    // Pasamos &hmax que cumple el rol del puntero al nivel máximo hallado
    incisoA(a, CAD, &lengMax, 0, &hmax);
    
    if (hmax != -1) {
        printf("Se encuentra en el nivel %d \n", hmax);
    } else {
        printf("Arbol vacio o no se encontro \n");
    }
    
    return 0;
}


/* --- DESARROLLO DEL INCISO A --- */
void incisoA(arbol a, char cad[], int *lengMax, int n, int *nmax) {
    int lenAct;
    
    if (a != NULL) {
        lenAct = strlen(a->cad);
        
        if (strcmp(a->cad,cad)<0 && lenAct > (*lengMax)) {
            (*lengMax) = lenAct;
            (*nmax) = n;
        }
        
        incisoA(a->izq, cad, lengMax, n + 1, nmax);
        incisoA(a->der, cad, lengMax, n + 1, nmax);
    }
}
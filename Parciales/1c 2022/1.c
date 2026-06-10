/*
Ej 1- Dado un árbol binario de enteros proveniente de la transformación de un árbol general, se pide obtener la suma de las claves con grado impar ubicadas en niveles menores a K (dato). El grado y el nivel se refieren a los del árbol original.
*/
/*
1)
- Arbol general
- Suma de claves con
    - grado % 2 != 0
    - n < K
*/
#include <stdio.h>
#include <stdlib.h>
 

int incisoA(arbol a, int n, int K){
    
    if (n >= K || a == NULL)
        return 0;
    else{
        if (gradoNodo(a) % 2 != 0)
            return a->clave + incisoA(a->izq, n + 1, K)+ incisoA(a->der, n, K);
        else
            return incisoA(a->izq, n + 1, K) + incisoA(a->der, n, K);
    }
}

int gradoNodo(arbol a){
    int grado = 0; arbol aux;
    
    aux = a->izq;
    while (aux != NULL){
        grado++;
        aux = aux->der;
    }
    return grado;
}

/* Invocacion: incisoA(a, 0, K); */
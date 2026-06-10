/* Ej 1- Dado un árbol binario de caracteres proveniente de la transformación de un bosque, 
verificar mediante una función entera, que alguno de los árboles del bosque tenía al menos 
un nodo en el nivel K (dato) con todos sus hijos ordenados ascendentemente.
- Definir tipos
- Mostrar la invocación de la solución desarrollada, dentro de un main completo que incluya 
declaraciones, inicializaciones, resultados obtenidos. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA{
    char c;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

int main(){
    arbol a;
    int K;
    
    cargarBosque(&a);
    scanf("%d", &K);
    if (cumple(a, K))
        printf("Arbol cumple");
    else
        printf("Arbol no cumple");
    return 0;
}

int nodoCumple(arbol a){
    int cumple=1;
    arbol aux; char ant, act;
    if (a->izq != NULL){
        ant = a->izq->c; aux = a->izq->der;
        while (aux != null && cumple){
            act = aux->c;
            cumple = (ant < act);
            ant = act;
            aux = aux->der;
        }
    }
    return cumple && a->izq != null;
}

int existe(arbol a, int K){
    arbol aux;
    int existeA = 0;
    aux = a;
    
    while (aux != null && !existeA){
        if (K == 0)
            existeA = nodoCumple(aux);
        else
            existeA = arbolCumple(aux->izq, 1, K);
        aux = aux->der;
    }
    return existeA;
}

int arbolCumple(arbol a, int n, int K){
    
    if (a == null || n > K)
        return 0;
    else
        if (n != K)
            return arbolCumple(a->izq, n + 1, K) ||
                   arbolCumple(a->der, n, K);
        else
            if (nodoCumple(a))
                return 1;
            else
                return arbolCumple(a->der, n, K);
}
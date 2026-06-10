/*
Ej 1- Dado un árbol binario de caracteres proveniente de la transformación de un árbol general, 
hallar e informar la cantidad de elementos no vocales que había en cada uno
 de los primeros K niveles (dato) [Considerar que K podría ser mayor a la profundidad del árbol
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA{
    char c;
    struct nodoA *izg, *der;
}nodoA;
typedef nodoA *arbol;


int main(){
    int K;
    arbol a;
    
    cargarArbol(&a);
     printf("ingrese K");
    scanf("%d",&K);
    printf("cantidad de no vocales: %d \n", contNV(a,0,K));
    
    return 0;
}


int contNV(arbol a, int n, int K){
    
    if (a == null || n > K)
        return 0;
    else
        return (a->c != 'a' && a->c != 'e' && a->c != 'i' && a->c != 'o' && a->c != 'u') +
        contNV(a->izg , n + 1, K) +
        contNV(a->der, n, K);
}
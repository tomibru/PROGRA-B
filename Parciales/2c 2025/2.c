/*
Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de números enteros (distintos de 0) se pide hallar mediante una función int la suma de las claves de los nodos no hoja que verifican que tienen grado par y la cantidad de hijos con claves positiva es igual a la cantidad de hijos con clave negativa.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct nodoNario* posicion;
typedef struct {
    posicion raiz;
} arbol;


// Prototipo de la función resolutiva
int incisoB(arbol a, posicion p);


/* --- PROGRAMA PRINCIPAL (MAIN) --- */
int main() {
    arbol a;
    posicion p;
    
    cargarArbol(&a, &p);
    
    printf("la suma es de %d \n", incisoB(a, p));
    
    return 0;
}


int incisoB(arbol a, posicion p) {
    posicion c;
    int contP = 0, contN = 0, gradoAct = 0, cont = 0;
    
    if (nulo(p)) {
        return 0;
    } else {
        c = HijoMasIzq(p, a);
        
        if (!nulo(c)) { // No es hoja
            while (!nulo(c)) {
                gradoAct++;
                
                if (Info(c, a) < 0) {
                    contN++;
                } else {
                    contP++;
                }
                
                cont += incisoB(a, c);
                c = HermanoDer(c, a);
            }
            
            if (gradoAct % 2 == 0 && contN == contP) {
                return cont + Info(p, a);
            } else {
                return cont;
            }
        }
        
        return incisoB(a, c);
    }
}
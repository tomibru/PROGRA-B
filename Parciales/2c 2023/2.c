//Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de caracteres, obtener el máximo y el mínimo grado de los nodos ubicados en el nivel K (dato).

#include <stdio.h>
#include <stdlib.h>

posicion hijoMasIzq(posicion p, arbolN a);
posicion hermanoDer(posicion p, arbolN a);
int nulo(posicion p);

void incisoB(arbolN a, posicion p, int *min, int *max, int K, int n) {
    posicion c;
    int grado = 0;
    
    if (!nulo(p) && n <= K) {
        c = hijoMasIzq(p, a);
        
        while (!nulo(c)) {
            if(n == K)
                grado++;
            else
                incisoB(a, c, min, max, K, n + 1);
             c = hermanoDer(c, a);

        }
        
        if (n == K) {
            if (grado > *max) {
                *max = grado;
            }
            if (grado < *min) {
                *min = grado;
            }
        }
    }
}
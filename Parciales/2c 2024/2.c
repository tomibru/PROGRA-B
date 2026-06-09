/*

Ej 2- (Utilizar TDA N-ario) Dado un árbol N-Ario de números naturales y un entero K retornar mediante una función int, la cantidad de nodos en niveles menores a K que verifican que su primer hijo es hoja y el resto de los hijos (si existen) son múltiplos del primero. (K dato)

*/



int incisoB(arbol a, posicion p, int n, int k) {

    int cont = 0, multiplo = -1, cumple = 1, hoja = 0;

    posicion c, primero;

    

    if (nulo(p) || n == k) {

        return 0;

    } else {

        c = primero = HijoMasIzq(p, a);

        if (!nulo(c)) {
            multiplo = Info(c, a);
            hoja = esHoja(c, a);
        }
        while (!nulo(c)) {
            if(c!= primero)
                cumple &= (Info(c, a) % multiplo == 0);
            cont += incisoB(a, c, n + 1, k);
            c = HermanoDer(c, a);         
        }
        return cont + (hoja && multiplo != 0 && cumple);

    }

}

int esHoja(posicion c, arbol a) {
    posicion h = HijoMasIzq(c, a);
    return nulo(h);
}
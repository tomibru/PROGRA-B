/*
Ej 1- Dado un árbol binario de enteros proveniente de la transformación de un bosque, calcular, mediante una o más funciones int la cantidad de árboles que tenían alguna clave negativa entre los niveles K1 y K2 (datos, K1 <= K2, no necesariamente los árboles tenían K1 o K2 niveles).
*/

int incisoA(arbol a, int K1, int K2){
    arbol aux = a;
    int cont = 0;
    int raizcumple = 0;
    
    while(aux != NULL){
        raizcumple =  (aux->dato < 0) && (K1==0);

        if(!raizcumple)
            cont += busquedaK(aux->izq, 1, K1, K2);
        else
            cont++;
        aux = aux->der;
    }
    return cont;
}

int busquedaK(arbol a, int n, int K1, int K2){
    
    if(a == NULL || n > K2)
        return 0;
    else
        if(n < K1)
            return busquedaK(a->izq, n+1, K1, K2) || busquedaK(a->der, n, K1, K2);
        else
            if(a->dato < 0)
                return 1;
            else
                return busquedaK(a->izq, n+1, K1, K2) || busquedaK(a->der, n, K1, K2);
}
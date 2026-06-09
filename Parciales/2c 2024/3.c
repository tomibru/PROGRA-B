/*
Ej 3- Dados dos digrafos G y G' con V=V' y aristas ponderadas, con |V|=N. G almacenado en
una matriz de adyacencia M y G' almacenado en una lista de adyacencia L. 
Se pide verificar si los vértices de G que no tienen bucles y tienen grado de entrada par 
verifican tener en G' grado de salida impar y bucle. El recorrido sobre M debe ser recursivo.
*/

int incisoC(int M[][max],lista V[],int n, int bucle, int gradoEn, int i, int j){
    
    if ( j < 0 )
        return 1;
    else{
        if(i >= 0 && !bucle)
            if(i == j)
                return incisoC(M, V,n, M[i][j]!=0, gradoEn, i-1, j);
            else{
                gradoEn += M[i][j] > 0;
                return incisoC(M, V, n,bucle, gradoEn, i-1, j);
            }
        else // i < 0
            if (gradoEn % 2 == 0 && !bucle)
                if( verificar( V, j) )
                    return incisoC(M, V,n, 0, 0, n-1, j-1);
                else
                    return 0;
            else
                return incisoC(M, V,n, 0, 0, n-1, j-1);
    }
}

int verificar(lista V[], int j){
    int bucle = 0, grados = 0;
    lista aux = V[j];
    
    while (aux != NULL){
        grados++;
        bucle =bucle || (j == aux->destino);
        aux = aux->sig;
    }
    return bucle && (grados % 2 != 0);
}
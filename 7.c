/*7. Desarrollar una función que obtenga el grado 
de un vértice (dato) de un grafo almacenado en: */


//a) una matriz de adyacencia
int incisoA(int M[][max],int v,int n){
    int i,grado=0;
    for(i=0;i<n;i++){
        if(M[v][i])
            grado++;
    }
    return grado;
}

//b) una lista de adyacencia
int incisoB(int V[],int v,int n){
    int i,grado;
    lista auxL;

    auxL= V[v].vertices;
    while (auxL != NULL){
        grado++;
        auxL=auxL->sig;
    }

    return grado;
}

//c) media matriz (triángulo superior)

int incisoC(int M[][max], int v, int n){    
    int i,grado=0;
    for(i=0;i<v;i++){
        grado+=M[i][v];
    }
    for(i=v;i<n;i++){
        grado+=M[v][i];
    }
    return grado;
}


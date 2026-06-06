/*6. Resolver el ejercicio anterior suponiendo que el digrafo está almacenado en una lista de 
adyacencia.*/

//a) su grado de entrada  
int GradoIn(V[],int n, int v){
    int i,grado=0;
    Lista auxl;
    for (i=0;i<n;i++){
        auxl= V[i].vertices;
        while(auxl != NULL){
            if(auxl->dato == v)
                grado++;
            auxl=auxl->sig;
        }
    }
    return grado;

}

//b) su grado de salida 
int GradoOut(V[],int n, int v){
    int grado=0;
    Lista auxl;
    auxl= V[v].vertices;
    while(auxl != NULL){
        grado++;
        auxl= auxl->sig;
    }

    return grado;

}

//c) el grado de dicho vértice

int Grado(V[], int n, int v) {
    return GradoIn(V, n, v) + GradoOut(V, n, v);
}
/*5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia, 
implementar funciones que devuelvan: 
a) su grado de entrada */

int GradoIn(int M[][max],int v,int n){
    int i,grado=0;
    for(i=0;i<n;i++)
        if(M[i][v])
            grado++;
    return grado;
}

//b) su grado de salida 

int GradoOut(int M[][max],int v,int n){
    int j,grado=0;
    for(j=0;j<n;j++)
        if(M[v][j])
            grado++;
    return grado;
}

//c) el grado de dicho vértice 
int Grado(int M[][max],int v,int n){
    int i,j,gradoIn=0, gradoOut=0;
    for(i=0;i<n;i++)
        if(i != v)
            if(M[i][v])
                gradoIn++;    
    for(j=0;j<n;j++)
        if(j != v)
            if(M[v][j])
                gradoOut++;
    return gradoIn + gradoOut;
}

preguntar

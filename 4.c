/*4. Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que 
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente.*/
void subyacente(unsigned int M[][],int n){
    int i,j;
    for (i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(M[i][j] == 1 && M[j][i] == 0)
                M[j][i]=1;
            else
            if(M[i][j] == 0 && M[j][i] == 1)
                M[i][j]=1;
        }
    }
}

/*MAS EFICIENTE*/   
void subyacente(unsigned int M[][],int n){
    int i,j;
    for (i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(M[i][j] || M[j][i])
                M[j][i]=M[i][j]=1;
        }
    }
}
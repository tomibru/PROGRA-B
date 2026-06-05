/*18. Para un digrafo dado, desarrollar un programa que 
genere la matriz de alcance R a partir de la 
matriz A resultante del algoritmo de Floyd.  */

//FLOYD
#define inf 999
void inicializarA(int M[][max],int A[][max],int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i==j)
                A[i][j]=0;
            else
                if(M[i][j] != 0)
                    A[i][j] = M[i][j];
                else
                    A[i][j] = inf;
}
void generarR(int A[][max], int R[][max], int n){
    int i,j;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(A[i][j] == inf)
                    R[i][j]=0;
                else
                    R[i][j]=1;
}

void floyd(int M[][max],int n,int A[][max], int R[][max]){
    int i,j,k;
    inicializarA(M,A,n);

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j]= A[i][k] + A[k][j];

    generarR(A,R,n);
}
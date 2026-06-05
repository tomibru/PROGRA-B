//KRUSKAL

int AB(int cc[], int n){
    int i=1,cumple=1;
    while(i<n && cumple)
        cumple = cc[i-1] == c[i];
    return cumple;
}

void minM(int M[][max],int Mady[][max], int n, int *fila,int *cola, int cc[]){
    int min=999,i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(M[i][j] == 0 && Mady[i][j] != 0 && Mady[i][j]< min && cc[i] != cc[j]){
                M[i][j] = M[j][i] =Mady[i][j];
                *fila= i;
                *cola= j;

                for(k=0;k<n;k++)
                    if(cc[k] == j)
                        cc[k] = cc[i];
            }
}

void kruskal(int M[][max], int n, int Mr[][max]){
    int cc[], componentes=0,vecMin, imin, jmin;

    incializarMr(Mr,n);
    incializarCC(cc,n);

    while(!AB(cc,n)){
        minM(Mr,M,n,&imin,&jmin,cc);
    }
}

//NOTAS: SE PUEDE EVITAR AB USANDO CONTADOR DE ARISTAS


//PRIM

void prim(int M[][max],int Mr[][max], int n,int u[]){
    int i,j,min,imin,jmin;

    //elijo el vértice 0 como punto de partida
    u[0]=1;

    for(i=0;i<n;i++){
        if(u[i]){
            min=999;
            for(j=0;j<n;j++){
                if(M[i][j]!=0 && M[i][j] < min && u[j]==0){
                    min=M[i][j];
                    imin= i;
                    jmin= j;
                }
            }
            u[jmin]=1;
            Mr[imin][jmin] = Mr[jmin][imin] = min;
        }   
    } 
}
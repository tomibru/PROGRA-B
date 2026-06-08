void kruskal(int usada[][max],int M[][max], int Mr[][max], int n ){    
    int cc[max], u, v, aristas=0,k, viejo, nuevo;
    incializarU(usada,n);
    incializarMr(Mr,n);
    inicializarCC(cc,n);

    while(aristas < n-1){
        aristaMin(usada,M,&u,&v,n);
        if(cc[u] != cc[v]){
            aristas++;
            Mr[u][v]= Mr[v][u] = M[u][v];
            viejo= cc[v];
            nuevo= cc[u];

            for(k=0; k<n, k++)
                if(cc[k] == viejo)
                    cc[k] = nuevo;
        }
    }
}

void aristaMin(int usada[][max],int M[][max], int *u, int *v,int n){
    int i,j,min=999;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(M[i][j] != 0 && !usada[i][j] && M[i][j] < min){
                min = M[i][j];
                *u=i;
                *v=j;
            }
        usada[*u][*v]=usada[*v][*u]=1;
}